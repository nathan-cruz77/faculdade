#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#include <stdbool.h>

#define TAMANHO 10000000; //10**7

/* Vetor de dados */
double* dados;

int main(){
    int i;
    double media, result, aux;
    double somatorio, size;
    bool controle=true;

    /* Semente para o random */
    srand(time(NULL));

    /* Aloca o vetor de dados */
    size = sizeof(double)*TAMANHO;
    dados = (double*) malloc(size);


    /* Preenchimento dos vetor de dados */
    #pragma omp parallel firstprivate(controle)
    {
        #pragma omp for
        for(i=0; (i<TAMANHO); i++){
            controle = i<TAMANHO;
            dados[i] = rand();
        }
    }

    /* Calcula a media */
    somatorio = 0;
    #pragma omp parallel firstprivate(controle) reduction(+:somatorio)
    {
        #pragma omp for
        for(i=0, controle=true; controle; i++){
            controle = i<TAMANHO;
            somatorio += dados[i];
        }
    }

    media = somatorio/TAMANHO;

    /* Calcula o somatorio mais externo */
    somatorio = 0;
    #pragma omp parallel firstprivate(controle) reduction(+:somatorio)
    {
        #pragma omp for
        for(i=0, controle=true; controle; i++){
            controle = i<TAMANHO;
            somatorio += pow(dados[i] - media, 2);
        }
    }

    aux = TAMANHO-1;
    result = sqrt(somatorio/aux);

    printf("Desvio padrao = %lf\n", result);

    free(dados);

    return 0;
}
