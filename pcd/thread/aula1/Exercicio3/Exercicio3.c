#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 4
#define TAMANHO 10000.0

/* Matrizes de dados a serem somadas */
double** mat1;
double** mat2;

/* Matriz de saida */
double** mat3;

void* Trabalhadora(void* arg){
    int id = (int) arg;
    int i, coluna, j, linha;
    double linha_inicial;

    linha_inicial = TAMANHO/MAX_THREADS;

    printf("(Thread[%d]) Linha inicial = %.0lf\n", id, linha_inicial*id);
    printf("\tLinha final = %.0lf\n", (linha_inicial*id + linha_inicial));

    /* Soma e joga na matriz resultante */
    for(i=0, linha=(linha_inicial*id); i<linha_inicial; i++, linha++){
        for(coluna=0; coluna<TAMANHO; coluna++){
            mat3[linha][coluna] = mat1[linha][coluna] + mat2[linha][coluna];
        }
    }
}

void ImprimeMat(double** mat){
    int i, j;

    for(i=0; i<TAMANHO; i++){
        for(j=0; j<TAMANHO; j++){
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void PreencheMat(double** mat){
    int i, j;

    for(i=0; i<TAMANHO; i++){
        for(j=0; j<TAMANHO; j++){
            mat[i][j] = rand();
        }
    }

}

int main(){
    int id, i, j;
    pthread_t threads[MAX_THREADS];
    clock_t tempo;

    /* Aloca as matrizes */
    mat1 = (double**) malloc(sizeof(double*)*TAMANHO);
    mat2 = (double**) malloc(sizeof(double*)*TAMANHO);
    mat3 = (double**) malloc(sizeof(double*)*TAMANHO);

    for(i=0; i<TAMANHO; i++){
        mat1[i] = (double*) malloc(sizeof(double)*TAMANHO);
        mat2[i] = (double*) malloc(sizeof(double)*TAMANHO);
        mat3[i] = (double*) malloc(sizeof(double)*TAMANHO);
    }

    printf("Alocacao finalizada\n");

    /* Preenche aleatoriamente as matrizes */
    tempo = clock();
    srand(time(NULL));
    PreencheMat(mat1);
    srand(time(NULL)+32154);
    PreencheMat(mat2);
    tempo = clock() - tempo;
    printf("Tempo de preenchimento: %.3lfs\n", tempo);

    /* Dispara as threads */
    for(id=0; id<MAX_THREADS; id++){
        pthread_create(&threads[id], NULL, Trabalhadora, (void*)id);
    }

    /* Aguarda as threads finaizarem */
    for(id=0; id<MAX_THREADS; id++){
        pthread_join(threads[id], NULL);
    }

    /*
    ImprimeMat(mat1);
    ImprimeMat(mat2);
    ImprimeMat(mat3);
    */

    return 0;
}
