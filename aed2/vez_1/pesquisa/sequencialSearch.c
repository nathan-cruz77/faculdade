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

/* encontra e retorna o indice da chave x na tabela */ 
TIndice Pesquisa(TTabela *T, TChave x) {
    int i;

    for(i=0; i<(T->max); i++){
        if(T->Item[i].Chave == x) return i;
    }
    return -1;
}

/* insere um registro na tabela */
void Insere(TTabela *T, TItem x) {
    if(T->n <= T->max-1){
        T->Item[T->n] = x;
        T->n += 1;
    }
    else if(T->n >= T->max){
        T->max += 1;
        T->Item = (TItem *) realloc(T->Item, T->max * sizeof(TItem));
        T->Item[T->n] = x;
        T->n += 1;
    }
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

void Imprime(TTabela *T) {
    int i;
    if (T->n > 0) {
        printf("%d", T->Item[0].Chave);
        for (i = 1; i < T->n; i++)
            printf(" %d", T->Item[i].Chave);
        printf("\n");
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
