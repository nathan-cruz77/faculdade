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

    tempo = MPI_Wtime();

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
        /*printf("Inicio: qtde=%ld, dt=%g, dx=%g, dx²=%g, kappa=%f, const=%f\n",
                (n+2), dt, dx, dx*dx, kappa, kappa*dt/(dx*dx));
        printf("Iteracoes previstas: %g\n", T/dt);*/
    }

    /* Ajusta o valor inicial de x */
    if(rank != 0){
        x = rank * (n+1) * dx;
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
    if(rank == size -1){
        prox = MPI_PROC_NULL;
    }

    t = 0.;
    while (t<T) {

        /* Calcula o novo u */
        x = dx;
        for (i=1; i<n; i++) {
            u[i] = u_prev[i] + kappa*dt/(dx*dx)*(u_prev[i-1]-2*u_prev[i]+u_prev[i+1]);
            if(u[i] >= 100) printf("%g\n", u[i]);
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
            u_prev[0] = 0.;
        }
        else if(rank == size-1){
            u[n] = 0.;
            u_prev[n] = 0.;
        }

        /* Copia tudo de u para u_prev */
        u[0] = u_prev[0];
        u[n] = u_prev[n];

        tmp = u_prev; u_prev = u; u = tmp; /* troca entre ponteiros */

        t += dt;
    }

    /* Calculando o maior valor e sua localizacao */
    maxloc = 1;
    for (i=1; i<n; i++) {
        if (u[i] > u[maxloc]){
            maxloc = i;
        }
    }

    maxval = u[maxloc];
    maxloc = (rank * (n+1)) + maxloc;

    /*printf("\nProcesso: %d\n\tmaxloc: %d\n\tmaxval: %g\n",
           rank, maxloc, maxval);*/

    if(rank != 0){
        MPI_Send(&maxval, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
        MPI_Send(&maxloc, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD);
    }
    else{
        long int* indices = (long int*) malloc(size*sizeof(long int));
        double* valores = (double*) malloc(size*sizeof(double));

        valores[0] = maxval;
        indices[0] = maxloc;

        for(i=1; i<size; i++){
            MPI_Recv(&valores[0], 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD,
                     &status);
            MPI_Recv(&indices[i], 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD,
                     &status);
        }

        /*for(i=0; i<size; i++){
            printf("proc %d: u[%ld] = %lf\n", i, indices[i], valores[i]);
        }*/

        maxval_global = valores[0];
        maxloc_global = indices[0];
        for(i=1; i<size; i++){
            if(valores[i] > maxval_global){
                maxval_global = valores[i];
                maxloc_global = indices[i];
            }
        }

        tempo = MPI_Wtime() - tempo;
        printf("Tempo total: %.3lfs\n", tempo);
        printf("Maior valor u[%ld] = %g\n", maxloc_global, maxval_global);
    }

    MPI_Finalize();
}
