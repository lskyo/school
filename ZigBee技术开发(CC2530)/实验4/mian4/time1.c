#include "time1.h"
#include "uart.h"
extern int time1;
extern int adc;
void time1_in()
{
    CLKCONCMD &=~0X40;   // 选择外部石英晶振32M
    while(!(SLEEPSTA&0X40));   // 等待晶振稳定
    CLKCONCMD &=~0X47;    //T1CHSPD二分频，CLKSPD不分频
    SLEEPCMD|=0X04; //关闭RC震荡器
    T1CTL|=0x0E;     //设置定时器T1,128分频，模计数模式，从0计数到T1CC0
    T1CC0L=62500%256;
    T1CC0H=62500/256;//0.5S 一次中断
    T1CCTL0 |=0x04;//设置捕获比较通道0为比较模式，用以触发中断
    T1IE=1;//使能TIMER1中断
    EA=1;//开启总中断
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
