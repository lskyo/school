#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  
#include <unistd.h>
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


int main(int argc,char **argv)
{
	int sock,n;
	char buffer[1518];
	unsigned char *iphead,*ethhead;
	
	if((sock=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP)))<0)
	{
		perror("socket");
		exit(1);
	}
	
	while(1)
	{
		printf("--------------\n");
		n = recvfrom(sock,buffer,sizeof(buffer),0,NULL,NULL);
		printf("%d bytes read\n",n);
		/*
		int num = 1;
		for(num=1;num<=n;num++)
		{
			printf("%d ",buffer[num]);
			if(0==(num%16))
			{
				printf(";\n");
			}
		}
		printf("\n");
		*/
/*
		ethhead = buffer;
		char protocol = *(ethhead+14+9);
		if(0x01 == protocol)
		{
			printf("test1\n");
			printf("Source MAC address: "
				"%02x:%02x:%02x:%02x:%02x:%02x\n",
				ethhead[0],ethhead[1],ethhead[2],
				ethhead[3],ethhead[4],ethhead[5]);
			printf("Destination MAC address: "
				"%02x:%02x:%02x:%02x:%02x:%02x\n",
				ethhead[6],ethhead[7],ethhead[8],
				ethhead[9],ethhead[10],ethhead[11]);
		}
*/
		
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
	return 0;
}
