#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 100000000

/* Vetor de dados */
double* dados;

int main(){
    int i;
    double somatorio, media;

    /* Aloca o vetor de dados */
    dados = (double*) malloc(sizeof(double)*TAMANHO);

    /* Preenchimento dos vetor de dados */
    #pragma omp parallel shared(dados) private(i)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++)
            dados[i] = rand_r(&i);
    }

    /* Calcula a media */
    somatorio = 0;
    #pragma omp parallel shared(dados) private(i) reduction(+:somatorio)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++)
            somatorio += dados[i];
    }

    media = somatorio/TAMANHO;

    printf("Media: %lf\n", media);

    return 0;
}
