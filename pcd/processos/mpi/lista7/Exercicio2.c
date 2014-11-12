#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define tam 1.0
#define dx 0.00001
#define dt 0.000001
#define T    0.01
#define kappa 0.000045

void main(int argc, char* argv[]) {

    double *tmp, *u, *u_prev;
    double x, t, tempo, maxval, maxval_global;
    long int i, n, maxloc, ini, fim, maxloc_global;
    int rank, size, prox, ant;
	MPI_Status status;

    /* Inicializa o MPI */
    MPI_Init(&argc, &argv);

	if(rank == 0){
		tempo = MPI_Wtime();
	}

    /* Detecta o rank do processo corrente e o total de processos */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    /* Claculando quantidade de pontos */
    n = (tam/dx)/size;

    /* Alocando vetores */
    u = (double *) malloc((n + 1)*sizeof(double));
    u_prev = (double *) malloc((n + 1)*sizeof(double));

    /* Apenas o processo mestre imprime */
    if(rank == 0){
        printf("Inicio: qtde=%ld, dt=%g, dx=%g, dx²=%g, kappa=%f, const=%f\n",
	            (n+2), dt, dx, dx*dx, kappa, kappa*dt/(dx*dx));
        printf("Iteracoes previstas: %g\n", T/dt);
    }

    /* Ajusta o valor inicial de x */
    if(rank != 0){
        x = rank * (n) * dx;
    }
    else{
        x = dx;
    }

    /* Cada um preenche seu pedaco de u_prev */
    for (i=1; i<n; i++) {
        if(x<=0.5){
            u_prev[i] = 200*x;
        }
        else{
            u_prev[i] = 200*(1.-x);
        }
        x += dx;
    }

	/* Calcula os processos com os quais interagir */
	prox = rank + 1;
	ant = rank - 1;

	/* Ajusta o proximo do ultimo e o anterior do primeiro */
	if(rank == 0){
		ant = MPI_PROC_NULL;
	}
	else if(rank == size -1){
		prox = MPI_PROC_NULL;
	}

    t = 0.;
    while (t<T) {

		/* Calcula o novo u */
        x = dx;
        for (i=1; i<n; i++) {
            u[i] = u_prev[i] + kappa*dt/(dx*dx)*(u_prev[i-1]-2*u_prev[i]+u_prev[i+1]);
            x += dx;
        }
		
		/* Envia para o proximo e recebe do anterior */
		MPI_Sendrecv(&u[n-1], 1, MPI_DOUBLE, prox, 0,
					 &u_prev[0], 1, MPI_DOUBLE, ant, MPI_ANY_TAG,
					 MPI_COMM_WORLD, &status);

		/* Envia para o anterior e recebe do proximo */
		MPI_Sendrecv(&u[1], 1, MPI_DOUBLE, ant, 0,
					 &u_prev[n], 1, MPI_DOUBLE, prox, MPI_ANY_TAG,
					 MPI_COMM_WORLD, &status);
	
		/* Forca condicao de contorno */
		if(rank == 0){
        	u[0] = 0.;
		}
		else if(rank == size-1){
			u[n] = 0.;
		}

		/* Copia tudo de u para u_prev */
		for(i=1; i<n; i++){
			u_prev[i] = u[i];
		}
        t += dt;
    }

    /* Calculando o maior valor e sua localizacao */
    maxloc = 0;
    for (i=1; i<n+1; i++) {
        if (u[i] > u[maxloc]) maxloc = i;
    }

	maxval = u[maxloc];
	maxloc = (rank * (n+1)) + maxloc;

	if(rank != 0){
		double* data = (double*) malloc(2*sizeof(double));
		MPI_Send(data, 2, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}
	else{

		double** data = (double**) malloc(size*sizeof(double*));
		for(i=0; i<size; i++){
			data[i] = (double*) malloc(2*sizeof(double));
		}

		data[0][0] = maxval;
		data[0][1] = maxloc;

		for(i=1; i<size; i++){
			MPI_Recv(data[i], 2, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG,
					 MPI_COMM_WORLD, &status);
		}

		maxval_global = maxval;
		maxloc_global = maxloc;
		for(i=0; i<size; i++){
			if(data[i][0] > maxval_global){
				maxval_global = data[i][0];
				maxloc_global = data[i][i];
			}
		}
	}

    if(rank == 0){
    	tempo = MPI_Wtime() - tempo;
        printf("Tempo total: %.3lfs\n", tempo);
        printf("Maior valor u[%ld] = %g\n", maxloc_global, maxval_global);
    }

    MPI_Finalize();
}
