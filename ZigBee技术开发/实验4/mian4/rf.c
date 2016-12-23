#include "rf.h"
#include "uart.h"
extern unsigned char duf[16];
extern unsigned char fuf[16];
void rf_in()
{
    FRMCTRL0 |=(0X20|0X40); 
    TXFILTCFG =0X09;
    AGCCTRL1=0X15;
    FSCAL1=0X00;
    RFIRQM0|=(1<<6);
    IEN2|=(1<<0);
    EA=1;
    FREQCTRL =0X0F;//信道选择 11信道
    SHORT_ADDR0=0X05;
    SHORT_ADDR1=0X00;
    PAN_ID0=0X22;
    PAN_ID1=0X00;
    RFST=0XED;
    RFST=0XE3;
    FRMFILT0&=~(1<<0);
}  


void rf_send(unsigned char *data)
{
    unsigned char i;
    unsigned char mac[]="test";
    RFST=0XE3;
    while(FSMSTAT1&((1<<1)|(1<<5)));
    RFIRQM0 &=~(1<<6);
    IEN2&=~(1<<0);
    RFST=0XEE;
    RFIRQF1=~(1<<1);
    RFD=11;
    for(i=0;i<4;i++)
    {
      RFD=mac[i];
    }
    RFIRQM0|=(1<<6);
    IEN2|=(1<<0);
    RFST =0XE9;
    while(!(RFIRQF1&(1<<1)));
    RFIRQF1=~(1<<1);
}

#pragma vector =RF_VECTOR
__interrupt void rf_isr(void)
{  unsigned char i,len;
    EA=0;
    if(RFIRQF0&(1<<6))
    {
        len=RFD;
        len&=0x7f;
        for(i=0;i<len;i++)
        {
            duf[i]=RFD;
        }
        S1CON=0;
        RFIRQF0&=~(1<<6);
    }
    if(duf[0]==’O&&duf[1]==’F’)
    LED=OFF;
    if(duf[0]==’O&&duf[1]==’N’)
    LED=ON;
    EA=1;
}
