#include <stdio.h>
#include "mpi.h"

#define N 100000000
#define u 2.0

int main(int argc, char* argv[]) {
    double passo, soma, x, soma_escravo;
    double tempo;
    int i, rank, ini, fim, size;
    MPI_Status aux;



    /* A partir desta linha podemos fazer comunicacao
     * e/ou trabalho concorrente*/
    MPI_Init(&argc, &argv);

    /* Captura o tempo do sistema */
	if(rank == 0){
    	tempo = MPI_Wtime();
	}

    /* Detecta o rank do processo corrente e a quantidade total de processos */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    /* Calcula os indices que cada processo deve usar */
    ini = rank*(N/size);
    fim = ini + (N/size);

    passo = (u-1) / (double) N;
	soma = 0;
	soma_escravo = 0;

    for (i=ini; i<fim; i++) {
        x=1+i*passo;
        soma_escravo += 0.5*(1/x+1/(x+passo));
    }

	MPI_Reduce(&soma_escravo, &soma, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank == 0){
		tempo = MPI_Wtime() - tempo;
        printf("ln %f = %20.15f\n", u, passo*soma);
        printf("Tempo da computacao: %.3lfs\n", tempo);
    }

    MPI_Finalize();

    return 0;
}
