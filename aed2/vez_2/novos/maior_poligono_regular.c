#include <stdio.h>
#include <stdlib.h>

int hash(int k, int m){
	return k % m;
}

void carrega(int** pontos, int* n, int* r){
	int i;

	scanf("%d", r);
	scanf("%d", n);

	*pontos = malloc(sizeof(int) * (*r));

	for(i=0; i<(*n); i++){
		scanf("%d", &(*pontos[i]));
	}
}

int main(){
	int* pontos;
	int n, r;

	carrega(&pontos, &n, &r);

	return 0;
}
