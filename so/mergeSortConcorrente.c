#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef int TChave;

typedef struct {
    TChave Chave;
} TItem;

typedef TItem* PItem;

/* Estrutura para passar dados entre as threads */
typedef struct {
    int inicio;
    int fim;
    PItem A;
} TDados;

typedef TDados* PDados;


PItem Gerador(int n){
    PItem A;
    int i;

    if(n > 0){
        A = (PItem) malloc(n * sizeof(TItem));

        srand(time(NULL));
        for (i = 0; i < n ; i++)
            A[i].Chave = rand() % 1000 +1;

        return A;
    }
    else
        return NULL;

}


void insertionSort(TItem *A, int p, int r) {
    int i, j;
    TItem aux;

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


void Libera(TItem **A)
{
    if ((*A) != NULL) {
        free(*A);
        (*A) = NULL;
    }
}


void Imprime(TItem *A, int n){
    int i;

    if (n > 0) {
        printf("\n");
        for (i = 0; i < n; i++)
            printf("%d ", A[i].Chave);
        printf("\n");
    }
}


void mergeSort_intercala(TItem *A, int p, int q, int r){
    int i, j, k;
    TItem *B;

    if(A[q].Chave > A[q+1].Chave && q < r){
        B=(TItem *)malloc(sizeof(TItem)* r - p + 1);
        for(i = p; i<=q; i++)
            B[i-p] = A[i];

        for(j = q + 1; j <= r; j++)
            B[r+q+1-j-p] = A[j];

        i=p;
        j=r;

        for(k=p; k<=r; k++)
            if(B[i-p].Chave <= B[j-p].Chave){
                A[k] = B[i-p];
                i++;
            }
            else{
                A[k] = B[j-p];
                j--;
            }
        free(B);
    }
}

void merge(PItem A, int inicio, int fim){
    int q;

    if(fim > inicio){
        q = (fim + inicio)/2;

        merge(A, inicio, q);
        merge(A, q+1, fim);
        mergeSort_intercala(A, inicio, q, fim);
    }
}

void* mergeSort_ordena(void* args){
    PDados aux, aux1, aux2;
    PItem A;
    int p, q, r;

    aux = (PDados) args;

    p = aux->inicio;
    r = aux->fim;
    A = aux->A;

    q = (r + p)/2;
    //printf("Ordenando: A[%d] - A[%d]\n", aux->inicio, aux->fim);
    //if((r - p) <= 20)
        //insertionSort(aux->A, aux->inicio, aux->fim);

    //if(aux->fim > aux->inicio){
    //else{
        //aux1 = (PDados) malloc(sizeof(TDados));
        //aux2 = (PDados) malloc(sizeof(TDados));

        //aux1->A = aux->A;
        //aux2->A = aux->A;

        //aux1->inicio = p;
        //aux1->fim = (r + p)/2;

        //aux2->inicio = (r + p)/2 + 1;
        //aux2->fim = r;

        /* Primeira metade */
        //mergeSort_ordena((void*) aux1);
        merge(A, p, q);

        /* Segunda metade */
        //mergeSort_ordena((void*) aux2);
        merge(A, q+1, r);


        /* Concatena os resultados */
        mergeSort_intercala(A, p, q, r);

        free(aux1);
        free(aux2);
        pthread_exit(NULL);
    //}
    //}
}


void mergeSort(PItem A, int n){
    PDados aux = (PDados) malloc(sizeof(TDados));

    aux->inicio = 0;
    aux->fim = n-1;
    aux->A = A;
    mergeSort_ordena((void*) aux);
    free(aux);
}

void threader(PItem A, int n){
    PDados aux1, aux2;
    pthread_t t1;
    clock_t tempo;
    double tempo_usado;

    /* Se o vetor for pequeno use apenas uma thread
     * tirei esta parte para este codigo ficar mais
     * parecido com o codigo usando fork() e dar mais
     * credibilidade ao benchmark */
    //if(n <= 20){
        //printf("Usando ateh 1 thread\n");
        //mergeSort(A, n);
        //return;
    //}

    /* Se for grande separe em duas threads */
    //else{
        aux1 = (PDados) malloc(sizeof(TDados));
        aux2 = (PDados) malloc(sizeof(TDados));

        aux1->A = A;
        aux2->A = A;

        aux1->inicio = 0;
        aux1->fim = n/2;

        aux2->inicio = n/2+1;
        aux2->fim = n-1;

        /* Abre as threads, 1 para cada metade do vetor*/
        /* Primeira metade */
        tempo = clock();
        pthread_create(&t1, NULL, mergeSort_ordena, (void*) aux1);
        tempo = clock() - tempo;
        tempo_usado = (double) tempo/CLOCKS_PER_SEC;
        printf("Tempo gasto na primeira metade: %.14lf\n", tempo_usado);

        /* Segunda metade */
        mergeSort_ordena((void*) aux2);

        /* Aguarda as threads finalizarem */
        pthread_join(t1, NULL);

        /* Fazemos a intercalacao das metades ordenadas */
        mergeSort_intercala(A, 0, n/2, n-1);


        free(aux1);
        free(aux2);
    //}


}

int main(){
    PItem A;
    int n;
    double tempo_usado;
    clock_t tempo;


    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    tempo = clock();
    A = Gerador(n);
    tempo = clock() - tempo;
    tempo_usado = (double) tempo/CLOCKS_PER_SEC;
    printf("\nTempo de preenchimento do vetor: %.14lfs\n", tempo_usado);

    if(A == NULL){
        printf("Tamanho negativo\n");
        return 0;
    }

    tempo = clock();
    threader(A, n);
    tempo = clock() - tempo;
    tempo_usado = (double) tempo/CLOCKS_PER_SEC;
    printf("\nTempo de ordenacao: %.14lfs\n", tempo_usado);

    //Imprime(A, n);
    Libera(&A);

    return 0;
}
