#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
    /* outros compomentes */ 
} TItem;
typedef int TIndice;

typedef struct {
    TItem *Item;
    TIndice n, max;
} TTabela;

/* inicializa uma tabela */
TTabela *Inicializa() {
    TTabela *T;
    T = (TTabela *) malloc(sizeof(TTabela));
    T->n = 0;
    T->max = 10;
    T->Item = (TItem *) malloc(T->max * sizeof(TItem));
    return T;
}

void Imprime(TItem *A, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", A[i].Chave);
    }
    printf("\n");
}

/* encontra e retorna o indice da chave x na tabela */ 
TIndice Pesquisa(TTabela *T, TChave x) {
    int i;
    
    //bolha(T->Item, (T->n)+1);
    //Imprime(T->Item, T->n);

    for(i=0; i<(T->n); i++){
        if(T->Item[i].Chave == x) return i;
    }
    return -1;
}

/* insere um registro na tabela */
void Insere(TTabela *T, TItem x) {
   int i, j;
   TItem aux;

   if(T->n >= T->max){
       T->max += 1;
       T->Item = (TItem *) realloc(T->Item, T->max * sizeof(TItem));
   }
   
   for(i=0;i<(T->n) && T->Item[i].Chave < x.Chave;i++);

   for(j=(T->n);j>i;j--){
       T->Item[j] = T->Item[j-1];
   }
   T->Item[i] = x;
   T->n += 1;
}

void Carrega(TTabela *T) {
    int i, n;
    TItem x;
    scanf("%d", &n);
    for (i = 0; i < n ; i++) {
        scanf("%d", &x.Chave);
        Insere(T, x);
    } 
}

void Libera(TTabela **T) {
    TTabela *aux;
    aux = *T;
    if (aux != NULL) {
        if (aux->Item != NULL) free(aux->Item);
        free(aux);
        (*T) = NULL;
    }
}

int main() {
    TTabela *T;
    TIndice i;
    TChave x;
    T = Inicializa();
    Carrega(T);
    scanf("%d", &x);
    i = Pesquisa(T, x);
    printf("%d\n", i);
    Libera(&T);
    return 0;
} 
