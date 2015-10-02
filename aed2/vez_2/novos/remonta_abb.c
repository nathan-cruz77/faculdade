#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Arv{
    int chave;
    struct Arv* esq;
    struct Arv* dir;
} TArv;

typedef TArv* PArv;

PArv empacotador(int x){
    PArv novo = (PArv) malloc(sizeof(TArv));

    novo->chave = x;
    novo->esq = NULL;
    novo->dir = NULL;

    return  novo;
}

PArv pesquisa(PArv arv, PArv* pai, int x){
    if(arv == NULL){
        return NULL;
    }

    else if(arv->chave == x){
        return arv;
    }

    else if(x < arv->chave){
        *pai = arv;
        return pesquisa(arv->esq, pai, x);
    }

    else{
        *pai = arv;
        return pesquisa(arv->dir, pai, x);
    }
}

PArv insere(PArv arv, int x){
    if(arv == NULL){
        return empacotador(x);
    }

    else if(x == arv->chave){
        return arv;
    }    

    else if(x > arv->chave){
        arv->dir = insere(arv->dir, x);
        return arv;
    }

    else{
        arv->esq = insere(arv->esq, x);
        return arv;
    }
}

void carrega(int** preOrdem, int** emOrdem, int* n){
    int i, aux;

    scanf("%d", n);

    *preOrdem = (int*) malloc(sizeof(int)*(*n));
    *emOrdem = (int*) malloc(sizeof(int)*(*n));

    for(i=0; i<(*n); i++){
        scanf("%d", &((*preOrdem)[i]));
    }

    for(i=0; i<(*n); i++){
        scanf("%d", &((*emOrdem)[i]));
    }
}

PArv busca_sucessor(PArv arv, PArv* pai){
    PArv aux;

    for(aux=arv->dir; aux->esq != NULL; aux = aux->esq);

    return pesquisa(arv, pai, aux->chave);
}

bool remove_no(PArv* arv, int x){
    PArv a_ser_removido, pai_do_removido=NULL;
    PArv sucessor, pai_do_sucessor=NULL;

    if(*arv == NULL){
        return false;
    }

    a_ser_removido = pesquisa(*arv, &pai_do_removido, x);

    if(a_ser_removido == NULL)
        return false;

    if(a_ser_removido->dir == NULL){
        if(a_ser_removido == *arv){
            *arv = a_ser_removido->esq;
        }
        else if(pai_do_removido->dir == a_ser_removido){
            pai_do_removido->dir = a_ser_removido->esq;
        }
        else if(pai_do_removido->esq == a_ser_removido){
            pai_do_removido->esq = a_ser_removido->esq;
        }
        free(a_ser_removido);
        return true;
    }
    else if(a_ser_removido->esq == NULL){
        if(a_ser_removido == *arv){
            *arv = a_ser_removido->dir;
        }
        else if(pai_do_removido->dir == a_ser_removido){
            pai_do_removido->dir = a_ser_removido->dir;
        }
        else if(pai_do_removido->esq == a_ser_removido){
            pai_do_removido->esq = a_ser_removido->dir;
        }
        free(a_ser_removido);
        return true;
    }
    else{
        sucessor = busca_sucessor(a_ser_removido, &pai_do_sucessor);

        a_ser_removido->chave = sucessor->chave;
        
        return remove_no(&(a_ser_removido->dir), sucessor->chave);
    }    
}

void Imprime(PArv No)
{
    if (No != NULL) {
        printf("(C%d", No->chave);
        Imprime(No->esq);
        Imprime(No->dir);
        printf(")");
    }
    else{
        printf("()");
    }
}

PArv remonta(int* preOrdem, int* emOrdem, int esq, int dir, int* i){
    int j, raiz;
    PArv aux;

    if(esq<=dir){
        
        for(j=esq; j<=dir; j++){
            if(emOrdem[j] == preOrdem[(*i)]){
                raiz = j;
                j = dir+1;
            }
        }

        aux = empacotador(preOrdem[(*i)]);
        (*i)++;
        aux->esq = remonta(preOrdem, emOrdem, esq, raiz-1, i);
        aux->dir = remonta(preOrdem, emOrdem, raiz+1, dir, i);
        return aux;
    }
    else{
        return NULL;
    }
}

void pos_ordem(PArv arv){
    if(arv == NULL){
        return;
    }

    pos_ordem(arv->esq);
    pos_ordem(arv->dir);
    printf("%d\n", arv->chave);
}

int main(){
    PArv arv=NULL;
    int* preOrdem;
    int* emOrdem;
    int n, i=0;
    
    carrega(&preOrdem, &emOrdem, &n);

    arv = remonta(preOrdem, emOrdem, 0, n-1, &i);    

    pos_ordem(arv);
    
    return 0;
}
