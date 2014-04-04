#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct { 
    TChave Chave; /* outros compomentes */ 
} TItem;

void Imprime(TItem *A, int n) {
    int i;
    if (n > 0) {
        printf("%d", A[0].Chave);
        for (i = 1; i < n; i++) printf(" %d", A[i].Chave);
        printf("\n");
    }
} 

void Metodo(TItem *A, int n) {
    int i, j;
    TItem aux;

    for(i=1;i<n;i++){
        aux = A[i];
        j = i-1;
        while(j>=0 && aux.Chave < A[j].Chave){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = aux;
    }
}

int main() {
    TItem *A;
    int i, n;
    scanf("%d", &n);
    A = (TItem *) malloc(n * sizeof(TItem));
    for (i = 0; i < n ; i++) scanf("%d", &A[i].Chave);
    Metodo(A, n); Imprime(A,n);
    return 0;
}
