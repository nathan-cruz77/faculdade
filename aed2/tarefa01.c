#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
} TItem;

int Carrega(TItem **A){
    int i, n;

    scanf("%d", &n);

    if (n > 0) {
        (*A) = (TItem *) malloc(n * sizeof(TItem));
        for (i = 0; i < n ; i++)
            scanf("%d", &(*A)[i].Chave);
    }
    else (*A) = NULL;

return n;
}

void Libera(TItem **A){
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

void Ordena(TItem *A, int n){
    /* Implementação do algoritmo de ordenação por bolha */
    TItem aux;
    int i, j;

    for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(A[j+1].Chave < A[j].Chave){
                aux = A[j+1];
                A[j+1] = A[j];
                A[j] = aux;
            }
        }
    }

}

int main(){
    TItem *A;
    int n;

    n = Carrega(&A);
    //Imprime(A, n);
    Ordena(A, n);
    Imprime(A,n);
    Libera(&A);

    return 0;
}
