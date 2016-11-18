#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 100


int main(int argc, char **argv)
{
    int fd_r,fd_w,nwrite,nread,len;
    char *buff="Hello\n";
    char buf_r[BUF_LEN];
    char buf[BUF_LEN];
    buf_r[BUF_LEN-1] = '\0';
	
	if(argc<3)
	{
		printf("please input filename!");
		exit(0);
	}

    fd_r=open(argv[1],O_RDWR | O_CREAT, 0666);
    if(fd_r < 0){
    	perror("open");
    	exit(1);
    }	
	fd_w=open(argv[2],O_RDWR | O_CREAT, 0666);
	if(fd_w < 0){
		perror("open");
		exit(1);
	}
	
	while((nread=read(fd_r,buf,BUF_LEN)) > 0){
	printf("read:%s",buf);
	//len=strlen(buf);
	write(fd_w,buf,nread);
    }
	
	
	/*
    if((nread=read(fd_r,buf,BUF_LEN)) > 0){
	//printf("read:%s",buf);
    }
    */
    close(fd_r);
	close(fd_w);
}