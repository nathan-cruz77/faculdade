#include <stdio.h>
#include <stdlib.h>

typedef struct SLista *PLista;

typedef int TChave;

typedef struct {
    TChave Chave;
    /* outros compomentes */
} TItem;

typedef int TIndice;

typedef struct {
    PLista Lista;
    TIndice m, n;
} THash;

typedef struct SNo *TCelula;

typedef struct SNo {
    TItem Item;
    TCelula Prox;
} TNo;

typedef struct SLista {
    TCelula Primeiro, Ultimo;
} TLista;

void TLista_Inicializa(TLista *L)
{
    L->Primeiro = (TCelula) malloc(sizeof(TNo));
    L->Ultimo = L->Primeiro;
    L->Primeiro->Prox = NULL;
}

int TLista_EhVazia(TLista *L)
{
    return (L->Primeiro == L->Ultimo);
}

/* Insere um item no final da lista */
void TLista_Insere(TLista *L, TItem x)
{
    L->Ultimo->Prox = (TCelula) malloc(sizeof(TNo));
    L->Ultimo = L->Ultimo->Prox;
    L->Ultimo->Item = x;
    L->Ultimo->Prox = NULL;
}

/* Remove um dado no da lista */
void TLista_Remove(TLista *L, TCelula No)
{
    TCelula aux;

    aux = No->Prox;
    No->Prox = aux->Prox;
    if (No->Prox == NULL)
        L->Ultimo = No;
    free(aux);
}

/* Imprime os elementos da lista */
void TLista_Imprime(TLista *L)
{
    TCelula No;

    No = L->Primeiro->Prox;
    while (No != NULL) {
        printf(" %d", No->Item.Chave);
        No = No->Prox;
    }
}

void TLista_Libera(TLista *L)
{
    TCelula No;

    while (L->Primeiro->Prox != NULL) {
        No = L->Primeiro->Prox;
        L->Primeiro->Prox = No->Prox;
        free(No);
    }
    free(L->Primeiro);
}

TIndice h(THash *T, TChave k)
{
    return k % T->m;
}

THash *Inicializa(int m)
{
    TIndice i;
    THash *T;

    T = (THash *) malloc(sizeof(THash));

    T->n = 0; T->m = m;
    T->Lista = (PLista) malloc(T->m * sizeof(TLista));
    for (i = 0; i < T->m; i++)
        TLista_Inicializa(&T->Lista[i]);

    return T;
}

TCelula Pesquisa(THash *T, TChave x){
    TLista lista = T->Lista[h(T, x)];
    TCelula aux, aux2;

    if(lista.Primeiro == lista.Ultimo) return NULL;

    for(aux = lista.Primeiro, aux2 = lista.Primeiro->Prox;
        aux2 != NULL && aux2->Item.Chave != x;
        aux = aux2, aux2 = aux2->Prox);

    if(aux2 == NULL) return NULL;
    return aux;

}

int Insere(THash *T, TItem x){
    if(Pesquisa(T, x.Chave) == NULL){
        TLista_Insere(&(T->Lista[h(T, x.Chave)]), x);
        T->n++;
        return 1;
    }
    return 0;
}

int Remove(THash *T, TChave x)
{
    TCelula aux = Pesquisa(T, x);

    if(aux != NULL){
        TLista_Remove(&(T->Lista[h(T, x)]), aux);
        T->n--;
        return 1;
    }
    return 0;
}

void Carrega(THash *T)
{
    int i, n;
    TItem x;

    scanf("%d", &n);
    for (i = 0; i < n ; i++) {
        scanf("%d", &x.Chave);
        Insere(T, x);
    }
}

void Libera(THash **T)
{
    THash *aux;
    int i;

    aux = *T;
    if (aux != NULL) {
        for (i = 0; i < aux->m; i++) TLista_Libera(&aux->Lista[i]);
        if (aux->Lista != NULL) free(aux->Lista);
        free(aux);
        (*T) = NULL;
    }
}

void Imprime(THash *T)
{
    int i;
    if (T->m > 0) {
        for (i = 0; i < T->m; i++) {
            printf("[%d]", i);
            TLista_Imprime(&T->Lista[i]);
            printf("\n");
        }
    }
}

int main()
{
    TIndice m;
    THash *T;
    TItem x;

    scanf("%d", &m);
    T = Inicializa(m);
    Carrega(T);
    scanf("%d", &x.Chave);
    if (Pesquisa(T, x.Chave) == NULL)
        Insere(T, x);
    else
        Remove(T, x.Chave);
    Imprime(T);
    Libera(&T);

    return 0;
}

