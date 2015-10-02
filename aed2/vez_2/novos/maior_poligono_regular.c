#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int abs(int num){
    if(num >= 0) return num;
    return num * -1;
}

bool hash(bool* tabela, int posicao, int perimetro){
    int indice = ((posicao) % perimetro) -1;

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

int descobre_maior_lado(int* vet, int n, int p){
    int i, maior;

    maior = abs(vet[0] - vet[1]);
    for(i=1; i<n; i++){
        if(i == n-1){
            if(abs(vet[n-1] - (vet[0] + p)) > maior){
                maior = abs(vet[n-1] - (vet[0] + p));
            }
        }
        else if(abs(vet[i] - vet[i+1]) > maior){
            maior = abs(vet[i] - vet[i+1]);
        }
    }

    return maior;
}

void descobre_razao(int* vet, int p, int n, bool* tabela, int* ini_pt, int* razao){
    int r, i, j;
    int maior_lado = descobre_maior_lado(vet, n, p);
    //printf("%d\n", maior_lado);

    *razao = -1;
    *ini_pt = -1;

    for(i=0; i<n; i++){
        for(r=maior_lado; r<= p/3 && p%r == 0; r++){
            for(j=1; r*j < p && hash(tabela, vet[i] + r*j, p); j++);
            if(r*(j) >= p){
                // Completou a volta
                *razao = r;
                *ini_pt = vet[i];
                return;
            }
        }
    }
}

int main(){
    int* pontos;
    int n, p, r, i;
    bool* tabela;
    int ini_pt, razao;

    scanf("%d", &p);
    scanf("%d", &n);

    pontos = (int*) malloc((p)*sizeof(int));

    for(i=0; i<(n); i++){
        scanf("%d", &(pontos[i]));;
    }

    inicializa_tabela(&tabela, p, pontos, n);

    descobre_razao(pontos, p, n, tabela, &ini_pt, &razao);

    if(razao <= 0 || ini_pt < 0){
        printf("-1 -1");
    }
    else{
        printf("%d %d", razao, ini_pt);
    }

    return 0;
}
