#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

#define TAMANHO 100000000 //10**8
#define MAX_THREADS 4

/* Vetor de dados */
double* dados;

int main(){
    int i;
    double media, result, aux;
    double somatorio, size, tempo;

    /* Semente para o random */
    srand(time(NULL));

    /* Aloca o vetor de dados */

    dados = (double*) malloc(sizeof(double)*TAMANHO);

    /* Preenchimento dos vetor de dados */
    tempo = omp_get_wtime();
    for(i=0; i<TAMANHO; i++)
        dados[i] = i+1;
    tempo = omp_get_wtime() - tempo;

    printf("Tempo de preenchimento: %.3lfs\n", tempo);

    /* Calcula a media */
    tempo = omp_get_wtime();
    somatorio = 0;
    omp_set_num_threads(MAX_THREADS);
    #pragma omp parallel shared(dados, media, somatorio) private(i)
    {
        #pragma omp for
        for(i=0; i<TAMANHO; i++)
            #pragma omp critical
            somatorio += dados[i];

        //#pragma omp barrier

        #pragma omp single
        {
            media = somatorio/TAMANHO;
            somatorio = 0;
        }

        //#pragma omp barrier

        #pragma omp for
        for(i=0; i<TAMANHO; i++)
            #pragma omp critical
            somatorio += pow(dados[i] - media, 2);
    }
    tempo = omp_get_wtime() - tempo;
    printf("Tempo de calculo do desvio padrao: %.3lfs\n", tempo);

    result = sqrt(somatorio/(TAMANHO-1));

    printf("\nDesvio padrao = %lf\n", result);

    free(dados);

    return 0;
}
