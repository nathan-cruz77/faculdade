#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define TAMANHO 100000000
#define MAX_THREADS 4

/* Vetores a serem usados */
double* A;
double* B;

/* Funcao auxiliar */
void imprime_vet(double* A, int n){
    int i;

    for(i=0; i<n; i++){
        printf("%.0lf ", A[i]);
    }
    printf("\n");
}

int main(){
    int i, aux;
    double produto_escalar;
    double tempo = omp_get_wtime();

    srand(time(NULL));

    /* Aloca os vetores globais */
    A = (double*) malloc(sizeof(double)*TAMANHO);
    B = (double*) malloc(sizeof(double)*TAMANHO);

    /* Popula os vetores aleatoria e sequencialmente */
    for(i=0; i<TAMANHO; i++){
        A[i] = rand();
        B[i] = rand();
    }

    printf("%.3lfs\n", omp_get_wtime() - tempo);

    tempo = omp_get_wtime();
    produto_escalar = 0;
    omp_set_num_threads(MAX_THREADS);
    #pragma omp parallel private(i) shared(A, B) reduction(+: produto_escalar)
    {
        #pragma omp for
            for(i=0; i<TAMANHO; i++)
                produto_escalar += A[i] * B[i];
    }

    printf("%.3lfs\n", omp_get_wtime() - tempo);

/*
    printf("A:\n\t");
    imprime_vet(A, TAMANHO);
    printf("B:\n\t");
    imprime_vet(B, TAMANHO);
    printf("Produto Escalar: %.2lf\n", produto_escalar);
*/

    return 0;
}
