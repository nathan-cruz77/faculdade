#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define TAMANHO 10000000
#define MAX_THREADS 4

typedef struct{
    int p;
    int r;
} TInfo;

int THREADS = 0;

double* A;

pthread_mutex_t s;

void mergeSort_intercala(int p, int q, int r){
    int i, j, k;
    double *B;

    /* Aloca e popula o novo vetor */
    B = (double *) malloc(sizeof(double) * (r-p+1));
    for(i=p; i<=q; i++) B[i-p] = A[i];
    for(j=r; j>q; j--) B[j-p] = A[j];

    for(i=p, j=r, k=p; k<=r; k++){
        if(B[i-p] <= B[j-p]){
            A[k] = B[i-p];
            i++;
        }
        else{
            A[k] = B[j-p];
            j--;
        }
    }
    free(B);
}

void mergeSort_ordena(int p, int r){
    int q;

    if(p<r){
        q = (p+r)/2;
        mergeSort_ordena(p, q);
        mergeSort_ordena(q+1, r);
        mergeSort_intercala(p, q, r);
    }
}

void* mergeSort_ordena_2(void* args){
    int p, q, r;
    pthread_t t1, t2;
    TInfo *aux, info1, info2;

    aux = (TInfo*) args;
    p = aux->p;
    r = aux->r;

    if(p<r){
        q = (p+r)/2;

        if(THREADS < MAX_THREADS){
            pthread_mutex_lock(&s);
            info1.p = p;
            info1.r = q;
            pthread_create(&t1, NULL, mergeSort_ordena_2, (void*) &info1);

            info2.p = q+1;
            info2.r = r;
            pthread_create(&t2, NULL, mergeSort_ordena_2, (void*) &info2);
            THREADS += 2;
            pthread_mutex_unlock(&s);

            pthread_join(t1, NULL);
            pthread_join(t2, NULL);
        }
        else{
            mergeSort_ordena(p, q);
            mergeSort_ordena(q+1, r);
        }
        mergeSort_intercala(p, q, r);
    }
}

void mergeSort(int n){
    mergeSort_ordena(0, n-1);
}


int main(){
    int i;

    A = (double*) malloc(sizeof(double)*TAMANHO);

    srand(time(NULL));
    for(i=0; i<TAMANHO; i++){
        A[i] = rand();
    }

    mergeSort(TAMANHO);
    return 0;
}
