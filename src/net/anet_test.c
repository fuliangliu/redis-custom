/*
 * jemalloc_test.c
 *
 *  Created on: 2015-7-17
 *      Author: liufuliang
 */
#if 0
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "zmalloc.h"
#include "anet.h"

#define TCP_BACKLOG       511     /* TCP listen backlog */

int main(int argc, char** argv){
	int port = 6375;
	int socket_fd, client_fd;
    int cport;
    char cip[46];

    //server bind
	if((socket_fd = anetTcpServer(NULL, port, NULL, 511)) == ANET_ERR){
		printf("anetTcpServer Error");
		return -1;
	}

	//block or noblock
	if(anetBlock(NULL, socket_fd) == ANET_ERR){
		printf("anetNonBlock Error");
	}

	//accept
	if((client_fd = anetTcpAccept(NULL, socket_fd, cip, sizeof(cip), &cport) == ANET_ERR)){
		printf("anetTcpAccept Error");
	}

	printf("cip: %s\n", cip);
	printf("cport: %d\n", cport);
	printf("client_fd: %d\n", client_fd);

	close(client_fd);
	close(socket_fd);
}
#endif

