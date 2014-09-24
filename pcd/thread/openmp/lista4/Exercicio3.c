#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define TAMANHO 6
#define MAX_THREADS 2

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
    int i;
    double produto_escalar = 0;

    srand(time(NULL));

    /* Aloca os vetores globais */
    A = (double*) malloc(sizeof(double)*TAMANHO);
    B = (double*) malloc(sizeof(double)*TAMANHO);

    /* Popula os vetores aleatoria e sequencialmente */
    for(i=0; i<TAMANHO; i++){
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    #pragma omp parallel private(i) reduction(+:produto_escalar)
    {
        #pragma omp for
            for(i=0; i<TAMANHO; i++)
                produto_escalar += A[i] * B[i];
    }

    printf("A:\n\t");
    imprime_vet(A, TAMANHO);
    printf("B:\n\t");
    imprime_vet(B, TAMANHO);
    printf("Produto Escalar: %.2lf\n", produto_escalar);

    return 0;
}
