#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 100

int main(void)
{
	int fd,nwrite,nread,len;
	char *buff="abcdefg";
	char buf_r[BUF_LEN];
	buf_r[BUF_LEN-1] = '\0';
	
	len=strlen(buff);
	fd=open("hello",O_RDWR | O_CREAT, 0666);
	if(fd < 0){
		perror("open");
		exit(1);
	}
	if((nwrite=write(fd,buff,len))==len){
		printf("write success\n");
	}
	
	close(fd);
	exit(0);
}

