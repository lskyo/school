/****************************************************************************
* 文 件 名：main.c
* 功    能：LED显示控制。
*           通过GPIO控制步进电机
* 说    明：将跳线JP14和JP19全部短接。      
****************************************************************************/
#include  "config.h"

#define   LED1      1<<16       // P2.16  
#define   MOTOD	    1<<24       // P2.24  
#define   MOTOC		1<<25		// P2.25 
#define   MOTOB 	1<<26		// P2.26 
#define   MOTOA		1<<27		// P2.27 
#define   LEDCON	0x00ff0000  // LED控制字
#define   MOTOCON	0x0f000000  // MOTO控制字
#define   GPIOSET(PIN)  IO1SET = PIN    // 方便修改置位端口
#define   GPIOCLR(PIN)	IO1CLR = PIN    // 方便修改清位端口

void DelayNS(uint32  dly);
void MOTO_Mode1(uint8 i);               // A-B-C-D
void MOTO_Mode2(uint8 i);               // AB-BC-CD-DA-AB
void MOTO_Mode3(uint8 i);               // A-AB-B-BC-C-CD-D-DA-A
                      
/****************************************************************************
* 名    称：main()
* 功    能：根据表DISP_TAB来控制LED显示。
****************************************************************************/
int  main(void)
{   	
    /* PINSEL2使用启动代码的默认配置，切勿任意配置PINSEL2，否则总线会受到干扰 */ 
    IO1DIR = LEDCON | MOTOCON;      // 配置LED控制I/O方向
      
    MOTO_Mode1(1);               // A-B-C-D
 //   MOTO_Mode2(10);               // AB-BC-CD-DA-AB
    //MOTO_Mode3(10);               // A-AB-B-BC-C-CD-D-DA-A

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
        for(i=0; i<20000; i++);
    }
}

/****************************************************************************
* 名    称：MOTO_Mode1()
* 功    能：单四拍程序
* 入口参数：uint8 i		延时参数，值越大，延时越久
* 出口参数：无
****************************************************************************/
void MOTO_Mode1(uint8 i)            // A-B-C-D
{



    while(1)
    {
        GPIOCLR(LED1);              // 点亮LED1，方便监视程序状态
        /* A */
        GPIOSET(MOTOA);
        DelayNS(i);
        GPIOCLR(MOTOA);
        /* B */
        GPIOSET(MOTOB);
        DelayNS(i);
        GPIOCLR(MOTOB);
        /* C */
        GPIOSET(MOTOC); 
        DelayNS(i);
        GPIOCLR(MOTOC);

        GPIOSET(LED1);              //  熄灭LED1，方便监视程序状态
        /* D */
       GPIOSET(MOTOD);            
        DelayNS(i);
        GPIOCLR(MOTOD);
    }
}

/****************************************************************************
* 名    称：MOTO_Mode2()
* 功    能：双四拍程序
* 入口参数：uint8 i		延时参数，值越大，延时越久
* 出口参数：无
****************************************************************************/
void MOTO_Mode2(uint8 i)            // AB-BC-CD-DA-AB
{  
    while(1)
    {
        GPIOCLR(LED1);              // 点亮LED1，方便监视程序状态
        /* AB */
        GPIOSET(MOTOA);
        GPIOSET(MOTOB);
        DelayNS(i);
        GPIOCLR(MOTOA);
        GPIOCLR(MOTOB);
        /* BC */
        GPIOSET(MOTOB);
        GPIOSET(MOTOC);
        DelayNS(i);
        GPIOCLR(MOTOB);
        GPIOCLR(MOTOC);

        GPIOSET(LED1);              //  熄灭LED1，方便监视程序状态
        /* CD */
        GPIOSET(MOTOC);
        GPIOSET(MOTOD);
        DelayNS(i);
        GPIOCLR(MOTOC);
        GPIOCLR(MOTOD);
        /* DA */
        GPIOSET(MOTOD);            
        GPIOSET(MOTOA);
        DelayNS(i);
        GPIOCLR(MOTOD);
        GPIOCLR(MOTOA);
    }
}

/****************************************************************************
* 名    称：MOTO_Mode3()
* 功    能：单双八拍程序
* 入口参数：uint8 i		延时参数，值越大，延时越久
* 出口参数：无
****************************************************************************/
void MOTO_Mode3(uint8 i)            // A-AB-B-BC-C-CD-D-DA-A
{
    while(1)	
    {  
        GPIOCLR(LED1);              // 点亮LED1，方便监视程序状态
        /* A */
        GPIOSET(MOTOA);
        DelayNS(i);
        GPIOCLR(MOTOA);
        /* AB */
        GPIOSET(MOTOA);
        GPIOSET(MOTOB);
        DelayNS(i);
        GPIOCLR(MOTOA);
        GPIOCLR(MOTOB);
        /* B */
        GPIOSET(MOTOB);
        DelayNS(i);
        GPIOCLR(MOTOB);
        /* BC */
        GPIOSET(MOTOB);
        GPIOSET(MOTOC);
        DelayNS(i);
        GPIOCLR(MOTOB);
        GPIOCLR(MOTOC);
        /* C */
        GPIOSET(MOTOC); 
        DelayNS(i);
        GPIOCLR(MOTOC);

        GPIOSET(LED1);              //  熄灭LED1，方便监视程序状态
        /* CD */
        GPIOSET(MOTOC);
        GPIOSET(MOTOD);
        DelayNS(i);
        GPIOCLR(MOTOC);
        GPIOCLR(MOTOD);
        /* D */
        GPIOSET(MOTOD);
        DelayNS(i);
        GPIOCLR(MOTOD);
        /* DA */
        GPIOSET(MOTOD);            
        GPIOSET(MOTOA);
        DelayNS(i);
        GPIOCLR(MOTOD);
        GPIOCLR(MOTOA);
    }
}