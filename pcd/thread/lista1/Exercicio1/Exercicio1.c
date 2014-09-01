#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 2
#define TAMANHO 6.0 //10**8

/* Array global de dados */
double* dados;

/* Array global para retorno das threads */
double* results;

/* Funcao principal das threads */
void* FuncaoThread(void* arg){
    int id = (int) arg;
    int i, pos;
    double tamanho_parcial;
    double soma = 0;

    tamanho_parcial = TAMANHO/MAX_THREADS;

    printf("(Thread[%d]) Thread iniciada\n", id);

    /* Preenche o vetor de forma aleatoria e acumula o valor em soma*/
    for(i=0, pos=(tamanho_parcial*id);
        i<tamanho_parcial; i++, pos++){
        dados[pos] = rand_r(&id);
        soma += dados[pos];
    }

    id = (int) arg;

    /* Salva o resultado parcial */
    results[id] = soma;
}

int main(){
    int id;
    double soma, media;

    /* Alocacao dos dados globais */
    dados = (double*) malloc(sizeof(double)*TAMANHO);

    /* Alocacao dos resultados parciais */
    results = (double*) malloc(sizeof(double)*MAX_THREADS);

    /* Vetor para guardar referencias para as threads */
    pthread_t threads[MAX_THREADS];

    /* Dispara as threads */
    for(id=0; id<MAX_THREADS; id++){
        pthread_create(&threads[id], NULL, FuncaoThread, (void*) id);
    }

    /* Aguarda as threads finalizarem */
    for(id=0; id<MAX_THREADS; id++){
        pthread_join(threads[id], NULL);
    }

    /* Faz a conta da media final e apresenta */
    for(id=0; id<MAX_THREADS; id++){
        soma += results[id];
    }
    media = soma/TAMANHO;

    /*
    for(id=0; id<TAMANHO; id++)
        printf("%.2lf ", dados[id]);
    printf("\n");
    */

    printf("Media do vetor: %.3lf\n", media);

    /* Libera as variaveis globais */
    free(results);
    free(dados);

    return 0;
}
