#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/stat.h>

#define SERVPORT 1300
#define MAXDATASIZE 1000
#define FILE_NAME_LEN 30
main(int argc,char *argv[])
{
	int sockfd,sendbytes;
	char buf[MAXDATASIZE];
	char file_name[FILE_NAME_LEN];
	struct hostent *host;
	struct sockaddr_in serv_addr;
	int fd = 0;
	int totalbytes = 0;
	int readbytes = 0;
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

        printf("please input the file you want to open:\n");

        scanf("%s",file_name);
        printf("buf is %s\n",file_name);

        fd=open(file_name,O_RDWR | O_CREAT, 0666);
        if(fd < 0){
        	perror("open");
        	exit(1);
        }	


        printf("press s to send file\n");
        getchar();
        while((readbytes = read(fd, buf,MAXDATASIZE)) )
        {
            if((sendbytes=send(sockfd, buf, readbytes,0))==-1){
            	perror("send");
            	exit(1);
            }
            totalbytes += sendbytes;
        }

        printf("sent %d bytes ..\n", totalbytes);
        close(sockfd);
            

}

