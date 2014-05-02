#include <stdio.h>
#include <stdlib.h>

/* Definicao do tipo da chave (poderia ser outra coisa) */
typedef int TChave;


/* Definicao do tipo TItem (item de dados de cada no)
 * neste caso, apenas o tipo chave */
typedef struct{
	TChave Chave;
} TItem;


/* Definicao do tipo TNo (guarda o no da arvore) */
typedef struct SNo{
	TItem Item;
	PArv Esq;
    PArv Dir;
	int fb; // fator de balanceamento: -1, 0, +1
} TNo;


/* Definicao do tipo ponteiro para no */
typedef struct SNo* PArv;


/* Funcao para verificar o fator de balanceamento do no */
int FB(PArv No){
	if(No == NULL)
		return 0;
	return No->fb;
}


/* Rotacao esquerda-esquerda */
void LL(PArv raiz){
    PArv aux;

    aux = raiz->Esq;
    raiz->Esq = aux->Dir;
    aux->Dir = raiz;
    raiz = aux;
}


/* Rotacao direita-direita */
void RR(PArv raiz){
    PArv aux;

    aux = raiz->Dir;
    raiz->Dir = aux->Esq;
    aux->Esq = raiz;
}


/* Rotacao esquerda-direita */
void LR(PArv raiz){
    PArv aux, aux2;

    aux = raiz->Esq;
    aux2 = aux->Dir;
    aux->Dir = aux2->Esq;
    aux2->Esq = aux;
    raiz->Esq = aux2->Dir;
    aux2->Dir = raiz;
    raiz = aux2;
}


/* Rotacao direita-esquerda */
void RL(PArv raiz){
    PArv aux, aux2;

    aux = raiz->Dir;
    aux2 = aux->Esq;
    raiz->Dir = aux2->Esq;
    aux2->Esq = raiz;
    aux->Esq = aux2->Dir;
    aux2->Dir = aux;
    raiz = aux2;
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

/* Funcao para criar um novo no */
PArv novo(TItem x){
    PArv novo;

    novo = (PArv) malloc(sizeof (TNo));
    novo->Esq = NULL;
    novo->Dir = NULL;
    novo->Item = x;
    novo->fb = 0;

    return novo;
}

/* Funcao para encontrar o pai de um novo */
PArv PesquisaPai(PArv raiz, PArv escolhido){
    if(raiz == NULL){
        return NULL;
    }
    else if(raiz->Esq == escolhido || raiz->Dir == escolhido){
        return raiz;
    }
    else if(PesquisaPai(raiz->Dir, escolhido) != NULL){
        return PesquisaPai(raiz->Dir, escolhido);
    }
    return PesquisaPai(raiz->Esq, escolhido);
}

/* Funcao para encontrar um no */
PArv Pesquisa(PArv raiz, TChave x){
	if(raiz == NULL)
		return NULL;
	else if(x < raiz->Item.Chave)
		return Pesquisa(raiz->Esq, x);
	else if(x > raiz->Item.Chave)
		return Pesquisa(raiz->Dir, x);
	else
		return raiz;
}

/* Funcao para inserir no */
int Insere(PArv raiz, TItem x){
    PArv new;

    if(raiz == NULL){

        return 1;
    }
    else if(x.Chave > raiz->Item.Chave){
        raiz->fb += Insere(raiz->Dir, x);
    }
    else if(x.Chave < raiz->Item->Chave){
        raiz->fb -= Insere(raiz->Esq, x);
    }


}

int Remove(PArv* raiz, TChave x){
    if(x > (*raiz)->Item.Chave){
        (*raiz)->fb -= Remove(&(*raiz->Dir), x);
    }
    else if(x < (*raiz)->Item.Chave){
        (*raiz)->fb += Remove(&(*raiz->Esq), x);
    }
    else if((*raiz) == NULL){
        return 0;
    }
    else{
        (*raiz) =
    }
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
