#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct lista{
    struct lista* prox;
    int chave;
} Tlista;

typedef Tlista* Plista;

int hash(int x, int m){
    return x % m;
}

Plista empacotador(int x){
    Plista novo = malloc(sizeof(Tlista));
    novo->chave = x;
    return novo;
}

bool pesquisa_lista(Plista lista, int x){
    if(lista == NULL){
        return false;
    }
    else if(lista->chave == x){
        return true;
    }
    else{
        return pesquisa_lista(lista->prox, x);
    }
}

void insere_lista(Plista* lista, int x){
    if(*lista == NULL){
        *lista = empacotador(x);
    }
    else{
        insere_lista(&((*lista)->prox), x);
    }
}

void Remove_lista(Plista* lista, int x){
    Plista pai, aux;

    if(*lista == NULL){
        return;
    }
    else if(pesquisa_lista(*lista, x)){
        for(pai=NULL, aux=*lista; aux->chave != x; pai=aux, aux=aux->prox);
        if(pai != NULL){
            pai->prox = aux->prox;
        }
        else{
            *lista = aux->prox;
        }
        free(aux);
    }
}

void imprime_lista(Plista lista){
    Plista aux;

    for(aux=lista; aux!=NULL; aux=aux->prox){
        printf(" %d", aux->chave);
    }
}

bool pesquisa(Plista* tabela, int x, int m){
    return pesquisa_lista(tabela[hash(x, m)], x);
}

void insere(Plista* tabela, int x, int m){
    insere_lista(&tabela[hash(x, m)], x);
}

void Remove(Plista* tabela, int x, int m){
    Remove_lista(&tabela[hash(x, m)], x);
}

void imprime(Plista* tabela, int m){
    int i;

    for(i=0; i<m; i++){
        printf("[%d]", i);
        imprime_lista(tabela[i]);
        printf("\n");
    }
}

int main(){
    Plista* tabela;
    int m, n, i, x;

    scanf("%d", &m);

    if(m <= 0){
        return 0;
    }

    tabela = malloc(sizeof(Plista) * m);
    for(i=0; i<m; i++){
        tabela[i] = NULL;
    }

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &x);
        insere(tabela, x, m);
    }

    scanf("%d", &x);
    if(pesquisa(tabela, x, m)){
        Remove(tabela, x, m);
    }
    else{
        insere(tabela, x, m);
    }

    imprime(tabela, m);

    return 0;
}
