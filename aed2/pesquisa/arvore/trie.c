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
    else if(EhExterno(raiz)){
        if(raiz->Item.Chave == x)
            return raiz;
        else
            return NULL;
    }

    /* Se for interno */
    else{
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

    return pacote;
}

TArvBin Empacotador2(TItem item){
    TArvBin pacote = (TArvBin) malloc(sizeof(TNo));

    pacote->Item = item;
    pacote->Dir = NULL;
    pacote->Esq = NULL;

    return pacote;
}


int Igual(TItem a, TItem b, int digito){
    if(retornaDigito(a.Chave, digito) == retornaDigito(b.Chave, digito))
        return 1;
    return 0;
}

void InsereRecursivo(TArvBin* raiz, TItem x, int digito){
    TArvBin aux, aux2;

    /* Se for vazio */
    if(*raiz == NULL)
        *raiz = Empacotador2(x);

    /* Se for interno */
    else if(EhInterno(*raiz)){
        if(retornaDigito(x.Chave, digito) == 0)
            InsereRecursivo(&(*raiz)->Esq, x, digito+1);
        else
            InsereRecursivo(&(*raiz)->Dir, x, digito+1);
    }
    /* Se for externo */
    else if(EhExterno(*raiz) && (*raiz)->Item.Chave != x.Chave){

        aux2=NULL;
        aux=(*raiz);

        while(Igual(aux->Item, x, digito)){
            *raiz = Empacotador();
            aux2 = *raiz;
            if(retornaDigito(aux->Item.Chave, digito) == 0)
                raiz = &(*raiz)->Esq;
            else
                raiz = &(*raiz)->Dir;
            digito++;
        }

        if(aux2 == NULL){
            aux2 = Empacotador();
            *raiz = aux2;
        }

        if(retornaDigito(aux->Item.Chave, digito) == 0){
            aux2->Esq = aux;
            aux2->Dir = Empacotador2(x);
            *raiz = aux2;
        }
        else if(retornaDigito(aux->Item.Chave, digito) == 1){
            aux2->Dir = aux;
            aux2->Esq = Empacotador2(x);
            *raiz = aux2;
        }

    }
}

int Insere(TArvBin* pRaiz, TItem x){

    /* Se a arvore for vazia */
    if(*pRaiz == NULL){
        *pRaiz = Empacotador2(x);
        return 1;
    }

    InsereRecursivo(pRaiz, x, 0);
    return 1;
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
