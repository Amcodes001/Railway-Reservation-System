#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <fcntl.h>
#include <pthread.h>
#include "./header_files/client_utils.h"

#define PORT 8090
#define PASS_LENGTH 20

int main(int argc, char * argv[]){
	char *ip = "127.0.0.1";

	if(argc==2){
		ip = argv[1];
	}

	int cli_fd = socket(AF_INET, SOCK_STREAM, 0);

	if(cli_fd == -1){
		printf("socket creation failed\n");
		exit(0);
	}

	struct sockaddr_in ca;
	ca.sin_family=AF_INET;
	ca.sin_port= htons(PORT);
	ca.sin_addr.s_addr = inet_addr(ip);

	if(connect(cli_fd, (struct sockaddr *)&ca, sizeof(ca))==-1){
		printf("connect failed\n");
		exit(0);
	}
	
	printf("connection established\n");
	
	while(entry_point(cli_fd)!=3);
	close(cli_fd);

	return 0;
}