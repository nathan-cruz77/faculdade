#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Neste programa farei uma implementacao usando lista de listas para
 * representar uma tabela de espalhamento */

/* Quantidade maxima de itens a serem guardados sem colisao */
#define MAXTAM 1610612741

/* Define os tipos que usaremos */
typedef int TChave;

typedef struct{
    TChave chave;
    TItem* prox;
} TItem;

typedef struct{
    int indice;
    TItem* elemento;
    TTabela* prox;
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
PTabela insere_tabela(PTabela tabela, TChave chave){
    PTabela aux, ante;
    PItem aux2 = novo_item(chave);

    /* Se a tabela estiver vazia, criamos a posicao com
     * indice = hash(chave) */
    if(tabela == NULL){
        aux = nova_tabela(hash(chave));
        aux->elemento = aux2;
        return aux;
    }

    /* Se a tabela nao estiver vazia procuramos a posicao a inserir,
     * para mante-la ordenada. Se houver colisao, inserimos na lista
     * de colisoes */
    for(ante=tabela; ante->indice < hash(chave))


}
