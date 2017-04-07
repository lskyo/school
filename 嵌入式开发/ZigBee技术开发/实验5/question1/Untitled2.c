#include<ioCC2530.h>
#include"Timer.h"
#include"UART.h"
#include"ADC.h"


#define LED1 P1_0
#define LED2 P1_1


void Initclk(void);
void Delay(uint16);
void Init_LED_IO(void);


uint8 RTflag=1;
uint8 temp=0;
uint16 halfs=0;
uint16 fives=0;
uint8 Recdata[6]="00000";
uint16 datanumber=0;
uint8 data[2]={0,0};
uint16 adc_data=0;
float num;
char adcdata[]=" 0.0V";


void Initclk(void)
{
  CLKCONCMD &= ~0X40;
  while(!(SLEEPSTA & 0X40));
  CLKCONCMD &= ~0X47;
  SLEEPCMD |= 0X04;
}



void Delay(uint16 n)
{
  uint16 tt;
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



void main(void)
{
  Initclk();
  Initial();
  Init_LED_IO();
  Init_UART();
  InitialAD();
  
  while(1)
  {
    if(fives>=1)
    {
      fives=0;
      LED2=~LED2;
      if(ADCCON1 & 0x80)
      {
        data[1]=ADCH;
        data[0]=ADCL;
        
        InitialAD();
        
        adc_data = 0;
        adc_data |=(uint16)data[0];
        adc_data |= ((uint16)data[1])<<8;

        adc_data = adc_data >> 3;
        num = (adc_data * 3.3)/4096;
        
        
        adcdata[1]=(char)(num)%10+48;
        adcdata[3]=(char)(num*10)%10+48;

        UartTX_Send_String(adcdata,5);
      }
    }
  }
}


