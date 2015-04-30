#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Arv{
	int chave;
	int fb;
	struct Arv* esq;
	struct Arv* dir;
} TArv;

typedef TArv* PArv;

PArv empacotador(int x){
	PArv novo = (PArv) malloc(sizeof(TArv));

	novo->chave = x;
	novo->fb = 0;
	novo->esq = NULL;
	novo->dir = NULL;

	return  novo;
}

int altura(PArv arv){
	int esq, dir;

	if(arv == NULL){
		return -1;
	}
	else{
		esq = altura(arv->esq);
		dir = altura(arv->dir);

		if(esq > dir){
			return 1 + esq;
		}
		else{
			return 1 + dir;
		}
	}
}

int abs(int x){
	if(x > 0){
		return x;
	}
	else{
		return x * -1;
	}
}

bool isAvl(PArv arv){
	if(arv == NULL){
		return true;
	}
	else if(abs(arv->fb) < 2){
		return (true && isAvl(arv->esq) && isAvl(arv->dir));
	}
	else{
		return false;
	}
}

void recalcula_fb(PArv arv){

	if(arv == NULL){
		return;
	}

	recalcula_fb(arv->esq);
	recalcula_fb(arv->dir);

	arv->fb = altura(arv->esq) - altura(arv->dir);
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

PArv* busca_desbalanceado(PArv* arv){
	PArv* esq;
	PArv* dir;

	if(*arv == NULL){
		return NULL;
	}

	esq = busca_desbalanceado(&((*arv)->esq));
	dir = busca_desbalanceado(&((*arv)->dir));

	if(esq != NULL){
		if(abs((*esq)->fb) >= 2){
			return esq;	
		}
	}
	else if(dir != NULL){
		if(abs((*dir)->fb) >= 2){
			return dir;
		}
	}
	else if(abs((*arv)->fb) >= 2){
		return arv;
	}
	else{
		return NULL;
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

/* Rotacoes */
void LL(PArv* arv){
	PArv b;

	b = (*arv)->esq;
	(*arv)->esq = b->dir;
	b->dir = *arv;
	*arv = b;

}

void RR(PArv* arv){
	PArv b;

	b = (*arv)->dir;
	(*arv)->dir = b->esq;
	b->esq = *arv;
	*arv = b;

}

void LR(PArv* arv){
	PArv b, c;

	b = (*arv)->esq;
	c = b->dir;
	(*arv)->esq = c->dir;
	b->dir = c->esq;
	c->dir = *arv;
	c->esq = b;
	*arv = c;
}

void RL(PArv* arv){
	PArv b, c;

	b = (*arv)->dir;
	c = b->esq;
	(*arv)->dir = c->esq;
	b->esq = c->dir;
	c->dir = b;
	c->esq = *arv;
	*arv = c;
}

void make_avl(PArv* arv){
	recalcula_fb(*arv);

	if((*arv)->fb >= 2){
		if((*arv)->esq->fb >= 0){
			LL(arv);
		}
		else{
			LR(arv);
		}
	}
	else if((*arv)->fb <= -2){
		if((*arv)->dir->fb <= 0){
			RR(arv);
		}
		else{
			RL(arv);
		}
	}
}

void balanceador(PArv* arv){
	if(*arv != NULL){
		balanceador(&(*arv)->esq);
		balanceador(&(*arv)->dir);
		make_avl(arv);
	}
}

void carrega(PArv* arv, int* n){
	int i, aux;

	scanf("%d", n);

	for(i=0; i<(*n); i++){
		scanf("%d", &aux);
		*arv = insere(*arv, aux);
		balanceador(arv);
	}
}

int main(){
	PArv raiz, aux;
	int x, aux2;

	raiz = NULL;
	carrega(&raiz, &aux2);
	
	scanf("%d", &x);
	if(pesquisa(raiz, &aux,x) == NULL){
		raiz = insere(raiz, x);
		balanceador(&raiz);
	}
	else{
		remove_no(&raiz, x);
		balanceador(&raiz);
	}

	Imprime(raiz);
	
	return 0;
}
