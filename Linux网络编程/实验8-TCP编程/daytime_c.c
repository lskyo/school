#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define SERVPORT 13
#define MAXDATASIZE 100
main(int argc,char *argv[])
{
	int sockfd,sendbytes;
	char buf[MAXDATASIZE];
	struct hostent *host;
	struct sockaddr_in serv_addr;
	if(argc < 2){
		fprintf(stderr,"Please enter the server's hostname!\n");
		exit(1);
	}
	if((host=gethostbyname(argv[1]))==NULL){
		perror("gethostbyname");
		exit(1);
	}
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("socket");
		exit(1);
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(SERVPORT);
	serv_addr.sin_addr=*((struct in_addr *)host->h_addr);
	bzero(&(serv_addr.sin_zero),8);
	if(connect(sockfd,(struct sockaddr *)&serv_addr,\
		sizeof(struct sockaddr))==-1){
		perror("connect");
		exit(1);
	}
	if((sendbytes=recv(sockfd,buf,MAXDATASIZE,0))==-1){
		perror("recv");
		exit(1);
	}
	buf[sendbytes] = '\0';
 	printf("received sys msg from server:%s",buf);
	while (1)
	{
	 	
        	printf("Enter the message  : ");
        	if(fgets(buf, sizeof(buf) - 1, stdin) == NULL)
        	{
        		break;
        	}	
		if((sendbytes=send(sockfd,buf,strlen(buf),0))==-1){
			perror("send");
			exit(1);
		}
		printf("sent %d bytes \n", sendbytes);
	}
	close(sockfd);
}

