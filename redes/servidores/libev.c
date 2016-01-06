#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <ev.h>

#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <string.h>
#include <errno.h>


#define MAX_CONNS 1024
#define MAX_EVENTS 1024

#define END_TRANS 1
#define NOT_END_TRANS -1

#define KB *1024


const char* FILENAME;


struct connection_status {

	char* send_buff;
	char* send_buff_aux;

	FILE* file_fd;

	off_t bytes_sent;
	off_t file_size;

	int client_fd;

	struct sockaddr_in client_addr;

	struct timeval inicio;
	struct timeval fim;

};


ev_io* client_watcher;


void notify_conn(struct connection_status* conn, bool open_con){

	unsigned long int tempo_total = 0;

	if(open_con){
		fprintf(stderr, "Connected to %s:%d\n",
			inet_ntoa(conn->client_addr.sin_addr), ntohs(conn->client_addr.sin_port));

		return;
	}

	fprintf(stderr, "Disconnected from %s:%d\n",
			inet_ntoa(conn->client_addr.sin_addr), ntohs(conn->client_addr.sin_port));

	tempo_total = conn->fim.tv_sec - conn->inicio.tv_sec;
	fprintf(stderr, "\t%lld bytes sent in %ld seconds\n", conn->file_size, tempo_total);
	fprintf(stderr, "\tThroughput: %.3lfKB/s\n", (conn->bytes_sent /1024.0) / tempo_total);

}


void check_input(int size, char** args){

	if(size != 3){
		printf("[usage]: %s <port> <file>\n\n", args[0]);
		printf("PORT:\tPort where the server will listen for connections\n");
		printf("FILE:\tFile that will be served to clients\n");
		exit(EXIT_FAILURE);
	}

}


void make_non_blocking(int fd){

	fcntl(fd, F_SETFL, O_NONBLOCK);

}


void set_addr(struct sockaddr_in *addr, int server_port){

	addr->sin_family = AF_INET;
	addr->sin_port = htons(server_port);
	addr->sin_addr.s_addr = INADDR_ANY;

}


int open_server_socket(int server_port){

	int server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	int SOCK_LEN = sizeof(struct sockaddr_in);

	struct sockaddr_in server_addr;

	set_addr(&server_addr, server_port);
	bind(server_fd, (struct sockaddr*) &server_addr, SOCK_LEN);

	make_non_blocking(server_fd);

	listen(server_fd, MAX_CONNS);

	printf("Waiting connections on: %s:%d\n", "127.0.0.1", server_port);
	fflush(stdout);

	return server_fd;
}


off_t find_file_size(const char* filename){

	struct stat stat_thingy;

	stat(filename, &stat_thingy);
	return stat_thingy.st_size;

}


void initialize_conn_status(struct connection_status* conn, int client_fd,
							const char* filename, struct sockaddr_in client_addr){

	gettimeofday(&(conn->inicio), NULL);

	conn->send_buff = malloc(sizeof(char) * (64 KB));

	conn->file_fd = fopen(filename, "rb");
	conn->file_size = find_file_size(filename);

	conn->client_fd = client_fd;
	conn->client_addr = client_addr;

	conn->bytes_sent = 0;
	conn->send_buff_aux = NULL;

	notify_conn(conn, true);

}


void destroy_conn_status(struct connection_status* conn){

	gettimeofday(&(conn->fim), NULL);

	notify_conn(conn, false);

	close(conn->client_fd);

	free(conn->send_buff);
	free(conn->send_buff_aux);

	free(conn);

}



void write_chunk(EV_P_ ev_io* watcher, int revents){

	struct connection_status* conn = watcher->data;

	size_t amount_read;

	amount_read = fread(conn->send_buff, sizeof(char), 64 KB, conn->file_fd);

	/* Try to read 64KB chunck */
	if(amount_read == 64 KB){
		send(conn->client_fd, conn->send_buff, 64 KB, 0);
		conn->bytes_sent += 64 KB;
	}

	/* Unable to read 64KB, maybe there is a smaller chunck in the end */
	else if(conn->file_size % (64 KB) != 0){
		conn->send_buff_aux = malloc(sizeof(char) * (conn->file_size % (64 KB)));

		fread(conn->send_buff_aux, sizeof(char), conn->file_size % (64 KB), conn->file_fd);
		send(conn->client_fd, conn->send_buff_aux, conn->file_size % (64 KB), 0);

		conn->bytes_sent += (conn->file_size % (64 KB));
	}

	if(conn->bytes_sent == conn->file_size){
		destroy_conn_status(conn);
		ev_io_stop(EV_A_ watcher);
	}

}


void accept_conn(EV_P_ ev_io* watcher, int revents){

	int server_fd = watcher->fd;

	client_watcher = malloc(sizeof(ev_io));

	struct sockaddr_in client_addr;
	int SOCK_LEN = sizeof(struct sockaddr_in);

	int client_fd = accept(server_fd, (struct sockaddr*) &client_addr,
						   &SOCK_LEN);
	make_non_blocking(client_fd);

	struct connection_status* conn = malloc(sizeof(struct connection_status));
	initialize_conn_status(conn, client_fd, FILENAME, client_addr);

	client_watcher->data = conn;

	ev_io_init(client_watcher, write_chunk, client_fd, EV_WRITE);
	ev_io_start(loop, client_watcher);

}


int main(int argc, char** argv){

	int server_fd;
	int server_port = atoi(argv[1]);

	FILENAME = argv[2];

	int client_fd;
	struct sockaddr_in client_addr;

	int SOCK_LEN = sizeof(struct sockaddr_in);

	check_input(argc, argv);

	server_fd = open_server_socket(server_port);

	/* Libev stuff */
	struct ev_loop* event_loop = EV_DEFAULT;

	ev_io watcher;

	ev_io_init(&watcher, accept_conn, server_fd, EV_READ);
	ev_io_start(event_loop, &watcher);

	ev_run(event_loop, 0);

	return 0;
}
