#include"ADC.h"
#include<ioCC2530.h>





void InitialAD(void)
{
  ADCH &= 0x00;
  ADCL &= 0x00;
  ADCCFG |=0x20;
  ADCCON3 = 0x35;
  ADCCON1 = 0x30;
  ADCCON1 |= 0x40;
}