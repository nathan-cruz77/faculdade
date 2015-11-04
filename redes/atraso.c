#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


/* Estrutura de dados para representar o enlace */
typedef struct{

    /* Capacidade do enlace em Mb/s */
    double capacidade;

    /* Velocidade de propagacao em m/s */
    double velocidade_propagacao;

    /* Distancia em metros entre os elementos
     * nas "pontas" do enlace */
    double distancia;

} Enlace;


/* Estrutura de dados para representar os roteadores */
typedef struct{

    /* Tamanhos das filas da interface A em bytes */
    size_t ethA_in;
    size_t ethA_out;

    /* Tamanhos das filas da interface B em bytes */
    size_t ethB_in;
    size_t ethB_out;

    /* Tamanho maximo das filas em bytes */
    size_t max;

    /* Tempo de processamento de cada pacote */
    double tempo_proc;

} Roteador;


/* Define o tipo string */
typedef const char* string;


/* Tamanho do pacote a ser definido (em bytes) */
double L;

/* Pacotes por segundo */
double alfa;


/* Tenta abrir o arquivo especificado */
FILE* my_open(string arq){

    FILE* file_desc = fopen(arq, "r");

    if(file_desc == NULL){
        printf("Erro ao abrir o arquivo %s\n", arq);
        exit(EXIT_FAILURE);
    }
    else{
        return file_desc;
    }
}

void le_entrada(char** args, Enlace** v_enlace, int* N_enlace,
                Roteador** v_roteador, int* N_roteador){
    int quantidade_roteadores, quantidade_enlaces;
    int tamanho_filas;
    int i, j, cont = 1;

    double capacidade, velocidade_propagacao, tempo_processamento;
    double distancia;

	L =  (double) strtod(args[cont], (char**) NULL);
    cont++;
	alfa =  (double) strtod(args[cont], (char**) NULL);
    cont++;

    quantidade_roteadores = atoi(args[cont]);
    cont++;
    quantidade_enlaces = quantidade_roteadores + 1;
    *N_roteador = quantidade_roteadores;
    *N_enlace = quantidade_enlaces;

    (*v_roteador) = malloc(sizeof(Roteador) * quantidade_roteadores);
    (*v_enlace) = malloc(sizeof(Enlace) * quantidade_enlaces);

    /* Preenche o vetor de roteadores */
    for(i=0; i<quantidade_roteadores; i++){
        tamanho_filas = (int) strtol(args[cont], (char**) NULL, 10);
        cont++;
        tempo_processamento = (double) strtod(args[cont], (char**) NULL);
        cont++;

        /* Define os valores do roteador "atual" de acordo
         * com os parametros lidos */
        (*v_roteador)[i].max = tamanho_filas;
        (*v_roteador)[i].tempo_proc = tempo_processamento;

        /* Ajusta as filas para comecarem vazias */
        (*v_roteador)[i].ethA_in = 0;
        (*v_roteador)[i].ethA_out = 0;
        (*v_roteador)[i].ethB_in = 0;
        (*v_roteador)[i].ethB_out = 0;
    }

    /* Preenche o vetor de enlaces */
    for(j=0; j<quantidade_enlaces; j++){
        capacidade = (double) strtod(args[cont], (char**) NULL);
        cont++;
        velocidade_propagacao = (double) strtod(args[cont], (char**) NULL);
        cont++;
        distancia = (double) strtod(args[cont], (char**) NULL);
        cont++;

        /* Define os valores do enlace atual de acordo
         * com os parametros lidos */
        (*v_enlace)[j].capacidade = capacidade;
        (*v_enlace)[j].velocidade_propagacao = velocidade_propagacao;
        (*v_enlace)[j].distancia = distancia;
    }
}

