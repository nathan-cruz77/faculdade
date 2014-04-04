#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem;

typedef int TIndice;

typedef struct {
	TItem *Item;
	TIndice n, max;
} TTabela;


/* Inicio da implementação do quicksort */
int quickSort_particao(TItem *A, int p, int r){
    int i, j;
    TItem aux, pivo;
    
    i=p-1;
    pivo = A[r];

    for(j=p; j<r; j++){
        if(A[j].Chave <= pivo.Chave){
            i += 1;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    
    aux = A[i+1];
    A[i+1] = pivo;
    A[r] = aux;

    return i+1;
}

void quickSort_ordena(TItem *A, int p, int r){
    int i;
    
    if(p >= r) return;
    i = quickSort_particao(A, p, r);
    quickSort_ordena(A, i+1, r);
    quickSort_ordena(A, p, i-1);
}

void quickSort(TItem *A, int n){
    quickSort_ordena(A, 0, n-1);
}
/* Fim da implementação do quicksort */


/* Algoritmo de ordenação */
void insertionSort(TItem *A, int n) {
    int i, j;
    TItem aux;

    for(i=1;i<n;i++){
        aux = A[i];
        j = i-1;
        while(j>=0 && aux.Chave < A[j].Chave){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = aux;
    }
}

/* inicializa uma tabela */
TTabela *Inicializa()
{
	TTabela *T;
	T = (TTabela *) malloc(sizeof(TTabela));
	T->n = 0;
	T->max = 10;
	T->Item = (TItem *) malloc(T->max * sizeof(TItem));
	return T;
}

/* encontra e retorna o indice da chave x na tabela */
TIndice Pesquisa(TTabela *T, TChave x)
{
    quickSort(T->Item, T->n);
    return Binaria(T, 0, T->n, x);
}

/* insere um registro na tabela */
void Insere(TTabela *T, TItem x) {
    if(T->n <= T->max-1){
        T->Item[T->n] = x;
        T->n += 1;
    }
    else if(T->n >= T->max){
        T->max += 1;
        T->Item = (TItem *) realloc(T->Item, T->max * sizeof(TItem));
        T->Item[T->n] = x;
        T->n += 1;
    }
}
void Carrega(TTabela *T)
{
	int i, n;
	TItem x;

	scanf("%d", &n);
	for (i = 0; i < n ; i++) {
		scanf("%d", &x.Chave);
		Insere(T, x);
	}
}

void Libera(TTabela **T)
{
	TTabela *aux;

	aux = *T;
	if (aux != NULL) {
		if (aux->Item != NULL) free(aux->Item);
		free(aux);
		(*T) = NULL;
	}
}

void Imprime(TTabela *T)
{
	int i;
	if (T->n > 0) {
		printf("%d", T->Item[0].Chave);
		for (i = 1; i < T->n; i++)
			printf(" %d", T->Item[i].Chave);
		printf("\n");
	}
}

TIndice Binaria(TTabela *T, TIndice esq, TIndice dir, TChave x) {
    TIndice meio;

    meio = (esq + dir) / 2;
    
    if(T->Item[meio].Chave == x) return meio;
    if(T->Item[meio].Chave > x) return Binaria(T, esq, meio, x);
    if(T->Item[meio].Chave < x) return Binaria(T, meio, dir, x);
    return -1;
}

int main()
{
	TTabela *T;
	TIndice i;
	TChave x;

	T = Inicializa();
	Carrega(T);
	scanf("%d", &x);
	i = Pesquisa(T, x);
    //Imprime(T);
	printf("%d\n", i);
	Libera(&T);

	return 0;
}
