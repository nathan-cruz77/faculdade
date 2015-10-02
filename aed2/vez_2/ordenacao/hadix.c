#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef int TChave;

typedef struct{
    TChave Chave;
} TDado;

int numeroDigitos(TChave numero){
    return (int)ceil(log10(numero));
}

int retornaDigito(TChave numero, int indice){
    return (numero / (int)pow(10, indice)) % 10;
}

int maior_indice(TDado* vet, int n){
    int i, maior=0;

    for(i=1; i<n; i++){
        if(vet[i].Chave > vet[maior].Chave){
            maior = i;
        }
    }

    return maior;
}

void insertionSort(TDado* vet, int n, int d){
    int i, j;
    TDado aux, aux2;

    for(i=1; i<n; i++){
        aux = vet[i];

        for(j=i-1; j>=0; j--){
            if(retornaDigito(vet[j].Chave, d) > retornaDigito(aux.Chave, d)){
                vet[j+1] = vet[j];
                if(j == 0){
                    vet[j] = aux;
                    j = -1;
                }
            }
            else{
                vet[j+1] = aux;
                j = -1;
            }
        }
    }
}

void hadix(TDado* vet, int n){
    int i, q;
    q = numeroDigitos(vet[maior_indice(vet, n)].Chave);
    for(i=0; i<q; i++){
        insertionSort(vet, n, i);
    }
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

    hadix(vet, n);

    print_vet(vet, n);    

    return 0;
}
