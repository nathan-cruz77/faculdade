#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Neste programa farei uma implementacao usando lista de listas para
 * representar uma tabela de espalhamento */

/* Quantidade maxima de itens a serem guardados sem colisao */
#define MAXTAM 1610612741

/* Define os tipos que usaremos */
typedef int TChave;

typedef struct Item{
    TChave chave;
    struct Item* prox;
} TItem;

typedef struct Tabela{
    int indice;
    struct Item* elemento;
    struct Tabela* prox;
} TTabela;

typedef TItem* PItem;
typedef TTabela* PTabela;


/* Funcao para calcular o hash das chaves */
int hash(TChave chave){
    return chave % MAXTAM;
}

/* Funcao para inicializar as estruturas vazias */
PItem novo_item(TChave chave){
    PItem novo = (PItem) malloc(sizeof (TItem));
    novo->chave = chave;
    novo->prox = NULL;
    return novo;
}


PTabela nova_tabela(int indice){
    PTabela tabela = (PTabela) malloc(sizeof (TTabela));
    tabela->indice = indice;
    tabela->elemento = NULL;
    tabela->prox = NULL;
    return tabela;
}


/* Funcao para inserir elementos na tabela */
void insere_tabela(PTabela tabela, TChave chave){
    PTabela aux, aux2, ante;
    PItem item = novo_item(chave);
    int hash_chave = hash(chave);

    /* Se a tabela estiver vazia, criamos a posicao com
     * indice = hash(chave) */
    if(tabela == NULL){
        aux = nova_tabela(hash_chave);
        aux->elemento = item;
        tabela = aux;
        return;
    }

    /* Se a tabela nao estiver vazia procuramos a posicao a inserir,
     * para mante-la ordenada. Se houver colisao, inserimos na lista
     * de colisoes */
    for(ante=NULL, aux=tabela;
        aux->indice < hash_chave && aux != NULL;
        ante = aux, aux = aux->prox);

    /* Estamos inserindo no fim da lista */
    if(aux == NULL){
        ante->prox = nova_tabela(hash_chave);
        (ante->prox)->elemento = item;
        return;
    }

    /* Estamos inserindo no começo da lista */
    if(aux == tabela){
        aux = nova_tabela(hash_chave);
        aux->prox = tabela;
        aux->elemento = item;
        tabela = aux;
        return;
    }

    /* Estamos inserindo no meio da tabela */
}
