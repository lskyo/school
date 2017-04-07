/* printf不同域变量的地址 */ 

#include<stdio.h>

int bb = 1;


void test(int i)
{
	int aa = 0;
	int dd = 0;
	bb = 10;
	
	printf("&aa = %d\n",&aa);
	printf("&dd = %d\n",&dd);
}

int main(void)
{

	//int bb = 1;
	int cc = 99;
	test(bb);
	
	printf("&bb = %d\n",&bb);
	printf("&cc = %d\n",&cc);
	
	printf("bb = %d\n",bb);

	return 0;
}
