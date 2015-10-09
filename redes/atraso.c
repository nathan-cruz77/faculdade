#include <stdlib.h>
#include <stdio.h>


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

/* Extrai os dados do arquivo de entrada */
void carrega_entrada(FILE* entrada, Enlace* v_enlace, Roteador* v_roteador){

	int quantidade_roteadores, quantidade_enlaces;
	int tamanho_filas, tempo_processamento;
	int i;

	double capacidade, velocidade_propagacao;
	double distancia;

	fscanf(entrada, "%d", &quantidade_roteadores);
	quantidade_enlaces = quantidade_roteadores + 1;

	v_roteador = malloc(sizeof(Roteador) * quantidade_roteadores);
	v_enlace = malloc(sizeof(Enlace) * quantidade_enlaces);

	/* Preenche o vetor de roteadores */
	for(i=0; i<quantidade_roteadores; i++){
		fscanf(entrada, "%d", tamanho_filas);
		fscanf(entrada, "%d", tempo_processamento);

		/* Define os valores do roteador "atual" de acordo
		 * com os parametros lidos */
		v_roteador[i].max = tamanho_filas;
		v_roteador[i].tempo_proc = tempo_processamento;

		/* Ajusta as filas para comecarem vazias */
		v_roteador[i].ethA_in = 0;
		v_roteador[i].ethA_out = 0;
		v_roteador[i].ethB_in = 0;
		v_roteador[i].ethB_out = 0;
	}

	/* Preenche o vetor de enlaces */
	for(i=0; i<quantidade_enlaces; i++){
		fscanf(entrada, "%lf", &capacidade);
		fscanf(entrada, "%lf", &velocidade_propagacao);
		fscanf(entrada, "%lf", &distancia);

		/* Define os valores do enlace atual de acordo
		 * com os parametros lidos */
		v_enlace[i].capacidade = capacidade;
		v_enlace[i].velocidade_propagacao = velocidade_propagacao;
		v_enlace[i].distancia = distancia;
	}
}


int main(int* len_args, char** args){

	Enlace* v_enlace = NULL;
    Roteador* v_roteador = NULL;
	FILE* entrada;

	printf("len_args = %d\n", *len_args);
	if(*len_args >= 1){
		entrada = my_open(args[1]);
	}
	else{
		entrada = stdin;
	}

    /* Extrai dados da entrada padrao ou do arquivo especificado */
    carrega_entrada(entrada, v_enlace, v_roteador);

	/* Calcula atraso total (fim a fim) */
	calcula_atraso(v_enlace, N_enlace, v_roteador, N_roteador);

    return 0;
}
