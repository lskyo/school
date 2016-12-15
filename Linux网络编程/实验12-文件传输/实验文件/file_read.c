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
    char *buff="Hello\n";
    char buf_r[BUF_LEN];
    buf_r[BUF_LEN-1] = '\0';

    printf("please input the file you want to open:\n");
    scanf("%s",buf_r);
    printf("buf is %s\n",buf_r);

    fd=open(buf_r,O_RDWR | O_CREAT, 0666);
    if(fd < 0){
    	perror("open");
    	exit(1);
    }	

    if((nread=read(fd,buf_r,BUF_LEN)) > 0){
        if(nread < (BUF_LEN - 1))
        	{
        	    buf_r[nread] = '\0';
        	}
        printf("read:%s\n",buf_r);
    }

    close(fd);
}

