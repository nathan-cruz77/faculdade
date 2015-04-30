#include <stdlib.h>
#include <stdio.h>

int busca(int* vet, int n, int x){
	int i, j;

	for(i=0, j=-1; i<n; i++){
		if(vet[i] == x){
			j = i;
			return j;
		}
	}

	return j;
}

void carrega(int** vet, int* n){
	int i;	

	scanf("%d", n);

	(*vet) = (int*) malloc(sizeof(int) * (*n));

	for(i=0; i<(*n); i++){
		scanf("%d", &(*vet)[i]);
	}
}

int main(){
	int* A;
	int n, x;

	carrega(&A, &n);

	scanf("%d", &x);
	printf("%d\n", busca(A, n, x));

	return 0;
}
