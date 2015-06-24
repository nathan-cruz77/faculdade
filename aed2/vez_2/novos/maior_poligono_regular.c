#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hash(int* pontos, bool* tabela, int i, int distancia, int perimetro){
	int indice = ((distancia + pontos[i]) % perimetro) - 1;

	if(tabela[indice]){
		return true;
	}
	else{
		return false;
	}
}

void inicializa_tabela(bool** tabela, int n, int* pontos, int np){
	int i;

	*tabela = malloc(sizeof(bool) * n);

	for(i=0; i<n; i++){
		(*tabela)[i] = false;
	}

	for(i=0; i<np; i++){
		(*tabela)[pontos[i]-1] = true;
	}
}

void carrega(int** pontos, int* n, int* p){
	int i;

	scanf("%d", p);
	scanf("%d", n);

	*pontos = malloc(sizeof(int) * (*p));

	for(i=0; i<(*n); i++){
		scanf("%d", &(*pontos[i]));
	}
}

void descobre_razao(int* vet, int p, int n, bool* tabela, int* ini_pt, int* razao){
	int r, i, j;
	
	*razao = -1;
	*ini_pt = -1;

	for(i=0; i<p; i++){
		for(r=1; r<= p/3; r++){
			for(j=1; j<=n && hash(vet, tabela, i, r*j, p); j++);
			if(j < n){
				*razao = r;
				*ini_pt = i;
				return;
			}
		}
	}
}

int main(){
	int* pontos;
	int n, p, r;
	bool* tabela;
	int ini_pt, razao;

	carrega(&pontos, &n, &p);
	inicializa_tabela(&tabela, p, pontos, n);

	descobre_razao(pontos, p, n, tabela, &ini_pt, &razao);

	printf("%d %d\n", ini_pt, razao);

	return 0;
}
