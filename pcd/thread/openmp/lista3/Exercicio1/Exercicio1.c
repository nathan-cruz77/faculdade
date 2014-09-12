#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

#define TAMANHO 1000000 //10**6
#define MAX_THREADS 8

/* Vetor de dados */
double* dados;

int main(){
    int i;
    double media, result, aux;
    double somatorio, size;

    /* Semente para o random */
    srand(time(NULL));

    /* Aloca o vetor de dados */

    dados = (double*) malloc(sizeof(double)*TAMANHO);

    /* Preenchimento dos vetor de dados */
    for(i=0; i<TAMANHO; i++)
        dados[i] = rand();

    /* Calcula a media */
    somatorio = 0;
    omp_set_num_threads(MAX_THREADS);
    #pragma omp parallel shared(dados) private(i) reduction(+:somatorio)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++)
            somatorio += dados[i];
    }

    media = somatorio/TAMANHO;

    /* Calcula o somatorio mais externo */
    somatorio = 0;
    omp_set_num_threads(MAX_THREADS);
    #pragma omp parallel shared(dados) private(i) reduction(+:somatorio)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++)
            somatorio += pow(dados[i] - media, 2);
    }

    aux = TAMANHO-1;
    result = sqrt(somatorio/aux);

    printf("Desvio padrao = %lf\n", result);

    free(dados);

    return 0;
}
