#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct{
	TChave Chave;
	/* outros compomentes */
} TItem;

typedef struct SNo *PArv;

typedef struct SNo{
	TItem Item;
	PArv Esq, Dir;
	int fb; // fator de balanceamento: -1, 0, +1
} TNo;


int FB(PArv No){
	if(No == NULL)
		return 0;
	return No->fb;
}


/* Left Rotation */
void LL(PArv pa){
    Parv aux;

    aux = a->Esq;
    pa->Esq = aux->Dir;
    aux->Dir = pa;
    pa = aux;
}


/* Right Rotation */
void RR(PArv pa){
    Parv aux;

    aux = pa->Dir;
    pa->Dir = aux->Esq;
    aux->Esq = pa;
    pa = aux;
}


void LR(PArv pa){
    Parv aux, aux2;

    aux = pa->Esq;
    aux2 = aux->Dir;
    aux->Dir = aux2->Esq;
    aux2->Esq = aux;
    pa->Esq = aux2->Dir;
    aux2->Dir = pa;
    pa = aux2;
}


void RL(PArv pa){
    Parv aux, aux2;

    aux = pa->Dir;
    aux2 = aux->Esq;
    aux->Esq = aux2->Dir;
    aux2->Dir = aux;
    pa->Dir = aux2->Esq;
    aux2->Esq = pa;
    pa = aux2;
}


int BalancaEsquerda(PArv pNo){
	// Implemente o seu metodo aqui!
}


int BalancaDireita(PArv pNo){
	// Implemente o seu metodo aqui!
}


PArv Inicializa(){
	return NULL;
}

PArv Pesquisa(PArv No, TChave x){
	if(No == NULL)
		return NULL; // retorna NULL caso a chave nao seja encontrada
	else if(x < No->Item.Chave)
		return Pesquisa(No->Esq, x);
	else if(x > No->Item.Chave)
		return Pesquisa(No->Dir, x);
	else
		return No;
}


int Insere(PArv pNo, TItem x){
	// Implemente o seu metodo aqui!
}


int Remove(PArv *p, TChave x){
	// Implemente o seu metodo aqui!
}


void Carrega(PArv pNo){
	int i, n;
	TItem x;

	scanf("%d", &n);
	for(i = 0; i < n ; i++){
		scanf("%d", &x.Chave);
		Insere(pNo, x);
	}
}


void Libera(PArv pNo){
	PArv No;

	No = pNo;
	if(No != NULL){
		Libera(&No->Esq);
		Libera(&No->Dir);
		free(No);
		(pNo) = NULL;
	}
}


void Imprime(PArv No){
	if(No != NULL){
		printf("(C%d", No->Item.Chave);
		Imprime(No->Esq);
		Imprime(No->Dir);
		printf(")");
	}
	else
		printf("()");
}


int main(){
	PArv Raiz;
	TItem x;

	Raiz = Inicializa();
	Carrega(&Raiz);
	scanf("%d", &x.Chave);
	if(Pesquisa(Raiz, x.Chave) == NULL)
		Insere(&Raiz, x);
	else
		Remove(&Raiz, x.Chave);
	Imprime(Raiz);
	Libera(&Raiz);

	return 0;
}
