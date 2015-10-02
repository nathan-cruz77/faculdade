#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
    /* outros compomentes */
} TItem; 

TItem *Aloca(int n)
{
    return ((n > 0) ? ((TItem *) malloc(n * sizeof(TItem))) : (NULL));
}

int Carrega(TItem **A)
{
    int i, n;
    
    scanf("%d", &n);
    
    (*A) = Aloca(n);
    for (i = 0; i < n ; i++)
        scanf("%d", &(*A)[i].Chave);

    return n;
}

void Libera(TItem **A)
{
    if ((*A) != NULL) {
        free(*A);
        (*A) = NULL;
    }
}

void Imprime(TItem *A, int n)
{
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

    /* Aloca e popula o novo vetor */
    B = (TItem*) malloc(sizeof(TItem) * (r-p+1));
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

void mergeSort_ordena(TItem *A, int p, int r){
    int q;

    if(p<r){
        q = (p+r)/2;
        mergeSort_ordena(A, p, q);
        mergeSort_ordena(A, q+1, r);
        mergeSort_intercala(A, p, q, r);
    }
}

void mergeSort(TItem *A, int n){
    mergeSort_ordena(A, 0, n-1);
}

int main()
{
    TItem *A;
    int n;

    n = Carrega(&A);
    mergeSort(A, n);
    Imprime(A, n);
    Libera(&A);
        
    return 0;
}
