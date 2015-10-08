#include <stdlib.h>
#include <stdio.h>


/* Estrutura de dados para representar o enlace */
typedef struct{

	/* Capacidade do enlace */
	double r;

	/* Velocidade de propagacao em m/s */
	double velocidade_propagacao;

	/* Distancia em metros entre os elementos
	 * nas "pontas" do enlace */
	double distancia;

} Enlace;


/* Estrutura de dados para representar os roteadores */
typedef struct{

	/* Tamanhos das filas em bytes */
	size_t in;
	size_t out;

	/* Tempo de processamento de cada pacote */
	double tempo_proc;

} Roteador;


/* Define o tipo string */
typedef const char* string;


char* read_line(FILE* arq_d){
	char* 
}

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
void carrega_entrada(string arq_entrada,
					 Enlace* v_enlace, Roteador* v_roteador){

	FILE* arq_entrada_d = my_open(arq_entrada);


}

int main(int* len_args, char** args){

	/* Nome do arquivo de entrada
	 * DEVE ser o primeiro a ser passado */
	string arq_entrada = args[1];

	/* Extrai dados da entrada padrao ou do arquivo especificado */
	Enlace* v_enlace = NULL;
	Roteador* v_roteador = NULL;

	carrega_entrada(arq_entrada);

	return 0;
}
