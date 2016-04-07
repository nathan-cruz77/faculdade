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

#define SERVER_PORT 3000
#define KB *1024

ev_io* client_watcher;

typedef struct{
	char* server_ip;
	int server_port;
	ev_io* this_server;
} connection_data;


void make_non_blocking(int fd){

	fcntl(fd, F_SETFL, O_NONBLOCK);

}


void check_input(int size, char** args){

	if(size != 3){
		printf("[usage]: %s <ip> <port>\n\n", args[0]);
		printf("IP:\tIp of secure-chat server\n");
		printf("PORT:\tPort where the server will listen for connections\n");
		exit(EXIT_FAILURE);
	}

}


void client_set_addr(struct sockaddr_in* addr, char* ip, int port){

	addr->sin_family = AF_INET;
	addr->sin_port = htons(port);
	addr->sin_addr.s_addr = inet_addr(ip);

}


void server_set_addr(struct sockaddr_in* addr, int port){

	addr->sin_family = AF_INET;
	addr->sin_port = htons(port);
	addr->sin_addr.s_addr = INADDR_ANY;

}


int open_socket(char* ip, int port){

	int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in other_addr;

	client_set_addr(&other_addr, ip, port);
	connect(socket_fd, (struct sockaddr *) &other_addr, sizeof(struct sockaddr_in));

	make_non_blocking(socket_fd);

	return socket_fd;

}


int open_server_socket(int port){

	int server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	int SOCK_LEN = sizeof(struct sockaddr_in);

	struct sockaddr_in server_addr;
	server_set_addr(&server_addr, port);

	bind(server_fd, (struct sockaddr*) &server_addr, SOCK_LEN);

	make_non_blocking(server_fd);

	listen(server_fd, 1);

	printf("Waiting connections on: port 3000\n");
	fflush(stdout);

	return server_fd;

}


void client_callback(EV_P_ ev_io* watcher, int events){

	char* buffer = malloc(sizeof(char) * 64 KB);
	size_t amount_read = 0;
	size_t i = 0;

	if(events & EV_READ){
		amount_read = recv(watcher->fd, buffer, 64 KB, 0);

		printf("\r<<< ");
		for(i = 0; i < amount_read; i++)
			printf("%c", buffer[i]);
		printf("\n>>> ");
	}

	if(events & EV_WRITE){
		memset(buffer, 0, 64 KB);
		amount_read = read(0, (void*) buffer, 64 KB);

		if(amount_read >= 4){
			send(watcher->fd, buffer, amount_read, 0);
			printf("\n>>> ");
		}
	}

}


void accept_conn(EV_P_ ev_io* watcher, int events){

	printf("Callback\n");
	fflush(stdout);

	int server_fd = watcher->fd;

	client_watcher = malloc(sizeof(ev_io));

	struct sockaddr_in client_addr;
	int SOCK_LEN = sizeof(struct sockaddr_in);

	int client_fd = accept(server_fd, (struct sockaddr*) &client_addr,
						   &SOCK_LEN);

	make_non_blocking(client_fd);

	ev_io_init(client_watcher, client_callback, client_fd, EV_WRITE | EV_READ);
	ev_io_start(loop, client_watcher);

	ev_io_stop(EV_A_ watcher);
	ev_timer_stop(EV_A_ (ev_timer*) watcher->data);

	printf("Connected to %s:%d\n", inet_ntoa(client_addr.sin_addr),
			ntohs(client_addr.sin_port));
	fflush(stdout);

}


void connect_conn(EV_P_ ev_timer* watcher, int events){

	printf("Trie connect client\n");
	fflush(stdout);

	connection_data* connection_server = (connection_data*) watcher->data;

	int client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	make_non_blocking(client_fd);

	struct sockaddr_in server_addr;
	int result_connect;

	client_set_addr(&server_addr, connection_server->server_ip, connection_server->server_port);
	result_connect = connect(client_fd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in));

	if(result_connect < 0){
		printf("Unable to connect to %s:%d\n", connection_server->server_ip, connection_server->server_port);
	}
	else{
		client_watcher = malloc(sizeof(ev_io));

		printf("Connected as client!\n");

		ev_io_stop(EV_A_ connection_server->this_server);
		ev_timer_stop(EV_A_ watcher);

		ev_io_init(client_watcher, client_callback, client_fd, EV_WRITE | EV_READ);
		ev_io_start(loop, client_watcher);

		close(connection_server->this_server->fd);
	}
}


int main(int argc, char** argv){

	check_input(argc, argv);

	make_non_blocking(0);

	int server_fd;

	char* other_server_ip = argv[1];
	int other_server_port = atoi(argv[2]);

	server_fd = open_server_socket(SERVER_PORT);

	struct ev_loop* event_loop = EV_DEFAULT;

	ev_io server_watcher;
	ev_timer conector_watcher;

	server_watcher.data = (void*) &conector_watcher;

	ev_io_init(&server_watcher, accept_conn, server_fd, EV_READ);
	ev_io_start(event_loop, &server_watcher);

	connection_data connection;
	connection.server_ip = other_server_ip;
	connection.server_port = other_server_port;
	connection.this_server = &server_watcher;

	conector_watcher.data = (void*) &connection;

	ev_timer_init(&conector_watcher, connect_conn, 0.0, 1.0);
	ev_timer_start(event_loop, &conector_watcher);

	ev_run(event_loop, 0);

	return 0;

}
