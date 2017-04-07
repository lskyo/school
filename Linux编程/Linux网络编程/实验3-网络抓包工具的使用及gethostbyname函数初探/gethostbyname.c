#include"stdio.h"
#include"netdb.h"
int main(int argc,char **argv)
{
	if(argc != 2)
	{
		printf("Usage is %s hostname\n",argv[0]);
		return -1;
	}
	struct hostent *server = NULL;
	server = gethostbyname(argv[1]);
	struct sockaddr_in addr;
	if(NULL == server)
	{
		printf("Fail to retrieve ip addr\n");
		return -1;
	}
	addr.sin_addr.s_addr = *(int *)(server->h_addr);
	printf("addr is 0x%x\n",addr.sin_addr.s_addr);
	return 0;
}