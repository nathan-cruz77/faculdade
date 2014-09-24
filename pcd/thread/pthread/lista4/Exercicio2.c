#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define TAMANHO 6
#define MAX_THREADS 2

/* Vetores a serem usados */
double* A;
double* B;

/* Variavel global para segurar o resultado da soma */
double produto_escalar = 0;


/* Estrutura para passar dados para a thread */
typedef struct{
    //pthread_mutex_t* semafaro;
    int id;
} TArgs;

/* Semaforos */
pthread_mutex_t s;

/* Main da thread */
void* trabalhador(void* args){
    TArgs* arg = (TArgs*) args;

    int id = arg->id;
    //pthread_mutex_t s = *(arg->semafaro);

    int inicio, fim, i;
    double soma;

    inicio = id*(TAMANHO/MAX_THREADS);
    fim = inicio + (TAMANHO/MAX_THREADS);

    if(id == MAX_THREADS-1 && fim < TAMANHO)
        fim = TAMANHO;


    printf("Thread[%d]: %d a %d\n", id, inicio, fim);
    for(i=inicio, soma=0; i<fim; i++){
        soma += A[i]*B[i];
    }

    pthread_mutex_lock(&s);
    produto_escalar += soma;
    pthread_mutex_unlock(&s);
}

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
    pthread_t threads[MAX_THREADS];
    TArgs parametros[MAX_THREADS];

    srand(time(NULL));
    /* Aloca os vetores de dados */
    A = (double*) malloc(sizeof(double)*TAMANHO);
    B = (double*) malloc(sizeof(double)*TAMANHO);

    /* Preenche os vetores de dados aleatoriamente */
    for(i=0; i<TAMANHO; i++){
        A[i] = rand() % 10;
        B[i] = rand() % 10;
    }

    /* Dispara as threads */
    for(i=0; i<MAX_THREADS; i++){
        parametros[i].id = i;
        pthread_create(&threads[i], NULL, trabalhador, (void*)&parametros[i]);
    }

    /* Aguarda as threads finalizarem */
    for(i=0; i<MAX_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("A:\n\t");
    imprime_vet(A, TAMANHO);
    printf("B:\n\t");
    imprime_vet(B, TAMANHO);
    printf("Produto Escalar: %.2lf\n", produto_escalar);

    return 0;
}
