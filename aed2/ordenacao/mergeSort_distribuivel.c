#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

/* Definicao do tipo da chave a ser usada para ordenacao */
typedef int TChave;

/* Definicao da estrutura para elementos do vetor */
typedef struct{
    TChave Chave;
} TItem;

/* Definicao da esturtura para passar como argumentos para as threads */
typedef struct{
    TItem* A;
    int p;
    int r;
} TArgs;

/* Inicio da definicao das funcoes utilizadas na ordenacao */

/* Funcao responsavel por fazer a concatenacao de subvetores ordenados */
void* mergeSort_intercala(void* params){

    TArgs* argumentos = (TArgs*) params;
    TItem *A = argumentos->A;
    int p = argumentos->p;
       int r = argumentos->r;

       int q = (r-p+1)/2;
    int i, j, k;
    TItem *B;

    /* Aloca o novo vetor */
    B = (TItem *) malloc(sizeof(TItem) * (r-p+1));

    /* Popula o novo vetor */
    for(i=p; i<=q; i++) B[i-p] = A[i];
    for(j=r; j>q; j--) B[j-p] = A[j];

    for(i=p, j=r, k=p; k<=r; k++){
        if(B[i-p].Chave <= B[j-p].Chave){
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

/* Insertion Sort para otimizar o Merge Sort */
void *insertionSort(void* args){
    TItem aux;
    int i, j;

    TArgs* params = (TArgs*) args;
    TItem *A = params->A;
       int p = params->p;
       int r = params->r;

    if(r-p+1 > 1){
        for(i=p+1; i<=r; i++){
            aux = A[i];
            j = i-1;
            while(j>=p && aux.Chave < A[j].Chave){
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = aux;
        }
    }
    return params;
}

/* Funcao recursiva que chama o insertionSort para subetores
 * suficientemente pequenos (tamanho <= 20)*/
void *mergeSort_ordena(void* args){
    TArgs* params = (TArgs*) args;

    TItem *A = params->A;
    int p = params->p;
    int r = params->r;
    int q;

    if((r-p+1) <= 20){
        insertionSort((void*) params);
    }
    else{
        params->r = (p+r)/2;
        mergeSort_ordena((void*) params);

        params->p = (p+r)/2+1;
        params->r = r;
        mergeSort_ordena((void*) params);

        params->p = p;
        params->r = r;
        mergeSort_intercala((void*) params);
    }

    /* Finaliza a thread */
    pthread_exit(NULL);
}


int Carrega(TItem **A)
{
    int i, n;

    scanf("%d", &n);

    if (n > 0) {
        (*A) = (TItem *) malloc(n * sizeof(TItem));
        for (i = 0; i < n ; i++)
            scanf("%d", &(*A)[i].Chave);
    }
    else
        (*A) = NULL;

    return n;
}


void threader(TItem* A, int n){

    TArgs* argumentos = (TArgs*) malloc(sizeof(TArgs));
    argumentos->A = A;
    argumentos->p = 0;
    argumentos->r = n-1;

    /* ID's das Threads */
    pthread_t threads[8];

    /* Variaveis auxiliares */
    int i, j, p, r;
    int contador;
    void* params;
    TArgs *args1, *args2;

    /* Se o vetor for pequeno o bastante, fazemos ordenacao
     * simples com 1 thread */
    if(n <= 20){
        printf("Detected small vector, using 1 thread and simple ordering method\n");
        insertionSort((void*) argumentos);
        return;
    }

    /* Caso o vetor seja grande, usamos varias threads */

    /* Caso possamos usar uma thread a cada 20 elementos */
    if(n <= 160){
        printf("Detected small vector, using up to 8 threads and simple ordering method\n");

        j = 0; p = 0; r = 0;
        for(i=0; i<n; i++){
            if(i%20 == 0 && i != 0){
                r = i-1;
                /* Determina o que sera passado para a thread */
                argumentos->p = p;
                argumentos->r = r;
                /* Cria a thread */
                pthread_create(&threads[j], NULL, &insertionSort,
                               (void*) argumentos);
                /* Atualiza os contadores */
                p = r;
                j++;
            }
        }

        /* Esperamos de duas em duas as threads terminarem para concatenar
         * os resultados */
        printf("Waiting for threads to terminate...\n");

        for(contador=8; contador > 0; contador/=2){
            for(i=0, j=0; i<contador; i+=2){
                pthread_join(threads[i], &params);
                args1 = (TArgs*) params;
                pthread_join(threads[i+1], &params);
                args2 = (TArgs*) params;

                /* Argumentos a serem passados para o concatenador */
                argumentos->p = args1->p;
                argumentos->r = args2->r;

                /* Verifica se estamos ordenando os elementos certos */
                printf("Concatenando A[%d]-A[%d]\n", argumentos->p,
                       argumentos->r);

                /* Cria uma nova thread para concatenar */
                //printf("Utilizando thread[%d]\n", j);
                pthread_create(&threads[j], NULL, &mergeSort_intercala,
                               (void*) argumentos);
                j++;
            }
        }
    }
}

void imprime(TItem* A, int n){
    int i;

    for(i=0; i<n; i++){
        if(i%20 == 0 && i != 0) printf("\n");
        printf("%d ", A[i].Chave);
    }
    printf("\n");
}

int main(){
    TItem* A;
    int n = Carrega(&A);

    /* Se conseguirmos carregar o vetor, ordenamos */
    if(n > 0){
        imprime(A, n);
        printf("\n");
        threader(A, n);
        printf("\n");
        imprime(A, n);
    }
    else
        printf("Unable to order vector without elements\n");

    return 0;
}
