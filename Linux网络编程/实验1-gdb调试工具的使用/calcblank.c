/* 注意GetMemory（char **p）的使用 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void GetMemory(char **p)
{
    *p = (char *)malloc(100);
}
void CalcBlank(void)
{
    char *str = NULL;
    char *ptr = NULL;
    unsigned int i = 0;
    GetMemory((char *)&str);
    //str = (char *)malloc(100);
    //char str[100];
    strcpy(str, "Karl marx is born in Germany and German is \
                his native language\n");
    ptr = str;
    while(('\0' != (*ptr)))
    {
        if (*ptr == ' ')
        {
            i++;
        }
        ptr++;
    }
    printf("the blank number is %d\n",i);
    //free(ptr);
}

int main(void)
{
    CalcBlank();
    return 0;
}


