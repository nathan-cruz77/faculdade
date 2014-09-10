#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define TAMANHO 10000

/* Matriz A */
double** A;

/* Vetor de coeficientes */
double* N;

/* Vetor resultado */
double* result;

/* Funcoes auxiliares */
void print_matrix(double** mat){
    int i, j;

    printf("\n");
    for(i=0; i<TAMANHO; i++){
        for(j=0; j<TAMANHO; j++){
            printf("%.2lf ", mat[i][j]);
        }
        printf("\n");
    }
}

void print_vector(double* vet){
    int i;

    printf("\n");
    for(i=0; i<TAMANHO; i++){
        printf("%.2lf\n", vet[i]);
    }
    printf("\n");
}

int main(){
    int i, j, aux;

    /* Aloca as estruturas de dados a serem usadas */
    N = (double*) malloc(sizeof(double)*TAMANHO);

    A = (double**) malloc(sizeof(double*)*TAMANHO);

    for(i=0; i<TAMANHO; i++){
        A[i] = (double*) malloc(sizeof(double)*TAMANHO);
    }

    result = (double*) malloc(sizeof(double)*TAMANHO);

    /* Popula concorrentemente todas as estruturas de dados */
    #pragma omp parallel private(i, j, aux) shared(A)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++){
            for(j=0; j<TAMANHO; j++){
                aux = omp_get_thread_num();
                A[i][j] = rand_r(&aux);
                aux++;
            }
        }

        #pragma omp for
        for(i=0; i<TAMANHO; i++){
            aux = omp_get_thread_num();
            N[i] = rand_r(&aux);
        }

        #pragma omp for
        for(i=0; i<TAMANHO; i++){
                result[i] = 0;
        }
    }

    /* Fazendo trabalho propriamente dito */
    #pragma omp parallel shared(A, N, result) private(i, j)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++){
            for(j=0; j<TAMANHO; j++){
                result[i] += N[j] * A[i][j];
            }
        }
    }

    /* Usado apenas para teste */
    //print_matrix(A);
    //print_vector(N);
    //printf("\n=\n");
    //print_vector(result);


    /* Liberando a memoria, concorrentemente */
    #pragma omp parallel private(i, j) shared(A)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++){
            free(A[i]);
        }
    }

    free(N);
    free(result);

    return 0;
}
