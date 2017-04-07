#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SERVPORT 1300
#define BACKLOG 10
#define MAX_CONNECTED_NO 10
#define MAXDATASIZE 500

int main()
{
	struct sockaddr_in server_sockaddr,client_sockaddr;
	int sin_size,recvbytes;
	int sockfd,client_fd;
	time_t currentTime;
	char timebuffer[MAXDATASIZE+1];
        int fd = 0;
        int nwrite = 0;
	char buf[MAXDATASIZE];
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket");
		exit(1);
	}
	printf("socket success!,sockfd=%d\n",sockfd);
	server_sockaddr.sin_family=AF_INET;
	server_sockaddr.sin_port=htons(SERVPORT);
	server_sockaddr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(server_sockaddr.sin_zero),8);
	if(bind(sockfd,(struct sockaddr *)&server_sockaddr,sizeof(struct sockaddr))==-1){
		perror("bind");
		exit(1);
	}
	printf("bind success!\n");
	if(listen(sockfd,BACKLOG)==-1){
		perror("listen");
		exit(1);
	}
	printf("listening....\n");

        sin_size = sizeof(struct sockaddr);
	if((client_fd=accept(sockfd,(struct sockaddr *)&client_sockaddr,&sin_size))==-1){
		perror("accept");
		exit(1);
	}

	fd=open("recvfile",O_RDWR | O_CREAT, 0666);
	if(fd < 0){
		perror("open");
		exit(1);
	}

	
	while (1) {
		if((recvbytes=recv(client_fd,buf,MAXDATASIZE,0)) <= 0){
			perror("recv");
			break;
		}
        	if((nwrite=write(fd,buf,recvbytes)) < 0 ){
        		perror("write file");
        	}

	}

	close(sockfd);
	close(fd);
	
}

