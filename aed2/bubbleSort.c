/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 17/03/14
 *  R.A.: 86492
 */


#include <stdio.h>
#include <stdlib.h>

void imprime(int *vet, int n){
    int i;

    for(i=0;i<n;i++) printf("%d ", vet[i]);
    printf("\n");
}

void bolha(int *vet, int n){
    int i, j, aux;

    for(i=n;i>0;i--){
        for(j=0;j<i;j++){
            if(vet[j+1] < vet[j]){
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main(){
    int tamanho, *vet, i;
    
    scanf("%d", &tamanho);
    vet = (int *) malloc(tamanho *(sizeof (int)));
    for(i=0;i<tamanho;i++){
            scanf("%d", &vet[i]);
    }
    imprime(vet, tamanho);
    bolha(vet, tamanho);
    imprime(vet, tamanho);
    return 0;
}