/* Extrai os dados do arquivo de entrada */
void carrega_entrada(FILE* entrada,
                     Enlace** v_enlace, int* N_enlace,
                     Roteador** v_roteador, int* N_roteador){

    int quantidade_roteadores, quantidade_enlaces;
    int tamanho_filas;
    int i;

    double capacidade, velocidade_propagacao, tempo_processamento;
    double distancia;

    fscanf(entrada, "%lf", &L);
	fscanf(entrada, "%lf", &alfa);

    fscanf(entrada, "%d", &quantidade_roteadores);
    quantidade_enlaces = quantidade_roteadores + 1;
    *N_roteador = quantidade_roteadores;
    *N_enlace = quantidade_enlaces;

    (*v_roteador) = malloc(sizeof(Roteador) * quantidade_roteadores);
    (*v_enlace) = malloc(sizeof(Enlace) * quantidade_enlaces);

    /* Preenche o vetor de roteadores */
    for(i=0; i<quantidade_roteadores; i++){
        fscanf(entrada, "%d", &tamanho_filas);
        fscanf(entrada, "%lf", &tempo_processamento);

        /* Define os valores do roteador "atual" de acordo
         * com os parametros lidos */
        (*v_roteador)[i].max = tamanho_filas;
        (*v_roteador)[i].tempo_proc = tempo_processamento;

        /* Ajusta as filas para comecarem vazias */
        (*v_roteador)[i].ethA_in = 0;
        (*v_roteador)[i].ethA_out = 0;
        (*v_roteador)[i].ethB_in = 0;
        (*v_roteador)[i].ethB_out = 0;
    }

    /* Preenche o vetor de enlaces */
    for(i=0; i<quantidade_enlaces; i++){
        fscanf(entrada, "%lf", &capacidade);
        fscanf(entrada, "%lf", &velocidade_propagacao);
        fscanf(entrada, "%lf", &distancia);

        /* Define os valores do enlace atual de acordo
         * com os parametros lidos */
        (*v_enlace)[i].capacidade = capacidade;
        (*v_enlace)[i].velocidade_propagacao = velocidade_propagacao;
        (*v_enlace)[i].distancia = distancia;
    }
}


/* Calcula o atraso total */
double calcula_atraso(Enlace* v_enlace, int N_enlace,
                      Roteador* v_roteador, int N_roteador){

    double atraso_transmissao = 0;
    double atraso_processamento = 0;
    double atraso_fila = 0;
    double atraso_propagacao = 0;
    double atraso_total = 0;

    int quantidade_segmentos = ceil(L/1500.);
    int i, j;

	for(i=0; i<N_enlace; i++){
		atraso_transmissao += quantidade_segmentos *
			((1500*8)/(v_enlace[i].capacidade*1000000));

        atraso_propagacao += quantidade_segmentos *
            ((1500*8) * v_enlace[i].distancia / v_enlace[i].velocidade_propagacao);

		/* Calcula o atraso de fila */
		for(j=1; j<=quantidade_segmentos; j++){
			atraso_fila += (j - 1) * ((1500*8*alfa)/(v_enlace[i].capacidade*1000000));
		}
    }

    for(i=0; i<N_roteador; i++){
        atraso_processamento += v_roteador[i].tempo_proc;
    }

    atraso_total = atraso_transmissao + atraso_processamento +
                   atraso_fila + atraso_propagacao;
    return atraso_total;
}


int main(int* len_args, char** args){

    Enlace* v_enlace;
    Roteador* v_roteador;
    FILE* entrada;
    int N_enlace, N_roteador;
    double total;

    entrada = stdin;

    le_entrada(args, &v_enlace, &N_enlace, &v_roteador, &N_roteador);

    /* Extrai dados da entrada padrao ou do arquivo especificado */
    //carrega_entrada(entrada, &v_enlace, &N_enlace, &v_roteador, &N_roteador);

    /* Calcula atraso total (fim a fim) */
    total = calcula_atraso(v_enlace, N_enlace, v_roteador, N_roteador);

    printf(" %.4lf", total);

    return 0;
}
