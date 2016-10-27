/* 掌握Linux系统下GCC/GDB的使用 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int display1(char *string);
char* reverse(char *string);

int main(void)
{
	char string[] = "Embeded Linux in ZhongShan Institute";
	char *ptr = NULL;
	
	display1(string);
	
	ptr = reverse(string);
	
	printf("the string len is %d\n",strlen(ptr));
	
	return 0;
}



int display1(char *string)
{
	printf("The original string is \"%s\"\n",string);
}



char* reverse(char *string1)
{
	int size = 0;
	int i = 0;
	
	size = strlen(string1);

	char *string2 = (char *)malloc(size + 1);

	for(i = 0; i < size; i++)
	{
		string2[size - i - 1] = string1[i];
	}

	string2[size] = 0;

	printf("The string afterward is \"%s\"\n",string2);

	return string2;
}

