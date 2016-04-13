#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define MAX_CONN 20
#define KB *1024

void set_addr(struct sockaddr_in *addr, int porta){

    addr->sin_family = AF_INET;
    addr->sin_port = htons(porta);
    addr->sin_addr.s_addr = INADDR_ANY;

}


void notifica_conn(struct sockaddr_in* cliente, bool abertura){

    if(abertura){
        fprintf(stderr, "Estabelecida conexao com %s:%d\n",
            inet_ntoa(cliente->sin_addr), ntohs(cliente->sin_port));
        return;
    }

    fprintf(stderr, "Terminada conexao com %s:%d\n",
            inet_ntoa(cliente->sin_addr), ntohs(cliente->sin_port));

}


size_t find_file_size(FILE* arq){

    size_t tamanho = 0;

    fseek(arq, 0, SEEK_END);
    tamanho = ftell(arq);
    rewind(arq);

    return tamanho;
}


void send_huge_file(int cliente, size_t* bytes_sent, char* arq_name){

    FILE* arq = fopen(arq_name, "rb");
    size_t file_size = 0;
    ssize_t aux = 0;
    char send_buff[64 KB];
    char* send_buff_aux;
    *bytes_sent = 0;

    if(arq == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", arq_name);
        exit(EXIT_FAILURE);
    }

    file_size = find_file_size(arq);

    while(fread(send_buff, sizeof(char), 64 KB, arq) == 64 KB){
        aux = send(cliente, send_buff, 64 KB, 0);

        if(aux > 0){
            *bytes_sent += aux;
        }
    }

    /* Send the chunk that could not be sent in a 64KB chunk */
    if(file_size % (64 KB) != 0){
        send_buff_aux = malloc(sizeof(char) * file_size % (64 KB));

        fread(send_buff_aux, sizeof(char), file_size % (64 KB), arq);
        aux = send(cliente, send_buff_aux, file_size % (64 KB), 0);

        if(aux > 0){
            *bytes_sent += aux;
        }

        free(send_buff_aux);
    }

    fclose(arq);

}


int main(int argc, char** argv){

    if(argc != 3){
        printf("[uso]: %s <porta> <arquivo>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int servidor_socket, cliente_socket;
    struct sockaddr_in servidor, cliente;
    int SOCK_LEN = sizeof(struct sockaddr_in);

    size_t bytes_enviados = 0;
    struct timeval tempo_ini;
    struct timeval tempo_fim;
    unsigned long int tempo_total = 0;

    size_t tamanho_arquivo = 0;

    servidor_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    set_addr(&servidor, atoi(argv[1]));

    bind(servidor_socket, (struct sockaddr*) &servidor,
         sizeof(struct sockaddr_in));

    listen(servidor_socket, 1024);
    printf("Esperando conexoes: localhost:%s\n", argv[1]);

    while(true){
        cliente_socket = accept(servidor_socket, (struct sockaddr*) &cliente,
                                (socklen_t*) &SOCK_LEN);
        notifica_conn(&cliente, true);

        gettimeofday(&tempo_ini, NULL);
        send_huge_file(cliente_socket, &bytes_enviados, argv[2]);
        gettimeofday(&tempo_fim, NULL);

        tempo_total = tempo_fim.tv_sec - tempo_ini.tv_sec;
        fprintf(stderr, "Vazao: %.3lfKB/s\n",
                (bytes_enviados/1024.0)/(float)tempo_total);

        close(cliente_socket);
        notifica_conn(&cliente, false);

    }

    close(servidor_socket);

}
