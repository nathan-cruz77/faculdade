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

int EhInterno(TArvBin No)
{
	// Implemente o seu metodo aqui!
}

int EhExterno(TArvBin No)
{
	// Implemente o seu metodo aqui!
}

TArvBin Inicializa()
{
	return NULL;
}

TArvBin Pesquisa(TArvBin No, TChave x)
{
	// Implemente o seu metodo aqui!
}

int Insere(TArvBin *pRaiz, TItem x)
{
	// Implemente o seu metodo aqui!
}

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
