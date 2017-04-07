#include"UART.h"
#include<ioCC2530.h>



void Init_UART(void)
{  
  PERCFG = 0X00;
  P0SEL = 0X3C;
  P2DIR &= ~0XC0;
  U0CSR |= 0X80;
  U0GCR |= 10;
  U0BAUD |= 216;
  
  UTX1IF = 1;
  U0CSR |= 0X40;
  IEN0 |= 0x84;
}


void UartTX_Send_String(char *Data,int len)
{
  int j;
  for (j=0;j<len;j++)
  {
    U0DBUF = *Data++;
    while(UTX0IF == 0);
    UTX0IF = 0;
  }
}




void UartTX_Send_data(int Data)
{
  U0DBUF = Data;
  while(UTX0IF == 0);
  UTX0IF = 0;
}


#pragma vector = URX0_VECTOR
__interrupt void UART0_ISR(void)
{
  URX1IF = 0;
  temp = U0DBUF;
  RTflag = 1;
}