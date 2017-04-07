#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define RET_OK   0
#define RET_ERR -1

#define LISTEN_QUEUE_NUM 5

#define BUFFER_SIZE 256

#define ECHO_PORT 2029

int main(int argc, char **argv)
{
	int sockfd = -1 ;
	int opt = 1;
	struct sockaddr_in cliaddr;
	uint8_t buffer[BUFFER_SIZE];
	int sendbytes = 0;
	int ret = -1;
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

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("ERROR opening socket");
		return RET_ERR;
	}
	if((ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) < 0)
	{
		perror("ERROR setsockopt");
		goto failed;
	}
	memset(&cliaddr, 0, sizeof(cliaddr));
	cliaddr.sin_family = AF_INET;
	cliaddr.sin_addr = *((struct in_addr *)host->h_addr);
	cliaddr.sin_addr.s_addr = *((int *)host->h_addr);
	cliaddr.sin_port = htons(ECHO_PORT);
	int len = sizeof(struct sockaddr_in);
	

	while(1)
	{
	printf("please Enter Message:\n");
	memset(buffer,0,sizeof(buffer));
	if(fgets(buffer,sizeof(buffer)-1,stdin)==NULL)
	{break;}
	//do{fgets(buffer,BUFFER_SIZE-1,stdin);
	//strcpy(buffer,"Yes, it is my first udp client! :)");		
	if((sendbytes=sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&cliaddr, len))==-1){
			perror("send");
			exit(1);
	}
	//}while(buffer[0]!='\0');
	}
failed:
	close(sockfd);
	return 0;
}
