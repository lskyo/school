/* printf各个数据类型的大小 */
#include<stdio.h>


int main(void)
{
	printf("sizeof(char)=%d\n",sizeof(char));
	printf("sizeof(unsigned char)=%d\n",sizeof(unsigned char));
	printf("sizeof(short)=%d\n",sizeof(short));
	printf("sizeof(long)=%d\n",sizeof(long));
	printf("sizeof(double)=%d\n",sizeof(double));
	printf("sizeof(long long)=%d\n",sizeof(long long));
	printf("sizeof(int)=%d\n",sizeof(int));
	printf("sizeof(char *)=%d\n",sizeof(char *));
	printf("sizeof(short *)=%d\n",sizeof(short *));
	printf("sizeof(int  *)=%d\n",sizeof(int  *));
	return 0;
}
