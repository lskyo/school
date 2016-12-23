#include "uart.h"

void uart_in()
{
    CLKCONCMD &=~0X40;    
    while(!(SLEEPSTA&0X40));    
    CLKCONCMD &=~0X47;    
    SLEEPCMD|=0X04;    
    PERCFG=0X00;   
    P0SEL|=0X3C;    
    P2DIR&=~0XC0;    
    U0CSR|=0X80;  
    U0GCR|=10;   
    U0BAUD|=216;
}
void uartTX_send_string(unsigned char *data,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        U0DBUF = *data++;
        while(UTX0IF==0);
        UTX0IF=0;
    }
}
void uartTX_send(unsigned char data)
{
    
        U0DBUF = data;
        while(UTX0IF==0);
        UTX0IF=0;
}