#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#include <stdbool.h>

#define TAMANHO 10; //10**7

/* Vetor de dados */
double* dados;

int main(){
    int i;
    double media, result, aux;
    double somatorio, size;

    /* Semente para o random */
    srand(time(NULL));

    /* Aloca o vetor de dados */
    size = sizeof(double)*TAMANHO;
    dados = (double*) malloc(size);


    /* Preenchimento dos vetor de dados */
    #pragma omp parallel shared(dados) private(i)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++)
            dados[i] = i+1;//rand();
    }

    /* Calcula a media */
    somatorio = 0;
    #pragma omp parallel shared(dados) private(i) reduction(+:somatorio)
    {
        #pragma omp for
        for(i=0, i<TAMANHO; i++)
            somatorio += dados[i];
    }

    media = somatorio/TAMANHO;

    /* Calcula o somatorio mais externo */
    somatorio = 0;
    #pragma omp parallel shared(dados) private(i) reduction(+:somatorio)
    {
        #pragma omp for
        for(i=0, i<TAMANHO; i++)
            somatorio += pow(dados[i] - media, 2);
    }

    aux = TAMANHO-1;
    result = sqrt(somatorio/aux);

    printf("Desvio padrao = %lf\n", result);

    free(dados);

    return 0;
}
