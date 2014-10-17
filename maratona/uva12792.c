#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isOrdenado(int* A, int N){

    if(A[0] != 1){
        return false;
    }
    return true;
}

void generator(int* A, int N){
    int i;

    for(i=0; i<N; i++){
        A[i] = i+1;
    }
}

void print_vec(int* A, int N){
    int i;

    printf("\n");
    for(i=0; i<N; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void shuffle(int* A, int N, int cont){
    int B[N];
    int i, p;

    for(i=0, p=N/2; i<N; i+=2, p++){
        B[i] = A[p];
    }

    for(i=1, p=0; i<N; i+=2, p++){
        B[i] = A[p];
    }

    for(i=0; i<N; i++){
        A[i] = B[i];
    }
}

int main(){
    int N, cont, i;
    int* A;
    double tempo;

    A = (int*) malloc(sizeof(int)*100000);

    while(scanf("%d", &N)){
        generator(A, N);
        shuffle(A, N, 1);
        cont = 1;

        while(!isOrdenado(A, N)){
            shuffle(A, N, cont+1);
            cont++;
        }
        printf("%d\n", cont);

    }
    free(A);

    return 0;
}
