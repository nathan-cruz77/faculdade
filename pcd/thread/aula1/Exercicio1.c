#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 8
#define TAMANHO 100000000 //10**8

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
    printf("(Thread[%d]) Tamanho parcial = %.0lf\n", id, tamanho_parcial);

    /* Preenche o vetor de forma aleatoria e acumula o valor em soma*/
    for(i=0, pos=(tamanho_parcial*id);
        i<tamanho_parcial; i++, pos++){
        dados[pos] = rand_r(&id);
        soma += dados[pos];
    }

    id = (int) arg;
    printf("(Thread[%d]) Vetor preenchido com sucesso\n", id);

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

    printf("Threads disparadas\n");

    /* Aguarda as threads finalizarem */
    for(id=0; id<MAX_THREADS; id++){
        pthread_join(threads[id], NULL);
    }

    printf("Threads finalizadas\n");

    /* Faz a conta da media final e apresenta */
    for(id=0; id<MAX_THREADS; id++){
        soma += results[id];
    }
    media = soma/TAMANHO;
    printf("Media do vetor: %.3lf\n", media);

    /* Libera as variaveis globais */
    free(results);
    free(dados);

    return 0;
}
