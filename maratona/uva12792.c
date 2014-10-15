#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isOrdenado(int* A, int N){
    int i;

    for(i=0; i<N-1; i++){
        if(A[i] > A[i+1]){
            return false;
        }
    }

    return true;
}

int* shuffle(int* A, int N){
    int B[N];
    int i, j;

    B[1] = A[0];
    for(i=1; i<=N/2; i++){
        B[i+2] = A[i];
    }

    for(i=N/2+1, j=0; i<N; i++, j+=2){
        B[j] = A[i];
    }

    for(i=0; i<N; i++){
        A[i] = B[i];
    }

    free(A);

    return B;
}

void generator(int* A, int N){
    int i;

    A = (int*) malloc(sizeof(int)*N);

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

int main(){
    int N, cont;
    int* A;

    while(scanf("%d", &N)){
        generator(A, N);
        //print_vec(A, N);
        A = shuffle(A, N);
        //print_vec(A, N);
        cont = 1;
        while(!isOrdenado(A, N)){
            A = shuffle(A, N);
            cont++;
        }
        free(A);
    }

    return 0;
}
