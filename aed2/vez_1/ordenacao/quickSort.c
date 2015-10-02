/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
    /* outros compomentes */
} TItem; 

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

int quickSort_particao(TItem *A, int p, int r){
    int i, j;
    TItem aux, pivo;
    
    i=p-1;
    pivo = A[r];

    for(j=p; j<r; j++){
        if(A[j].Chave <= pivo.Chave){
            i += 1;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    
    aux = A[i+1];
    A[i+1] = pivo;
    A[r] = aux;

    return i+1;
}

void quickSort_ordena(TItem *A, int p, int r){
    int i;
    
    if(p >= r) return;
    i = quickSort_particao(A, p, r);
    quickSort_ordena(A, i+1, r);
    quickSort_ordena(A, p, i-1);
}

void quickSort(TItem *A, int n){
    quickSort_ordena(A, 0, n-1);
}

int main()
{
    TItem *A;
    int n;

    n = Carrega(&A);
    quickSort_particao(A, 0, n-1);
    Imprime(A, n);
    quickSort(A, n);
    Imprime(A, n);
    Libera(&A);
        
    return 0;
}

