#include <iostream>
#include <vector>
#include <cstdlib>

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

#include "rc4.h"
#include "sdes.h"
#include "rsa.h"

#define SERVER_PORT 3000
#define KB *1024

using namespace std;

ev_io* client_watcher;

char* buffer_send;
char* buffer_recv;

string key;
bool use_rc4;
vector<int> close_me;

typedef struct{

    char* server_ip;
    int server_port;
    int client_fd;

} connection_data;


void fecha_server(int sig){

    /* Fecha todas as conexoes */
    for(int i = 0; i < close_me.size(); i++){
        close(close_me[i]);
    }

    cout << "\rReceived SIGINT. Exiting." << endl;
    exit(EXIT_SUCCESS);

}


void make_non_blocking(int fd){

    fcntl(fd, F_SETFL, O_NONBLOCK);

}


bool check_input(int size, char** args){

    bool server_mode;

    if(size != 3 && size != 1){
        printf("[usage]: %s <ip> <port> <encryption>\t// Client mode\n", args[0]);
        printf("         OR\n");
        printf("         %s <encryption>\t\t// Server mode\n\n", args[0]);
        printf("IP:\tIp of secure-chat server\n");
        printf("PORT:\tPort of secure-chat server\n");

        // Only rc4 encryption is supported
        //printf("Encryption:\tEncryption algorithm to use, may be \"--rc4\" or \"--sdes\"\n");

        exit(EXIT_FAILURE);
    }

    if(size == 3){
        printf("Initializing client mode.\n");
        server_mode = false;

        /*
        if(args[3] == "--rc4")
            use_rc4 = true;
        else
            use_rc4 = false;
        */

    }

    if(size == 1){
        printf("Initializing server mode\n");
        server_mode = true;

        /*
        if(args[1] == "--rc4")
            use_rc4 = true;
        else
            use_rc4 = false;
        */

    }

    use_rc4 = true;

    return server_mode;

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

    close_me.push_back(socket_fd);

    return socket_fd;

}


int open_server_socket(int port){

    int server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int SOCK_LEN = sizeof(struct sockaddr_in);

    struct sockaddr_in server_addr;
    server_set_addr(&server_addr, port);

    if(bind(server_fd, (struct sockaddr*) &server_addr, SOCK_LEN) < 0){
        cout << "Unable to bind" << endl;
        exit(EXIT_FAILURE);
    }

    make_non_blocking(server_fd);

    listen(server_fd, 1);

    printf("Waiting connections on: port 3000\n");
    fflush(stdout);

    close_me.push_back(server_fd);

    return server_fd;

}


void client_callback(EV_P_ ev_io* watcher, int events){

    size_t amount_read = 0;
    size_t i = 0;

    if(events & EV_READ){
        memset(buffer_recv, 0, 64 KB);

        amount_read = recv(watcher->fd, buffer_recv, 64 KB, 0);

        if(amount_read <= 0)
            return;

        printf("\r<<< ");
        if(use_rc4)
            cout << rc4(key, string(buffer_recv)).c_str();
        else
            cout << decifra(string(buffer_recv), key).c_str();
        printf("\n\n>>> ");
    }

    if(events & EV_WRITE){
        memset(buffer_send, 0, 64 KB);
        fgets(buffer_send, 64 KB, stdin);

        string aux(buffer_send);
        if(use_rc4)
            aux = rc4(key, aux);
        else
            aux = cifra(aux, key);

        amount_read = strlen(buffer_send);

        for(i = 0; i < amount_read; i++){
            buffer_send[i] = aux.c_str()[i];
        }

        if(amount_read > 0){
            send(watcher->fd, buffer_send, amount_read, 0);
            printf("\n>>> ");
        }
    }

}


void accept_conn(EV_P_ ev_io* watcher, int events){

    int server_fd = watcher->fd;

    client_watcher = (ev_io*) malloc(sizeof(ev_io));

    struct sockaddr_in client_addr;
    unsigned int SOCK_LEN = sizeof(struct sockaddr_in);

    int client_fd = accept(server_fd, (struct sockaddr*) &client_addr,
                           &SOCK_LEN);

    key = server_exchange_key(client_fd);

    make_non_blocking(client_fd);

    close_me.push_back(client_fd);

    ev_io_init(client_watcher, client_callback, client_fd, EV_WRITE | EV_READ);
    ev_io_start(loop, client_watcher);

    ev_io_stop(EV_A_ watcher);

    printf("Connected to %s:%d\n>>> ", inet_ntoa(client_addr.sin_addr),
            ntohs(client_addr.sin_port));
    fflush(stdout);

}


void connect_conn(EV_P_ ev_timer* watcher, int events){

    printf("\nTrying to connect to remote server\n");
    fflush(stdout);

    connection_data* connection_server = (connection_data*) watcher->data;

    if(connection_server->client_fd <= 0){

        connection_server->client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        close_me.push_back(connection_server->client_fd);

    }

    struct sockaddr_in server_addr;
    int result_connect;

    client_set_addr(&server_addr, connection_server->server_ip, connection_server->server_port);
    result_connect = connect(connection_server->client_fd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in));


    if(result_connect < 0){

        printf("Unable to connect to %s:%d\n", connection_server->server_ip, connection_server->server_port);

    }
    else{

        client_watcher = (ev_io*) malloc(sizeof(ev_io));

        key = client_exchange_key(connection_server->client_fd);
        make_non_blocking(connection_server->client_fd);

        printf("Connection stablished!\n>>> ");

        /* Stop timed connection */
        ev_timer_stop(EV_A_ watcher);

        /* Create and start event watcher for connected socket */
        ev_io_init(client_watcher, client_callback, connection_server->client_fd, EV_WRITE | EV_READ);
        ev_io_start(loop, client_watcher);

    }
}


int main(int argc, char** argv){

    bool server_mode = check_input(argc, argv);

    make_non_blocking(0);

    struct ev_loop* event_loop = EV_DEFAULT;
    struct sigaction fecha_bonitinho;

    fecha_bonitinho.sa_handler = &fecha_server;
    sigaction(SIGINT, &fecha_bonitinho, NULL);

    int server_fd;
    int client_fd;

    if(server_mode){

        server_fd = open_server_socket(SERVER_PORT);

        ev_io server_watcher;
        ev_io_init(&server_watcher, accept_conn, server_fd, EV_READ);
        ev_io_start(event_loop, &server_watcher);

    }

    else{

        char* other_server_ip = argv[1];
        int other_server_port = atoi(argv[2]);

        ev_timer conector_watcher;

        connection_data connection;
        connection.server_ip = other_server_ip;
        connection.server_port = other_server_port;
        connection.client_fd = -1;

        conector_watcher.data = (void*) &connection;

        ev_timer_init(&conector_watcher, connect_conn, 0.0, 1.0);
        ev_timer_start(event_loop, &conector_watcher);

    }

    buffer_send = (char*) malloc(sizeof(char) * 64 KB);
    buffer_recv = (char*) malloc(sizeof(char) * 64 KB);

    ev_run(event_loop, 0);

    free(buffer_send);
    free(buffer_recv);

    close(server_fd);
    close(client_fd);

    return 0;

}
