#include<ioCC2530.h>
#include"People.h"

#define ON 0
#define OFF 1
#define uint unsigned int
#define uchar unsigned char
#define LED1 P1_0
#define LED2 P1_1
#define uint8 unsigned char
#define uint16 unsigned int

void InitialAD(void);
void initclk(void);
void UartTX_Send_data(int Data);
void Delay(uint);
void initUARTtest(void);
void UartTX_Send_String(char *Data,int len);
void initial(void);
void Init_LED_IO(void);
uchar Recdata[6]="00000";
uchar RTflag=1;
uchar temp=0;
uint datanumber=0;
uint halfs=0,fives=0,min=0;
uchar data[2]={0,0};
uint adc_data=0;
float num;
char adcdata[]=" 0.0V";
uchar state=0;



void InitialAD(void)
{
  ADCH &= 0x00;
  ADCL &= 0x00;
  ADCCFG |=0x20;
  ADCCON3 = 0x35;
  ADCCON1 = 0x30;
  ADCCON1 |= 0x40;
}

void initial(void)
{
  P1DIR |= 0x01;
  T1CTL |= 0x0E;
  T1CC0L = 62500%256;
  T1CC0H = 62500/256;
  T1CCTL0 |= 0x04;
  T1IE = 1;
  EA = 1;
}


void initclk(void)
{
  CLKCONCMD &= ~0X40;
  while(!(SLEEPSTA & 0X40));
  CLKCONCMD &= ~0X47;
  SLEEPCMD |= 0X04;
}

void initUARTtest(void)
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
  LED1 = OFF;
  LED2 = OFF;
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



int main(void)
{
  uchar ii;
  initclk();
  initial();
  Init_LED_IO();
  initUARTtest();
  InitialAD();
  PeopleInit();
  
  while(1)
  {
    if(fives>=1)
    {
      fives=0;
      if(ADCCON1 & 0x80)
      {
        data[1]=ADCH;
        data[0]=ADCL;
        
        InitialAD();
        
        adc_data = 0;
        adc_data |=(uint)data[0];
        adc_data |= ((uint)data[1])<<8;

        adc_data = adc_data >> 3;
        num = (adc_data * 3.3)/4096;
        
        
        adcdata[1]=(char)(num)%10+48;
        adcdata[3]=(char)(num*10)%10+48;

        UartTX_Send_String(adcdata,5);
      }
    }
  }
  return 0;
}

#pragma vector = URX0_VECTOR
__interrupt void UART0_ISR(void)
{
  URX1IF = 0;
  temp = U0DBUF;
  RTflag = 1;
}

#pragma vector = T1_VECTOR
__interrupt void T1_ISR(void)
{
  if(1==PeopleScan())
  {
    state=1;
    UartTX_Send_String("\n Warning!Someone broke in!\n",30);
    LED1=ON;
  }
  else
  {
    if(state==1)
    {
      min++;
      LED1=ON;
      UartTX_Send_String("\n Warning!Someone broke in!\n",30);
    }
    if(min>=10)
    {
      LED1=OFF;
      state=0;
      min=0;
    }
  }
  halfs++;
  if(halfs>=1)
  {
    halfs=0;
    fives++;
  }
}