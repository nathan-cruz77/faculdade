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
    int digito;
} TNo;

int retornaDigito(TChave x, int digito)
{
    return ((x >> digito) & 1);
}

int EhInterno(TArvBin No){
    if(No->Esq != NULL || No->Dir != NULL)
        return 1;
    return 0;
}

int EhExterno(TArvBin No){
    if(No->Esq != NULL || No->Dir != NULL)
        return 0;
    return 1;
}

TArvBin Inicializa()
{
    return NULL;
}

/* Funcoes auxiliares */
TArvBin EmpacotaInterno(int digito){
    TArvBin novo = (TArvBin) malloc(sizeof(TNo));

    novo->Dir = NULL;
    novo->Esq = NULL;
    novo->digito = digito;

    return novo;
}

TArvBin EmpacotaExterno(TItem x){
    TArvBin novo = (TArvBin) malloc(sizeof(TNo));

    novo->Item = x;
    novo->Dir = NULL;
    novo->Esq = NULL;

    return novo;
}

/* Retorna a posicao na qual as chaves se diferenciam */
int CalculaDigito(TChave x, TChave y){
    int i;

    /* Se as chaves forem iguais */
    if(x == y)
        return -1;

    for(i=0;
        retornaDigito(x, i) == retornaDigito(y, i);
        i++);

    return i;
}

TArvBin Pesquisa(TArvBin No, TChave x){

    /* Se a arvore for vazia */
    if(No == NULL)
        return NULL;

    /* Se estiver em folha */
    if(EhExterno(No)){
        if(No->Item.Chave == x)
            return No;
        return NULL;
    }

    /* Se estiver em no interno */
    if(retornaDigito(x, No->digito) == 1)
        return Pesquisa(No->Dir, x);
    return Pesquisa(No->Esq, x);
}

void InsereEntre(TArvBin *pRaiz, TItem x, int digito){
    TArvBin pai, aux, aux2;

    /* Busca os nos entre os quais faremos a insercao */
    pai = NULL;
    aux = *pRaiz;
    while(aux->digito < digito){
        pai = aux;
        if(retornaDigito(x.Chave, aux->digito) == 1)
            aux = aux->Dir;
        else
            aux = aux->Esq;
    }

    /* Cria o no interno que estamos inserindo */
    aux2 = EmpacotaInterno(digito);

    /* Se estivermos inserindo em cima da raiz */
    if(pai == NULL){
        if(retornaDigito(x.Chave, digito) == 1){
            aux2->Dir = EmpacotaExterno(x);
            aux2->Esq = aux;
        }
        else{
            aux2->Esq = EmpacotaExterno(x);
            aux2->Dir = aux;
        }
        *pRaiz = aux2;
        return;
    }

    /* Caso estivermos inserindo entre dois nos */
    else{
        if(retornaDigito(x.Chave, pai->digito) == 1)
            pai->Dir = aux2;
        else
            pai->Esq = aux2;

        if(retornaDigito(x.Chave, digito) == 1){
            aux2->Dir = EmpacotaExterno(x);
            aux2->Esq = aux;
        }
        else{
            aux2->Esq = EmpacotaExterno(x);
            aux2->Dir = aux;
        }
        return;
    }
}

int Insere(TArvBin *pRaiz, TItem x){
    TArvBin aux, pai, novo;
    int digito;

    /* Se a arvore for vazia */
    if(*pRaiz == NULL){
        *pRaiz = EmpacotaExterno(x);
        return 1;
    }

    /* Procuramos a folha a ser comparada com o elemento */
    aux = *pRaiz;
    pai = NULL;

    while(EhInterno(aux)){
        pai = aux;

        if(retornaDigito(x.Chave, aux->digito) == 1)
            aux = aux->Dir;
        else
            aux = aux->Esq;
    }

    /* Se o elemento ja estiver inserido */
    if(aux->Item.Chave == x.Chave)
        return 0;

    /* Calcula o digito onde se diferenciam os itens */
    digito = CalculaDigito(aux->Item.Chave, x.Chave);

    /* Se o no pai do elemento selecionado for nulo
     * (arvore com apenas um elemento) */
    if(pai == NULL){
        pai = EmpacotaInterno(digito);

        if(retornaDigito(x.Chave, digito) == 1){
            pai->Dir = EmpacotaExterno(x);
            pai->Esq = aux;
        }
        else{
            pai->Esq = EmpacotaExterno(x);
            pai->Dir = aux;
        }
        *pRaiz = pai;
        return 1;
    }

    if(EhExterno(aux)){
        if(pai->digito > digito){
            InsereEntre(pRaiz, x, digito);
            return 1;
        }

        else{
            novo = EmpacotaInterno(digito);

            /* Acerta o interno que estamos inserindo na arvore */
            if(retornaDigito(x.Chave, pai->digito) == 1)
                pai->Dir = novo;
            else
                pai->Esq = novo;

            /* Acerta os ponteiros do interno que acabamos de inserir */
            if(retornaDigito(x.Chave, digito) == 1){
                novo->Dir = EmpacotaExterno(x);
                novo->Esq = aux;
            }
            else{
                novo->Esq = EmpacotaExterno(x);
                novo->Dir = aux;
            }
            return 1;
        }
    }

    /* Deu merda */
    return -1;
}

void Imprime(TArvBin No);

void Carrega(TArvBin *pNo)
{
    int i, n;
    TItem x;

    scanf("%d", &n);
    for (i = 0; i < n ; i++) {
        scanf("%d", &x.Chave);
        Insere(pNo, x);
    }
}

void Libera(TArvBin *pNo)
{
    TArvBin No;

    No = *pNo;
    if (No != NULL) {
        Libera(&No->Esq);
        Libera(&No->Dir);
        free(No);
        (*pNo) = NULL;
    }
}

void Imprime(TArvBin No)
{
    if (No != NULL) {
        printf("(");
        if (EhExterno(No))
            printf("C%d", No->Item.Chave);
        else
            printf("D%d", No->digito);
        Imprime(No->Esq);
        Imprime(No->Dir);
        printf(")");
    }
    else
        printf("()");
}

int main()
{
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
