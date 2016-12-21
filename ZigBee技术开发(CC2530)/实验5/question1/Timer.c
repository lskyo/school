#include"Timer.h"
#include<ioCC2530.h>

void Initial(void)
{
  P1DIR |= 0x01;
  T1CTL |= 0x0E;
  T1CC0L = 62500%256;
  T1CC0H = 62500/256;
  T1CCTL0 |= 0x04;
  T1IE = 1;
  EA = 1;
}

#pragma vector = T1_VECTOR
__interrupt void T1_ISR(void)
{
  halfs++;
  if(halfs>=10)
  {
    halfs=0;
    fives++;
  }
}