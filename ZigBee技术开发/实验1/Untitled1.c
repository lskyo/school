#include<iocc2530.h>
#include<stdio.h>

#define LED0 P1_0
#define LED1 P1_1
#define ON 0
#define OFF 1
#define KEY2 P0_4
#define KEY1 P0_1

void Init_ir_key1(void)
{
  P0IFG &= 0x00;
  P0INP &= 0x02;
  PICTL |= 0x01;
  P0IEN |= 0x02;
  IEN1 |= 0x20;
  EA = 1;
}


#pragma vector = P0INT_VECTOR
__interrupt void P0_ISR(void)
{
  if(P0IFG>0)
  {
    P0IFG=0;
    P0IF=0;
    LED1 = ~LED1;
  }
}


void delay_us(unsigned int n)
{
  unsigned int tt;
  for(tt=0;tt<n;tt++);
  for(tt=0;tt<n;tt++);
  for(tt=0;tt<n;tt++);
}

void Init_led(void)
{
  P1SEL &= ~0x03;
  P1DIR |= 0x03;
  LED0 = ON;
  LED1 = ON;
}


void Init_key2(void)
{
  P0SEL &= ~0x10;
  P0DIR |= ~0x10;
  P0INP |= 0x10;
}

void main(void)
{
  Init_led();
  Init_key2();
  Init_ir_key1();
  
  
  while(1)
  {
    if(KEY2 == 0)
    {
      delay_us(150);
      if(KEY2==0)
      {
        while(!KEY2);
        LED0 = ~LED0;
      }
    }
  }
}