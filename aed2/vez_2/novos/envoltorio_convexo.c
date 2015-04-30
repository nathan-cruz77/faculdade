///////////////////////////////////////////////////////////////////////////
// Envoltória convexa
// By: Nathan Cruz
// Template by: Jurandy Almeida
// Hu3Hu3Br
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////
// Structure para armazenar os pontos 2d
///////////////////////////////////////////////////////////////////////////
typedef struct
{
    int x;
    int y;
} ponto2D;

///////////////////////////////////////////////////////////////////////////
//    Prototipos das funcoes
///////////////////////////////////////////////////////////////////////////
void calculaEnvoltoria(ponto2D **pontos, int nPontos, ponto2D **envoltoria, int *nEnvoltoria);
double areaComSinal(ponto2D *p1, ponto2D *p2, ponto2D *p3);
void *mallocX(unsigned int nbytes);
void leCoordenadas(ponto2D **pontos, int *nPontos);
void escreveCoordenadas(ponto2D **pontos, int nPontos);
void ordenadaPorX(ponto2D *pontos, int n);
void print_vet(ponto2D* vet, int n);

///////////////////////////////////////////////////////////////////////////
// Funcao principal
///////////////////////////////////////////////////////////////////////////
int main()
{
    int nPontos, nEnvoltoria, i;
    ponto2D *pontos, *envoltoria;

    // Lendo a lista de coordenadas
    leCoordenadas(&pontos, &nPontos);

    // Ordenando a lista de coordenatas
    // sem esse passo, a funcao calculaEnvoltoria
    // nao retornara o resultado esperado
    ordenadaPorX(pontos, nPontos);

    /* Verifica se o metodo de ordenacao esta funcionando corretamente */
	//print_vet(pontos, nPontos);

    // Calculando a envoltoria convexa
    calculaEnvoltoria(&pontos, nPontos, &envoltoria, &nEnvoltoria);

    // Escrevendo a envoltoria convexa
    escreveCoordenadas(&envoltoria, nEnvoltoria - 1);

    free(pontos);
    free(envoltoria);

    return 0;
}


void print_vet(ponto2D* vet, int n){
	int i;

	for(i=0; i<n; i++){
		printf("%d ", vet[i].x);
	}
	printf("\n");
}

///////////////////////////////////////////////////////////////////////////
// IMPLEMENTE SEU ALGORITMO DE ORDENACAO AQUI
///////////////////////////////////////////////////////////////////////////

void ordenadaPorX (ponto2D *pontos, int nPontos){
	/* InsertionSort */

	int i, j;
	ponto2D aux;
	
	for(j=1; i<nPontos; i++){
		aux = pontos[j];
		for(i=j-1; i>=0; i--){
			if(pontos[i].x > aux.x){
				pontos[i+1] = pontos[i];
				if(i == 0){
					pontos[i] = aux;
					i=-1;
				}
			}
			else{
				pontos[i+1] = aux;
				i=-1;
			}
		}
	}
}

void adicionaPonto(ponto2D* vet, ponto2D x, int* i){
	(*i)++;
	vet[(*i)] = x;
}

void removePonto(ponto2D* vet, int* i){
	(*i)--;
}

///////////////////////////////////////////////////////////////////////////
// IMPLEMENTE O CALCULO DA ENVOLTORIA CONVEXA AQUI
///////////////////////////////////////////////////////////////////////////

void calculaEnvoltoria (ponto2D **pontos, int nPontos, ponto2D **envoltoria, int *nEnvoltoria)
{
    int i, t, k = -1;
    ponto2D *auxenvoltoria = malloc(sizeof(ponto2D) * nPontos);

	adicionaPonto(auxenvoltoria, *pontos[0], &k);

	for(i=1; i<nPontos; i++){

		while(k > 1 && areaComSinal(&(auxenvoltoria[k-1]), &(auxenvoltoria[k]), &(*pontos[i])) < 0){
			removePonto(auxenvoltoria, &k);
		}

		adicionaPonto(auxenvoltoria, *pontos[i], &k);
	}

	t = k+1;
	for(i=0; i<t; i++){
		*envoltoria[i] = auxenvoltoria[i];
	}

	k = -1;
	adicionaPonto(auxenvoltoria, *pontos[nPontos-2], &k);
	for(i=nPontos-3; i>=0; i--){

		while(k > 1 && areaComSinal(&(auxenvoltoria[k-1]), &(auxenvoltoria[k]), &(*pontos[i])) > 0){
			removePonto(auxenvoltoria, &k);
		}

		adicionaPonto(auxenvoltoria, *pontos[i], &k);
	}

	for(i=0; i<k+1; i++){
		*envoltoria[t+i] = auxenvoltoria[i];
	}

	*nEnvoltoria = t + i;
}


double areaComSinal (ponto2D *p1, ponto2D *p2, ponto2D *p3)
{
    return ((*p2).x - (*p1).x) * ((*p3).y - (*p1).y) -
                 ((*p2).y - (*p1).y) * ((*p3).x - (*p1).x);
}

///////////////////////////////////////////////////////////////////////////
// Auxiliary functions to read and write data
///////////////////////////////////////////////////////////////////////////

void *mallocX (unsigned int nbytes)
{
    void *ptr;
    ptr = malloc (nbytes);
    if (ptr == NULL)
    {
        printf ("Memoria insuficiente!\n");
        exit (EXIT_FAILURE);
    }
    return ptr;
}

void leCoordenadas (ponto2D **pontos, int *nPontos)
{
    int i;

    scanf ("%d", nPontos);
    (*pontos) = (ponto2D*) mallocX ((*nPontos) * sizeof (ponto2D));

    for (i = 0; i < (*nPontos); i++)
        scanf ("%d %d", &(*pontos)[i].x, &(*pontos)[i].y);

}

void escreveCoordenadas (ponto2D **pontos, int nPontos)
{
    int i;

    for (i = 0; i < nPontos; i++)
        printf ("%d %d \n", (*pontos)[i].x, (*pontos)[i].y);

}

