/*
 * jemalloc_test.c
 *
 *  Created on: 2015-7-17
 *      Author: liufuliang
 */
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define TCP_BACKLOG       511     /* TCP listen backlog */
#define True 1
#define False 0

int main(int argc, char** argv){

	/*------------------getaddrinfo--------------------*/
	int port = 6375;

	//service
	char service[6];
	snprintf(service,6,"%d",port);

	//hints
	struct addrinfo hints, *localAddress;
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;    /* No effect if bindaddr != NULL */
    int rv;
    if ((rv = getaddrinfo(NULL,service,&hints,&localAddress)) != 0) {
        printf("ERROR: %s", gai_strerror(rv));
        return -1;
    }

    /*------------------socket bind, listen--------------------*/
    //print info
    char buf[512];
    int socket_fd;
    struct addrinfo *r;
    for(r=localAddress; r != NULL; r=r->ai_next){
    	struct sockaddr_in *sa = (struct sockaddr_in *)r->ai_addr;
    	printf("name: %s\nip:%s\nfamily:%d\nsocktype:%d\nprotocol:%d\n",
    			r->ai_canonname,
    			inet_ntop(AF_INET, &sa->sin_addr.s_addr, buf, sizeof(buf)),
    			r->ai_family,
    			r->ai_socktype,
    			r->ai_protocol);

    	//socket()
    	if((socket_fd = socket(r->ai_family, r->ai_socktype, r->ai_protocol)) < 0){
    		continue;
    	}
    	//setsockopt()
    	int yes = 1;
    	if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
            printf("setsockopt SO_REUSEADDR: %s", strerror(errno));
            continue;
        }
    	//bind
        if (bind(socket_fd, r->ai_addr, r->ai_addrlen) == -1){
        	close(socket_fd);
        	continue;
        }

        //listen
        if (listen(socket_fd, TCP_BACKLOG) == -1) {
            printf("listen: %s", strerror(errno));
            close(socket_fd);
            continue;
        }
        //fcntl noblock
        int flags;
        if ((flags = fcntl(socket_fd, F_GETFL)) == -1) {
            printf("fcntl(F_GETFL): %s", strerror(errno));
            close(socket_fd);
            continue;
        }
        int NOBLOCK = 0;
        if (NOBLOCK)
            flags |= O_NONBLOCK;
        else
            flags &= ~O_NONBLOCK;

        if (fcntl(socket_fd, F_SETFL, flags) == -1) {
            printf("fcntl(F_SETFL,O_NONBLOCK): %s", strerror(errno));
            close(socket_fd);
            continue;
        }

        break;
    }

    if(r==NULL){
        fprintf(stderr, "Could not bind\n");
        exit(-1);
    }
    freeaddrinfo(localAddress);


    /*------------------socket accept--------------------*/
    char client_ip[46];
    int client_port;
    while (True) {
    	//accept
    	struct sockaddr_storage address;
    	struct sockaddr *apiAddress = (struct sockaddr *)&address;
    	socklen_t address_len = sizeof(address);
    	int client_fd = accept(socket_fd,apiAddress,&address_len);
    	if(client_fd == -1){
    		printf("accept: %s", strerror(errno));
    		break;
    	}
    	//tcp_nodelay forbid nagle
    	int yes = 1;
        if (setsockopt(client_fd, IPPROTO_TCP, TCP_NODELAY, &yes, sizeof(yes)) == -1){
            printf("setsockopt TCP_NODELAY: %s", strerror(errno));
        }
    	//client ip and port
    	if (address.ss_family == AF_INET) {
    		struct sockaddr_in *s = (struct sockaddr_in *)&address;
    		inet_ntop(AF_INET,(void*)&(s->sin_addr),client_ip,sizeof(client_ip));
    		client_port = ntohs(s->sin_port);
    	} else {
    		struct sockaddr_in6 *s = (struct sockaddr_in6 *)&address;
    		inet_ntop(AF_INET6,(void*)&(s->sin6_addr),client_ip,sizeof(client_ip));
    		client_port = ntohs(s->sin6_port);
    	}
    	close(client_fd);
    	printf("client ip: %s\nclient port:%d\nclient fd: %d\n", client_ip, client_port, client_fd);
    }

    close(socket_fd);
	return 0;
}
#endif

