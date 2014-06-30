#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int TChave;

typedef struct {
    TChave Chave;
} TItem;

typedef TItem* PItem;

PItem Gerador(int n){
    PItem A;
    int i;

    if(n > 0){
        A = (PItem) malloc(n * sizeof(TItem));

        srand(time(NULL));
        for (i = 0; i < n ; i++){
            A[i].Chave = rand();
        }

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
        printf("%d", A[0].Chave);
        for (i = 1; i < n; i++)
            printf(" %d", A[i].Chave);
        printf("\n");
    }
}

void mergeSort_intercala(TItem *A, int p, int q, int r){
    int i, j, k;
    TItem *B;

    if(A[q].Chave > A[q+1].Chave){
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

void mergeSort_ordena(TItem *A, int p, int r){
    int q;
    int n;

    if (p < r){

        if((r - p) <= 20)
            insertionSort(A, p, r);

        else{
            q = (r + p) / 2;

            mergeSort_ordena(A, p, q);
            mergeSort_ordena(A, q+1, r);
            mergeSort_intercala(A, p, q, r);
        }
    }
}

void mergeSort(TItem *A, int n){
    mergeSort_ordena(A, 0, n - 1);
}

int main(){
    TItem *A;
    int n;

/*
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
*/
    n = 100000000;
	printf("Tamanho: %d\n", n);

    A = Gerador(n);

    if(A == NULL){
        printf("Tamanho negativon\n");
        return 0;
    }

    mergeSort(A, n);

    //Imprime(A, n);

    /* Desaloca */
    Libera(&A);

    return 0;
}

