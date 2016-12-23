#include "time1.h"
#include "uart.h"
extern int time1;
extern int adc;
void time1_in()
{
    CLKCONCMD &=~0X40;   // ѡ���ⲿʯӢ����32M
    while(!(SLEEPSTA&0X40));   // �ȴ������ȶ�
    CLKCONCMD &=~0X47;    //T1CHSPD����Ƶ��CLKSPD����Ƶ
    SLEEPCMD|=0X04; //�ر�RC����
    T1CTL|=0x0E;     //���ö�ʱ��T1,128��Ƶ��ģ����ģʽ����0������T1CC0
    T1CC0L=62500%256;
    T1CC0H=62500/256;//0.5S һ���ж�
    T1CCTL0 |=0x04;//���ò���Ƚ�ͨ��0Ϊ�Ƚ�ģʽ�����Դ����ж�
    T1IE=1;//ʹ��TIMER1�ж�
    EA=1;//�������ж�
}
#pragma vector =T1_VECTOR
__interrupt void T1_ISR(void)
{
     time1++;
     adc++;
     if(time1>=2)
     {
       time1 =0;
     //uartTX_send('A');
     //uartTX_send('\n');
     }
}
