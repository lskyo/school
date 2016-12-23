#include<ioCC2530.h>
#include"MYUART.h"

#define uint unsigned int
#define uchar unsigned char
#define LED1 P1_0
#define LED2 P1_1

void Delay(uint);
void Init_LED_IO(void);
 
uchar Recdata[6]="00000";
uchar RTflag=1;
uchar temp=0;
uint datanumber=0;


void Delay(uint n)
{
  uint tt;
  for(tt=0;tt<n;tt++);
  for(tt=0;tt<n;tt++);
  for(tt=0;tt<n;tt++);
  for(tt=0;tt<n;tt++);
  for(tt=0;tt<n;tt++);
}


void Init_LED_IO(void)
{
  P1DIR |= 0x03;
  LED1 = 1;
  LED2 = 1;
}


#pragma vector = URX0_VECTOR
__interrupt void UART0_ISR(void)
{
  URX1IF = 0;
  temp = U0DBUF;
  RTflag = 1;
}



void main(void)
{
  uchar ii;
  Init_LED_IO();
  Init_UART();
  
  while(1)
  {
    if(RTflag == 1)
    {
      RTflag = 0;
      if(temp!=0)
      {
        if((temp!='#')&&(datanumber<6))
        {
          Recdata[datanumber++]=temp;
        }
        else 
        {
          RTflag=3;
        }
        if(datanumber==6)
        {
          RTflag=3;
          temp=0;
        }
      }
    }
    if(RTflag == 3)
    {
      RTflag = 0;
      if(Recdata[0]=='L')
      {
        if(Recdata[1]=='E')
        {
          if(Recdata[2]=='D')
         {
           if(Recdata[3]=='1')
          {
            if(Recdata[4]=='1')
           {
             LED1 = 0;
           }
           else if(Recdata[4]=='2')
           {
             LED1 = 1;
           }
          }
          else if(Recdata[3]=='2')
          {
            if(Recdata[4]=='1')
           {
             LED2 = 0;
           }
           else if(Recdata[4]=='2')
           {
             LED2 = 1;
           }
          }
         }
        }
      }
    for(ii=0;ii<6;ii++)  Recdata[ii]='0';
    datanumber = 0;
    }
  }
}

