#include <stdlib.h>
#include <stdio.h>

typedef int TChave;

typedef struct{
    TChave Chave;
} TDado;

int particiona(TDado* vet, int p, int r){
    int i, j;
    TDado pivo = vet[r];
    TDado aux;

    for(j=p, i=p-1; j<r; j++){
        if(vet[j].Chave < pivo.Chave){
            i++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }

    i++;
    aux = vet[i];
    vet[i] = vet[r];
    vet[r] = aux;

    return i;
}

void quicksort_ordena(TDado* vet, int p, int r){
    int q;

    if(r > p){
        q = particiona(vet, p, r);
        quicksort_ordena(vet, p, q-1);
        quicksort_ordena(vet, q+1, r);
    }
}

void quicksort(TDado* vet, int n){
    quicksort_ordena(vet, 0, n-1);    
}

void print_vet(TDado* vet, int n){
    int i;

    for(i=0; i<n; i++){
        printf("%d ", vet[i].Chave);
    }

    printf("\n");
}

int main(){
    int n, i;
    TDado* vet;

    scanf("%d", &n);

    vet = (TDado*) malloc(sizeof(TDado) * n);

    for(i=0; i<n; i++){
        scanf("%d", &vet[i].Chave);
    }

    particiona(vet, 0, n-1);
    print_vet(vet, n);

    quicksort(vet, n);

    print_vet(vet, n);

    return 0;
}
