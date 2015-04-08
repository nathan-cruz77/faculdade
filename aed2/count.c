#include <stdlib.h>
#include <stdio.h>

typedef int TChave;

typedef struct{
	TChave Chave;
} TDado;

int tiraMaior(TDado* vet, int n){
	int maior = vet[0].Chave;
	int i;

	for(i=1; i<n; i++){
		if(vet[i].Chave > maior){
			maior = vet[i].Chave;
		}
	}

	return maior;
}

void print_vet(TDado* vet, int n){
	int i;

	for(i=0; i<n; i++){
		printf("%d ", vet[i].Chave);
	}

	printf("\n");
}

void print_vet_i(int* vet, int n){
	int i;

	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}

	printf("\n");
}


void count(TDado* vet, int n){
	int i;
	int aux = tiraMaior(vet, n);
	TDado* B = (TDado*) malloc(sizeof(TDado) * n);
	int* C = (int*) malloc(sizeof(int) * (aux +1));

	for(i=0; i<aux; i++){
		C[i] = 0;
	}

	for(i=0; i<n; i++){
		C[vet[i].Chave]++;
	}

	for(i=0; i<aux; i++){
		C[i+1] += C[i];
	}

	for(i=n-1; i>=0; i--){
		C[vet[i].Chave]--;
		B[C[vet[i].Chave]] = vet[i];
	}

	for(i=0; i<n; i++){
		vet[i] = B[i];
	}
}

int main(){
	int n, i;
	TDado* vet;
	
	scanf("%d", &n);
	vet = (TDado*) malloc(sizeof(TDado) * n);

	for(i=0; i<n; i++){
		scanf("%d", &vet[i].Chave);
	}

	count(vet, n);
	print_vet(vet, n);

	return 0;
}
