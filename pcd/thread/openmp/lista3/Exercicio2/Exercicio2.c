#include <stdio.h>
#include <omp.h>

/* Constantes */
#define N 100000000
#define u 987.0

int main(void) {
    double passo, soma,x;
    int i;

    passo = (u-1) / N;

    soma = 0;
    #pragma omp parallel shared(passo) private(x, i) reduction(+:soma)
    {
        #pragma omp for
        for (i=0; i<N;i++){
            x=1+i*passo;
            soma += 0.5*(1/x+1/(x+passo));
        }
    }
    printf("ln %f = %20.15f\n", u, passo*soma);

    return 0;
}
