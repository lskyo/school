#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <errno.h>  
#include <sys/socket.h>
#include <sys/types.h>  
#include <linux/in.h>
#include <linux/if_ether.h>
#include <net/if.h>
#include <sys/ioctl.h>


typedef struct _ethdr
{
	char src_mac[6];
	char dst_mac[6];
	short type;
}ETH_HEADER;

typedef struct _iphdr
{
	unsigned char h_verlen;
	unsigned char tos;
	unsigned short total_len;
	unsigned short ident;
	unsigned short frag_and_flags;
	unsigned char ttl;
	unsigned char proto;
	unsigned short checksum;
	unsigned int sourceIP;
	unsigned int destIP;
}IP_HEADER;

int sock,n;
char buffer[1518];
unsigned char *iphead,*ethhead;


/*线程函数声明*/
void pthread1(void *arg);
void pthread2(void *arg);

/*线程ID 定义*/
pthread_t id1,id2;

/*定义指针指向字符串*/
char *string1 = "it is pthread 1 running...\n";
char *string2 = "it is pthread 2 running...\n";

/*定义全局变量，在两个线程里面分别加1，因此这个gNum变量就是我们所说的临界资源*/
int gNum = 0;
int main(int argc, char *argv[])
{
	
	int ret;
	if((sock=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP)))<0)
	{
		perror("socket");
		exit(1);
	}
	
	printf("entering main thread\n");
	
	/*创建线程pthread1*/
	ret=pthread_create(&id1,NULL,(void *)pthread1, NULL);
	if(ret!=0) {
		perror("pthread create1");
	}
	ret=pthread_create(&id2,NULL,(void *)pthread2, NULL);
	if(ret!=0) {
		perror("pthread create2");
	}

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	while(1)
	{
		usleep(1000000);
	}
	printf("leaving main thread\n");
	exit(0);
}

void pthread1(void *arg)
{
	printf("entering thread1\n");
	while(1)
	{
		/*
		gNum++;
		printf("pthread1: gNum = %d\n",gNum);
		usleep(3000000);
		if(gNum>=1000)
			break;
		*/
		printf("--------------\n");
		n = recvfrom(sock,buffer,sizeof(buffer),0,NULL,NULL);
		printf("%d bytes read\n",n);
		IP_HEADER *ipHdr = (IP_HEADER *)(buffer+sizeof(ETH_HEADER));
		unsigned char *p = (unsigned char*)&ipHdr->sourceIP;
		if(0x01==ipHdr->proto)
		{
			printf("test2\n");
			printf("Source IP\t: %u.%u.%u.%u\n",p[0],p[1],p[2],p[3]);
			p = (unsigned char*)&ipHdr->destIP;
			printf("Destination IP\t: %u.%u.%u.%u\n",p[0],p[1],p[2],p[3]);
		}
		
		
		
	}
	printf("leaving thread1\n");	
}
void pthread2(void *arg)
{
	printf("entering thread2\n");
	while(1)
	{
		usleep(1000000);
		printf("pthread2 wakeup!\n");
	}
	printf("leaving thread2\n");	
}
