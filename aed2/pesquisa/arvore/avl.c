/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 17/03/14
 *  R.A.: 86492
 */

#include <stdio.h>
#include <stdlib.h>

/* Definicao do tipo da chave (poderia ser outra coisa) */
typedef int TChave;


/* Definicao do tipo TItem (item de dados de cada no)
 * neste caso, apenas o tipo chave */
typedef struct{
	TChave chave;
} TItem;
typedef TItem* PItem;


/* Definicao do tipo do no da arvore */
typedef struct{
	PItem item;
	PArv esq;
    PArv dir;
    PArv pai;
    /* Fator de balanceamento (-1, 0, +1) */
	int fb;
} TArv;
typedef TArv* PArv;


PArv novo_no(TChave chave, PArv pai){
    /* Cria um novo com um item com a chave passada como parametro */
    PArv novo;
    PItem item;

    /* Aloca as estruturas no e item */
    novo = (PArv) malloc(sizeof (TArv));
    item = (PItem) malloc(sizeof (TItem));

    /* Popula o item */
    item->chave = chave;

    /* Popula o novo no */
    novo->item = item;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = pai;
    novo->fb = 0;
}


int insere(PArv raiz, TChave chave, PArv pai){
    /* Insere um no na arvore */

    /* Se a arvore for nula, a raiz sera o no inserido e esta balanceada */
    if(raiz == NULL){
        raiz = novo_no(chave, pai);
        return 1;
    }
    /* Se estivermos inserindo um elemento maior que o qual estamos
     * analisando, inserimos a direita deste. Retornamos +1 para indicar
     * insercao a direita */
    else if(chave > raiz->item->chave){
        raiz->fb += insere(raiz->dir, chave, raiz);
        return 0;
    }
    /* Se estivermos inserindo um elemento menor que o qual estamos
     * analisando, inserimos a esquerda deste. Retornamos -1 para indicar
     * insercao a esquerda */
    else if(chave < raiz->item->chave){
        raiz->fb += insere(raiz->esq, chave, raiz);
        return 0;
    }
    /* Nao eh para cair aqui */
    else
        return 0;
}


int remocao(PArv raiz, TChave chave){
    /* Remove um dado no da arvore */

    /* Se a arvore for nula, nao temos o que remover */
    if(raiz == NULL){
        return 0;
    }
    /* Se estivermos no elemento a ser removido */
    if(raiz->chave < chave){
        raiz->fb +=
    }
}
