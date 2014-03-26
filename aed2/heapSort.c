#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem; 

int Carrega(TItem **A)
{
	int i, n;
	
	scanf("%d", &n);
	
	if (n > 0) {
		(*A) = (TItem *) malloc(n * sizeof(TItem));
		for (i = 0; i < n ; i++)
			scanf("%d", &(*A)[i].Chave);
	}
	else
		(*A) = NULL;

	return n;
}

void Libera(TItem **A)
{
	if ((*A) != NULL) {
		free(*A);
		(*A) = NULL;
	}
}

void Imprime(TItem *A, int n)
{
	int i;
	if (n > 0) {
		printf("%d", A[0].Chave);
		for (i = 1; i < n; i++)
			printf(" %d", A[i].Chave);
		printf("\n");
	}
}

void heapRefaz(TItem *A, int esq, int dir)
{ 
	TItem aux;
	int i, j;
			
	i = esq;
	j = i * 2 + 1;
	aux = A[i];
	
	while (j <=dir)
	{
		if ((j < dir) && (A[j].Chave < A[j+1].Chave))
			j++;
		if (aux.Chave >= A[j].Chave)
			break;
		A[i] = A[j];
		i = j;
		j = i * 2 + 1;
	}
	A[i] = aux;
}

void heapConstroi(TItem *A, int n)
{ 
	int esq;
	esq = (n / 2) - 1;
	
	while (esq >= 0)
	{
		heapRefaz(A, esq, n-1);
		esq--;
	}	
}

void heapSort(TItem *A, int n)
{ 
	TItem aux;
	int m;
	
	heapConstroi(A, n);
	
	m = n - 1;
	
	while(m > 0)
	{
		aux = A[m];
		A[m] = A[0];
		A[0] = aux;
		m = m - 1;	
		heapRefaz(A, 0, m);
	}
}

int main()
{
	TItem *A;
	int n;

	n = Carrega(&A);
	heapRefaz(A, 0, n-1);
	//Imprime(A, n);
	heapConstroi(A, n);
	//Imprime(A, n);	
	heapSort(A, n);
	Imprime(A, n);
	Libera(&A);
		
	return 0;
}
