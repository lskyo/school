#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include "string.h"

/*�̺߳�������*/
void pthread1(void *arg);
void pthread2(void *arg);

/*�߳�ID ����*/
pthread_t id1,id2;

/*����ָ��ָ���ַ���*/
char *string1 = "it is pthread 1 running...\n";
char *string2 = "it is pthread 2 running...\n";

/*����ȫ�ֱ������������߳�����ֱ��1��������gNum��������������˵���ٽ���Դ*/
int gNum = 0;
int main(int argc, char *argv[])
{
	int ret;
	
	printf("entering main thread\n");
	
	/*�����߳�pthread1*/
	ret=pthread_create(&id1,NULL,(void *)pthread1, NULL);
	if(ret!=0) {
		perror("pthread create1");
	}

	/*�����߳�pthread2*/
	ret=pthread_create(&id2,NULL,(void *)pthread2, string2);
	if(ret!=0) {
		perror("pthread create2");
	}

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	printf("leaving main thread\n");
	exit(0);
}

void pthread1(void *arg)
{
	printf("entering thread1\n");
	int i = 0;
	for(i = 0 ;i<3 ;i++)
	{
		gNum++;
		printf("pthread1: gNum = %d\n",gNum);
		usleep(300000);
	}
	printf("leaving thread1\n");	
}

void pthread2(void *arg)
{
	printf("entering thread2\n");
	int i = 0;
	printf("arg is %s\n", arg);
	for(i = 0 ;i<3 ;i++)
	{
		gNum++;
		printf("pthread2: gNum = %d\n",gNum);
		usleep(300000);
	}

	printf("leaving thread2\n");		
}

