/****************************************************************************
* 文 件 名：main.c
* 功    能：使用PWM5控制电机转速，共4档。
* 说    明：将跳线JP4，JP9短接。
****************************************************************************/
#include  "config.h"
#define   KEY				    1<<20       // 定义按键
#define   P0_22             	1<<22       // GPIO
#define   P0_21             	1<<21       // GPIO
                 
/* PWM周期及占空比设置值 */
#define  CYCLE_DATA			    20000  	// 定义周期
#define  DUTY_CYCLE_DATA		2000   	// 定义基本占空比参数

void DelayNS(uint32  dly);

/****************************************************************************
* 名称：main()
* 功能：主函数
****************************************************************************/
int  main(void)
{   uint8 i = 1;

    PINSEL1 = 0x01 << 10;		    // 设置PWM5连接到P0.21管脚
    IO0DIR  = P0_22;
	IO0CLR  = P0_22;                // 将P0.22置低，配合PWM控制   
  //IO0CLR  = P0_22; 
  //IO0SET  = P0_22;
    PWMPR  = 0x00;                  // 不分频，计数频率为Fpclk
    PWMMCR = 0x02;					// 设置PWMMR0匹配时复位PWMTC
    PWMMR0 = CYCLE_DATA;     		// 设置PWM周期
    PWMMR5 = DUTY_CYCLE_DATA;		// 设置PWM占空比
   
    PWMLER = 1 << 0 | 1<< 5;        // PWMMR0、PWMMR5锁存
    PWMPCR = 1 << 13;	            // 允许PWM5输出，单边PWM
    PWMTCR = 0x09;			 		// 启动定时器，PWM使能
   
    while(1)
    {
        PWMMR0 = CYCLE_DATA;         //PROTEUS下 这句话不能少
        PWMMR5 = DUTY_CYCLE_DATA*i;	// 设置PWM占空比
        PWMLER = 1 << 0 | 1<< 5;    // PWMMR0、PWMMR5锁存
        PWMTCR = 0x09;				// 启动定时器，PWM使能

        if( (IO0PIN&KEY) == 0 ) 
        {
            DelayNS(20);
            if( (IO0PIN&KEY) == 0 ) 
            {
                i = i+1;
                while( (IO0PIN&KEY) == 0 );
                if(i >= 11)  i = 1;
            }
        }
    }
    return(0);
}

/****************************************************************************
* 名    称：DelayNS()
* 功    能：长软件延时
* 入口参数：dly		延时参数，值越大，延时越久
* 出口参数：无
****************************************************************************/
void DelayNS(uint32  dly)
{   uint32  i;

    for(; dly>0; dly--) 
    {
        for(i=0; i<500; i++);
    }
}
