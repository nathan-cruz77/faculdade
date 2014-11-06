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
    double x, t, tempo;
    long int i, n, maxloc, ini, fim;
    int rank, size;

    /* Inicializa o MPI */
    MPI_Init(&argc, &argv);

    /* Detecta o rank do processo corrente e o total de processos */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    /* Claculando quantidade de pontos */
    n = (tam/dx)/size;

    ini = (n)*rank;
    fim = ini + (n);

    /* Alocando vetores */
    u = (double *) malloc((n + 1)*sizeof(double));
    u_prev = (double *) malloc((n + 3)*sizeof(double));

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

    t = 0.;
    while (t<T) {
        x = dx;
        for (i=1; i<n; i++) {
            u[i] = u_prev[i] + kappa*dt/(dx*dx)*(u_prev[i-1]-2*u_prev[i]+u_prev[i+1]);
            x += dx;
        }
        u[0] = u[n] = 0.; /* forca condicao de contorno */
        tmp = u_prev; u_prev = u; u = tmp; /* troca entre ponteiros */
        t += dt;
    }

    tempo = MPI_Wtime() - tempo;

    if(rank == 0){
        printf("Tempo do segundo laco: %.3lfs\n", tempo);
    }

    tempo = MPI_Wtime();
    /* Calculando o maior valor e sua localizacao */
    maxloc = 0;
    for (i=1; i<n+1; i++) {
        if (u[i] > u[maxloc]) maxloc = i;
    }

    tempo = MPI_Wtime() - tempo;

    if(rank == 0){
        printf("Tempo do terceiro laco: %.3lfs\n", tempo);
        printf("Maior valor u[%ld] = %g\n", maxloc, u[maxloc]);
    }

    MPI_Finalize();
}
