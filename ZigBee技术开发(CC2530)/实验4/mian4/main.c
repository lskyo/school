#include "uart.h"
#include "time1.h"
#include "rf.h"
#define key1 P0_1 
#define key2 P0_4 
#define ON    0
#define OFF   1
#define uint16 unsigned int
int time1;//定时器1中断标志位
int adc;//adc中断标志位
unsigned  char temp[2];
unsigned  char duf[16];
unsigned  char fuf[16];
void delay(uint16 n);
void in()
{
     CLKCONCMD &=~0x40;
     delay(100);
     P0SEL&=~0x11;
     P0DIR&=~0x11;
     
     P1SEL&=~0x03;
     P1DIR|=0x03;    
}




void main(void)
{ 
     while(1)
    {
       if(key2==0)
       {
              delay(1000000);
              if(key2==0)
              {
                    rf_send(‘ON’); 
              }
if(key1==0)
              {
                    rf_send(‘OF’); 
              }
       }  
  }
}



void delay(uint16 n)
{
    uint16 tt;
    for(tt=0;tt<n;tt++);
    for(tt=0;tt<n;tt++);
    for(tt=0;tt<n;tt++);
    for(tt=0;tt<n;tt++);
    for(tt=0;tt<n;tt++);
}





