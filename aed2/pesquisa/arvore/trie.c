#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
    TChave Chave;
    /* outros compomentes */
} TItem;

typedef struct SNo *TArvBin;

typedef struct SNo {
    TItem Item;
    TArvBin Esq, Dir;
} TNo;

int retornaDigito(TChave x, int digito){
    return ((x >> digito) & 1);
}

int EhInterno(TArvBin No){
    if(No->Dir != NULL || No->Esq != NULL)
        return 1;
    return 0;
}

int EhExterno(TArvBin No){
    if(No->Dir != NULL || No->Esq != NULL)
        return 0;
    return 1;
}

TArvBin Inicializa(){
    return NULL;
}

TArvBin PesquisaRecursiva(TArvBin raiz, TChave x, int digito){

    /* Se a arvore for vazia */
    if(raiz == NULL)
        return NULL;

    /* Se for externo */
    if(EhExterno(raiz)){
        if(raiz->Item.Chave == x)
            return raiz;
        else
            return NULL;
    }

    /* Se for interno */
    if(EhInterno(raiz)){
        if(retornaDigito(x, digito) == 0)
            return PesquisaRecursiva(raiz->Esq, x, digito+1);
        else
            return PesquisaRecursiva(raiz->Dir, x, digito+1);
    }
}

TArvBin Pesquisa(TArvBin Raiz, TChave x){
    return PesquisaRecursiva(Raiz, x, 0);
}

TArvBin Empacotador(){
    TArvBin pacote = (TArvBin) malloc(sizeof(TNo));
    pacote->Dir = NULL;
    pacote->Esq = NULL;
}

int Igual(TItem a, TItem b, int digito){
    if(retornaDigito(a.Chave, digito) == retornaDigito(b.Chave, digito))
        return 1;
    return 0;
}

void InsereRecursivo(TArvBin raiz, TItem x, int digito){
    int i, j;

    /* Se for interno */
    if(EhInterno(raiz)){
        if(retornaDigito(x.Chave, digito) == 0)
            InsereRecursivo(raiz->Esq, x, digito+1);
        else
            InsereRecursivo(raiz->Dir, x, digito+1);
    }
    /* Se for externo
    else if(EhExterno(raiz))
    }*/
}

int Insere(TArvBin *pRaiz, TItem x){

    /* Se a arvore for vazia */
    if(*pRaiz == NULL){
        *pRaiz = Empacotador();
        (*pRaiz)->Item = x;
        return 1;
    }

    if(Pesquisa(*pRaiz, x.Chave) != NULL)
        return 0;

    InsereRecursivo(*pRaiz, x, 0);
}

void Carrega(TArvBin *pNo){
    int i, n;
    TItem x;

    scanf("%d", &n);
    for (i = 0; i < n ; i++) {
        scanf("%d", &x.Chave);
        Insere(pNo, x);
    }
}

void Libera(TArvBin *pNo){
    TArvBin No;

    No = *pNo;
    if (No != NULL) {
        Libera(&No->Esq);
        Libera(&No->Dir);
        free(No);
        (*pNo) = NULL;
    }
}

void Imprime(TArvBin No){
    if (No != NULL) {
        printf("(");
        if (EhExterno(No))
            printf("C%d", No->Item.Chave);
        Imprime(No->Esq);
        Imprime(No->Dir);
        printf(")");
    }
    else
        printf("()");
}

int main(){
    TArvBin Raiz;
    TItem x;

    Raiz = Inicializa();
    Carrega(&Raiz);
    scanf("%d", &x.Chave);
    if (Pesquisa(Raiz, x.Chave) == NULL)
        Insere(&Raiz, x);
    Imprime(Raiz);
    Libera(&Raiz);

    return 0;
}
