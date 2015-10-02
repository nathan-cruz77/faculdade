#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct{
    TChave Chave;
} TDado;

typedef TDado* PDado;

void print_vet(PDado* vet, int n){
    int i;
    for(i=0; i<n; i++){
            printf("%d ", vet[i]->Chave);
    }
    printf("\n");
}

void insertionSort(PDado* vet, int n){
    int i, j;
    PDado aux, aux2;

    for(i=1; i<n; i++){
        aux = vet[i];

        for(j=i-1; j>=0; j--){
            if(vet[j]->Chave > aux->Chave){
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
        print_vet(vet, n);
    }
}

int menor_indice(PDado* vet, int start, int end){
    int i, menor=start;

    for(i=start; i<end; i++){
        if(vet[i]->Chave < vet[menor]->Chave){
            menor = i;
        }
    }

    return menor;
}

void selectionSort(PDado* vet, int n){
    int i, menor;
    PDado aux;

    for(i=0; i<n-1; i++){
        menor = menor_indice(vet, i, n);
        if(menor > i){
            aux = vet[menor];
            vet[menor] = vet[i];
            vet[i] = aux;
        }
        print_vet(vet, n);
    }
}

void bubbleSort(PDado* vet, int n){
    int i, j;
    PDado aux;

    for(i=n; i>0; i--){
        for(j=0; j<i-1; j++){
            if(vet[j+1]->Chave < vet[j]->Chave){
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
            }
        }
        print_vet(vet, n);
    }
}

int main(){
    int n, i;
    PDado* vet;
    
    scanf("%d", &n);

    vet = (PDado*) malloc(sizeof(PDado) * n);

    for(i=0; i<n; i++){
        vet[i] = (PDado) malloc(sizeof(TDado));
        scanf("%d", &(vet[i]->Chave));
    }

    print_vet(vet, n);

    //insertionSort(vet, n);
    selectionSort(vet, n);
    //bubbleSort(vet, n);

    return 0;
}
