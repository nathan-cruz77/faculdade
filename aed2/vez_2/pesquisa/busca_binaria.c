#include <stdlib.h>
#include <stdio.h>

int busca(int* A, int esq, int dir, int x){
	int meio = (dir - esq)/2  + esq;

	if(dir < esq){
		return -1;
	}
	else if(dir == esq && A[esq] != x){
		return -1;
	}

	if(A[meio] > x){
		return busca(A, esq, )
	}
}

int main(){
	return 0;
}
