#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <math.h>

#define MAX_THREADS 8
#define TAMANHO 100000000.0 //10**8

typedef struct{
    int id;
    double media;
} TInfo;
typedef TInfo* PInfo;

/* Vetor de estruturas a serem passadas como argumento */
PInfo info;

/* Array global de dados */
double* dados;

/* Array global para retorno das threads */
double* results;

/* Funcao principal das threads para fazer a soma */
void* FuncaoThreadMedia(void* arg){
    int id = (int) arg;
    int i, pos;
    double tamanho_parcial;
    double soma = 0;

    tamanho_parcial = TAMANHO/MAX_THREADS;

    printf("(Thread[%d]) Thread iniciada\n", id);

    /* Acumula o v em soma*/
    for(i=0, pos=(tamanho_parcial*id); i<tamanho_parcial; i++, pos++){
        soma += dados[pos];
    }

    id = (int) arg;

    /* Salva o resultado parcial */
    results[id] = soma;

    printf("(Thread[%d]) finalizada com sucesso\n", id);
}

/* Funcao principal das threads para fazer a soma do desvio */
void* FuncaoThreadDesvio(void* arg){
    PInfo info = (PInfo) arg;
    int i, pos;
    double soma, tamanho_parcial;

    tamanho_parcial = TAMANHO/MAX_THREADS;
    soma = 0;

    printf("(Thread[%d]) Thread iniciada\n", info->id);

    /* Faz a conta em si */
    for(i=0, pos=tamanho_parcial*(info->id); i<tamanho_parcial; i++, pos++){
        soma += pow(dados[pos] - (info->media), 2);
    }

    /* Salva o resultado parcial */
    results[info->id] = soma;

    printf("(Thread[%d]) finalizada com sucesso\n", info->id);

}

int main(){
    int id;
    double soma, media, final_result;
    clock_t tempo;
    srand(time(NULL));

    /* Aloca o vetor de argumentos */
    info = (PInfo) malloc(sizeof(TInfo)*MAX_THREADS);

    /* Alocacao dos dados globais */
    tempo = clock();
    dados = (double*) malloc(sizeof(double)*TAMANHO);
    printf("Tempo de alocacao: %.2lf\n", tempo - clock());

    /* Alocacao dos resultados parciais */
    results = (double*) malloc(sizeof(double)*MAX_THREADS);

    /* Vetor para guardar referencias para as threads */
    pthread_t threads[MAX_THREADS];

    /* Preenche o vetor de dados aleatoriamente */
    tempo = clock();
    for(id=0; id<TAMANHO; id++){
        dados[id] = rand();
    }
    printf("Tempo de preenchimendo: %.2lf\n", tempo - clock());

    /* Dispara as threads para calculo da media */
    for(id=0; id<MAX_THREADS; id++){
        pthread_create(&threads[id], NULL, FuncaoThreadMedia, (void*) id);
    }

    printf("Threads disparadas[1]\n");

    /* Aguarda as threads finalizarem */
    for(id=0; id<MAX_THREADS; id++){
        pthread_join(threads[id], NULL);
    }

    printf("Threads finalizadas[1]\n");

    /* Calcula a media */
    for(id=0; id<MAX_THREADS; id++){
        soma += results[id];
    }

    media = soma/TAMANHO;

    /* Dispara as threads para calculo do desvio */
    for(id=0; id<MAX_THREADS; id++){
        info[id].id = id;
        info[id].media = media;
        pthread_create(&threads[id], NULL,
                       FuncaoThreadDesvio, (void*) &info[id]);
    }

    printf("Threads disparadas[2]\n");

    /* Aguarda as threads finalizarem */
    for(id=0; id<MAX_THREADS; id++){
        pthread_join(threads[id], NULL);
    }

    printf("Threads finalizadas[2]\n");

    /* Calcula a somatoria do desvio */
    for(id=0, soma=0; id<MAX_THREADS; id++){
        soma += results[id];
    }

    final_result = sqrt(1/(TAMANHO-1) * soma);

    /* Imprime o desvio padrao */
    printf("Desvio padrao = %lf\n", final_result);

    /* Libera as variaveis globais */
    free(results);
    free(dados);

    return 0;
}
