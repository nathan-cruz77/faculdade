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
    tempo = MPI_Wtime();

    /* Detecta o rank do processo corrente e a quantidade total de processos */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    /* Calcula os indices que cada processo deve usar */
    ini = rank*(N/size);
    fim = ini + (N/size);

    passo = (u-1) / (double) N;

    for (i=ini; i<fim; i++) {
        x=1+i*passo;
        soma += 0.5*(1/x+1/(x+passo));
    }

    /* Se estivermos no processo mestre, aguardamos o resultado da computacao
     * de todos os escravos e geramos o resultado final */
    if(rank == 0){

        /* Recebemos o resultado de todos */
        for(i=0; i<size-1; i++){
            MPI_Recv(&soma_escravo, 1, MPI_DOUBLE, MPI_ANY_SOURCE,
                     MPI_ANY_TAG, MPI_COMM_WORLD, &aux);

            /* Verificar a possibilidade de fazer reducao */
            soma += soma_escravo;
        }
        tempo = MPI_Wtime() - tempo;

        printf("ln %f = %20.15f\n", u, passo*soma);
        printf("Tempo da computacao: %.3lfs\n", tempo);
    }

    /* Se estivermos num processo escravo enviamos o resultado parcial para
     * o mestre */
    else{
        MPI_Send(&soma, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
