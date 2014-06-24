#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int Chave;
} TItem;

typedef TItem* PItem;

PItem Gerador(int n){
    PItem A;
    int i;

    if(n > 0){
        A = (PItem) malloc(n * sizeof(TItem));

        srand(time(NULL));
        for (i = 0; i < n ; i++)
            A[i].Chave = rand() % 1000 +1;

        return A;
    }
    else
        return NULL;

}

void Libera(TItem **A)
{
	if ((*A) != NULL) {
		free(*A);
		(*A) = NULL;
	}
}
void Imprime(TItem *A, int n, int pid)
{
	int i;
	if(pid==0){
		FILE *arquivo;
		arquivo = fopen("saida2.txt","w");
		for (i = 0; i < (n/2); i++)
		fprintf(arquivo," %d", A[i].Chave);printf("\n");
		fclose(arquivo);
	}
	else{
		FILE *arquivo1;
		arquivo1 = fopen("saida1.txt","w");
		for (i = (n/2); i < n; i++){
			fprintf(arquivo1," %d", A[i].Chave);
		}
		fclose(arquivo1);
	}
}

void mergeSort_intercala ( TItem *v, int esq, int meio, int dir){
	int i, j, k;
	int a_tam = meio-esq+1;
	int b_tam = dir-meio;
	TItem *a = (TItem*) malloc(sizeof(TItem) * a_tam);
	TItem *b = (TItem*) malloc(sizeof(TItem) * b_tam);
	for(i = 0; i < a_tam; i++) a[i] = v[i+esq];
	for(i = 0; i < b_tam; i++) b[i] = v[i+meio+1];
	for(i = 0, j = 0, k = esq; k <= dir; k++){
		if( i == a_tam) v[k] = b[j++];
		else if (j == b_tam) v[k] = a[i++];
		else if (a[i].Chave < b[j].Chave) v[k] = a[i++];
		else v[k] = b[j++];
	}
	free(a);
	free(b);
}
void mergeSort_ordena(TItem *A, int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		mergeSort_ordena(A, p, q);
		mergeSort_ordena(A, q+1, r);
		mergeSort_intercala(A, p, q, r);
	}
}
void mergeSort(TItem *A, int n, int pid)
{
	if(pid == 0){
		mergeSort_ordena(A, 0, n/2-1);
	}
	else{
		mergeSort_ordena(A, (n/2), n-1);
	}
}
int main()
{
	TItem *A;
	int n;
    time_t tempo;
    double tempo_usado;

    printf("Entre com o tamanho do vetor a ordenar: ");
    scanf("%d", &n);
	A = Gerador(n);
	int pid = fork();

    tempo = clock();
	mergeSort(A, n, pid);
    tempo = clock() - tempo;
    tempo_usado = (double) tempo/CLOCKS_PER_SEC;
    printf("Tempo gasto na primeira metade: %.14lf\n", tempo_usado);

	//Imprime(A, n, pid);
	Libera(&A);
	return 0;
}
