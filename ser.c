#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include "./header_files/server_utils.h"

#define PORT 8090
#define PASS_LENGTH 20
#define ERR_EXIT(msg) do{perror(msg);exit(EXIT_FAILURE);} while(0)

void *connection_handler(int connectedfd)
{
	service_cli(connectedfd);
}

int main(){
	printf("Initializing connection...\n");
	
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd==-1) {
		//if socket creation fails
		printf("socket creation failed\n");
		ERR_EXIT("socket()");
	}

	int optval = 1;
	int optlen = sizeof(optval);
	/*
	to close socket automatically while terminating process
	SOL_SOCKET : to manipulate option at API level o/w specify level
	*/
	
	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	sa.sin_port = htons(PORT);
	/*
	sockaddr_in is from family AF_INET (ip(7)) and varies as per the adress family
	*/

	printf("Binding socket...\n");
	if(bind(sockfd, (struct sockaddr *)&sa, sizeof(sa))==-1){
		printf("binding port failed\n");
		ERR_EXIT("bind()");
	}

	//2nd arg : size of backlog
	if(listen(sockfd, 100)==-1){
		printf("listen failed\n");
		ERR_EXIT("listen()");
	}

	printf("Listening...\n");

	pthread_t thread_id[110];
	int i=0;

	while(1){ 
		int connectedfd;

		if((connectedfd = accept(sockfd, (struct sockaddr *)NULL, NULL))==-1){
			printf("connection error\n");
			ERR_EXIT("accept()");
		}

		if( pthread_create(&thread_id[i++],NULL,connection_handler,connectedfd) < 0)
		{
			perror("thread not created");
			return 1;
		}

		if( i >= 100)
        {
          	i = 0;
          	while(i < 50)
          	{
           	  pthread_join(thread_id[i++],NULL);
          	}
         	 i = 0;
        }
	}
	close(sockfd);
	printf("Connection closed!\n");
	return 0;
}
