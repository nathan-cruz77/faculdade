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

void carrega(PArv* arv, int* n){
	int i, aux;

	scanf("%d", n);

	for(i=0; i<(*n); i++){
		scanf("%d", &aux);
		*arv = insere(*arv, aux);
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

int main(){
	PArv arv, pai, aux;
	int n, i;

	pai = NULL;
	arv = NULL;

	carrega(&arv, &n);

	scanf("%d", &i);
	aux = pesquisa(arv, &pai, i);

	if(aux != NULL){
		remove_no(&arv, aux->chave);
	}
	else{
		arv = insere(arv, i);
	}

	Imprime(arv);
	printf("\n");
	
	return 0;
}
