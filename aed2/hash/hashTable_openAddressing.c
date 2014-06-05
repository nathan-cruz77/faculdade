#include <stdio.h>
#include <stdlib.h>

#define NIL -1

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem;

typedef int TIndice;

typedef struct {
	TItem *Item;
	TIndice m, n;
} THash;

TIndice h(THash *T, TChave k)
{
	return k % T->m;
}

TIndice H(THash *T, TChave k, int i)
{
  return (h(T, k) + i) % T->m;
}

THash *Inicializa(int m)
{
	TIndice i;
	THash *T;

	T = (THash *) malloc(sizeof(THash));

	T->n = 0; T->m = m;
	T->Item = (TItem *) malloc(T->m * sizeof(TItem));
	for (i = 0; i < T->m; i++)
		T->Item[i].Chave = NIL;

	return T;
}

TIndice Pesquisa(THash *T, TChave x){
	int i;
    TIndice aux = H(T, x, 0);

    for(i=1; i<(T->m) && T->Item[aux].Chave != x; i++){
        aux = H(T, x, i);
    }

    if(T->Item[aux].Chave == x) return aux;
    return NIL;
}

int Insere(THash *T, TItem x)
{
    int i;
    TIndice aux = H(T, x.Chave, 0);

    for(i=1;
		i<(T->m) && (T->Item[aux].Chave != NIL && T->Item[aux].Chave != x.Chave);
	   	i++){
        aux = H(T, x.Chave, i);
    }

	if(T->Item[aux].Chave == x.Chave)
		return 0;

    if(T->Item[aux].Chave == NIL){
        T->Item[aux] = x;
        T->n++;
        return 1;
    }
    return 0;
}

void Carrega(THash *T)
{
	int i, n;
	TItem x;

	scanf("%d", &n);
	for (i = 0; i < n ; i++) {
		scanf("%d", &x.Chave);
		Insere(T, x);
	}
}

void Libera(THash **T)
{
	THash *aux;
	int i;

	aux = *T;
	if (aux != NULL) {
		if (aux->Item != NULL) free(aux->Item);
		free(aux);
		(*T) = NULL;
	}
}

void Imprime(THash *T)
{
	int i;
	if (T->m > 0) {
		for (i = 0; i < T->m; i++)
			printf("[%d] %d\n", i, T->Item[i].Chave);
	}
}

int main()
{
    /* int i, j; */
	TIndice m;
	THash *T;
	TItem x;

	scanf("%d", &m);
	T = Inicializa(m);
	Carrega(T);
	scanf("%d", &x.Chave);
	if (Pesquisa(T, x.Chave) == NIL)
		Insere(T, x);
	Imprime(T);

	/* Utilizado para debugar o programa
    for(i=0; i<3; i++){
        scanf("%d", &j);
        printf("%d encontrado em T->Lista[%d]\n", j, Pesquisa(T, j));
    }*/

	Libera(&T);

	return 0;
}
