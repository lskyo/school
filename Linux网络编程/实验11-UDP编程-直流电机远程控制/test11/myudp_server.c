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
#include <fcntl.h>
#include <sys/ioctl.h>



#define DCM_IOCTRL_SETPWM 			(0x10)
#define DCM_TCNTB0				(16384)
#define RET_OK   0
#define RET_ERR -1

static int dcm_fd = -1;
char *DCM_DEV="/dev/dcm/0raw";


#define BUFFER_SIZE 256

#define ECHO_PORT 2029

int main(int argc, char **argv)
{
	int factor = DCM_TCNTB0/1024;
	//int setpwm = 0;
	int sockfd, len, opt = 1;
	struct sockaddr_in cliaddr;
	uint8_t buffer[BUFFER_SIZE];
	int ret = RET_OK;

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
	cliaddr.sin_addr.s_addr = INADDR_ANY;
	cliaddr.sin_port = htons(ECHO_PORT);
	if ((ret = bind(sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr))) < 0)
	{
		perror("ERROR on binding");
		goto failed;
	}
    /*
	do 
	{
		memset(buffer, 0 ,sizeof(buffer));
	
		len = sizeof(cliaddr);
		if((ret = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len)) > 0)
		{
			printf("Recv from %s\r\n", inet_ntoa(cliaddr.sin_addr));
			printf("recv msg : %s\n", buffer);
		}
	}while(ret >= 0);
	*/
	
	if((dcm_fd=open(DCM_DEV, O_WRONLY))<0){
		printf("Error opening %s device\n", DCM_DEV);
		return 1;
	}
	
	
	
	
	
	do 
	{
		memset(buffer, 0 ,sizeof(buffer));
		len = sizeof(cliaddr);
		if((ret = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len)) > 0)
		{
			printf("Recv from %s\r\n", inet_ntoa(cliaddr.sin_addr));
			printf("recv msg : %s\n", buffer);
			//使用atoi函数将buffer里的字符型数据转换整形，并通过ioctl设置电机转速
			//ioctl(.....);//具体用法请参看dcm_main.c
			ioctl(dcm_fd, DCM_IOCTRL_SETPWM, (atoi(buffer) * factor));	
		}
	}while(ret >= 0);

failed:
	close(sockfd);
	return 0;
}
