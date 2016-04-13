#include <stdlib.h>
#include <stdio.h>

int busca(int* A, int esq, int dir, int x){
    int meio = (dir - esq)/2  + esq;

    if(dir < esq){
        return -1;
    }

	if(dir == esq && A[esq] != x){
        return -1;
    }

    if(A[meio] > x){
        return busca(A, esq, meio, x);
    }

	if(A[meio] < x){
		return busca(A, meio+1, dir, x);
	}

	return meio;
}

int main(){

	int* A;
	int n;
	int i;

	scanf("%d", &n);

	A = malloc(sizeof(int) * n);

	for(i = 0; i < n; i++){
		scanf("%d", &(A[i]));
	}

	scanf("%d", &i);

	printf("Busca binaria: %d\n", busca(A, 0, n - 1, i));

    return 0;
}
