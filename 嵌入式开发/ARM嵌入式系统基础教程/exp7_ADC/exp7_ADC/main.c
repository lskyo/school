/****************************************************************************
* 文 件 名：main.c
* 功    能：使用ADC模块的通道0、1进行电压的测量，然后将转换结果从串口输出，

****************************************************************************/
#include  "config.h"
#include  <stdarg.h>
uint8 send_buf[16]; 

/****************************************************************************
* 名    称：DelayNS()
* 功    能：长软件延时
* 入口参数：dly		延时参数，值越大，延时越久
* 出口参数：无
****************************************************************************/
void  DelayNS(uint32  dly)
{  
    uint32  i;
    for(; dly>0; dly--) 
    {
        for(i=0; i<5000; i++);
    }
}


/****************************************************************************
* 名    称：UART0Init()
* 功    能：初始化串口0。设置为8位数据位，1位停止位，无奇偶校验
* 入口参数：bps 通讯波特率 
* 出口参数：无
****************************************************************************/
void  UART0Init(uint32 bps)
{  
    uint16 Fdiv;
    PINSEL0 = (PINSEL0 & (~0x0F)) | 0x05;	// 不影响其它管脚连接,设置I/O连接到UART0
    U0LCR = 0x83;							// DLAB = 1，可设置波特率
    Fdiv = (Fpclk / 16) / bps;				// 设置波特率
    U0DLM =0;							
    U0DLL = 0x12;		
    
    
   // U0DLM = Fdiv / 256;							
  //  U0DLL = Fdiv % 256;						
    U0LCR = 0x03;
}

/****************************************************************************
* 名    称：UART0SendByte()
* 功    能：向串口发送字节数据，并等待发送完毕。
* 入口参数：data  要发送的数据
* 出口参数：无
****************************************************************************/
void  UART0SendByte(uint8 data)
{  
    U0THR = data;							// 发送数据
    while( (U0LSR&0x20)==0 );				// 等待数据发送完毕
}


/****************************************************************************
* 名    称：UART0SendStr()
* 功    能：向串口发送一字符串
* 入口参数：srt		要发送的字符串的指针
* 出口参数：无
****************************************************************************/

void  UART0SendStr(char *str)
{  
    while(1)
    {  
        if( *str == '\0' ) break;
        UART0SendByte(*str++);				// 发送数据
    }
}
    
    
    
    
void  Time0Init(void)
{   /* Fcclk = Fosc*4 = 11.0592MHz*4 = 44.2368MHz
	   Fpclk = Fcclk/4 = 44.2368MHz/4 = 11.0592MHz
	*/
    T0PR = 9;			    					// 设置定时器0分频为10分频
	T0MCR = 0x03;		   						// 匹配通道0匹配中断并复位T0TC
	T0EMR = 3<<6;                              // 当发生匹配中断时，MAT0.1输出发生翻转
	T0MR0 = 110591;	    						// 比较值
	T0TCR = 0x03;		   						// 启动并复位T0TC
	T0TCR = 0x01; 
}

/****************************************************************************
* 名    称：main()
* 功    能：进行通道0、1电压ADC转换，并把结果转换成电压值，然后发送到串口。
* 说    明：在CONFIG.H文件中包含stdio.h。
****************************************************************************/
int  main(void)
{  
    uint32  ADC_Data;
    char    str[20];
    
    

    
    
    
    
    UART0Init(9600);							// 初始化UART0
    PINSEL1 = 0x01400000;						// 设置P0.27、P0.28连接到AIN0、AIN1
    Time0Init();
    /* 进行ADC模块设置，其中x<<n表示第n位设置为x(若x超过一位，则向高位顺延) */
    ADCR = (1 << 0)                     |		// SEL = 1 ，选择通道0
           ((Fpclk / 1000000 - 1) << 8) | 		// CLKDIV = Fpclk / 1000000 - 1 ，即转换时钟为1MHz
           (0 << 16)                    |		// BURST = 0 ，软件控制转换操作
           (0 << 17)                    | 		// CLKS = 0 ，使用11clock转换
           (1 << 21)                    | 		// PDN = 1 ， 正常工作模式(非掉电转换模式)
           (0 << 22)                    | 		// TEST1:0 = 00 ，正常工作模式(非测试模式)
           (4 << 24)                    | 		// START = 1 ，直接启动ADC转换
           (0 << 27);							// EDGE = 0 (CAP/MAT引脚下降沿触发ADC转换)
    DelayNS(10);								
    ADC_Data = ADDR;							// 读取ADC结果，并清除DONE标志位
   
       while(1)
    {  
        ADCR = (ADCR&0x00FFFF00)|0x01|(4 << 24);	// 设置通道1，并进行第一次转换
     //   while( (ADDR&0x80000000)==0 );	            // 等待转换结束
      //  ADCR = ADCR | (1 << 24);					// 再次启运转换
        while( (ADDR&0x80000000)==0 );              // 等待转换结束
        ADC_Data = ADDR;							// 读取ADC结果
        ADC_Data = (ADC_Data>>6) & 0x3FF;           // 提取AD转换值
        ADC_Data = ADC_Data * 3300/1024;                 // 数值转换
       
        sprintf(str, "VIN1=%dmV \r", ADC_Data);            
        UART0SendStr(str);
        DelayNS(100);
         
        ADCR = (ADCR&0x00FFFF00)|0x02|(4 << 24);	// 设置通道2，并进行第一次转换
    //    while( (ADDR&0x80000000)==0 );			    // 等待转换结束
    //    ADCR = ADCR | (1 << 24);					// 再次启运转换
        while( (ADDR&0x80000000)==0 );              // 等待转换结束
        ADC_Data = ADDR;							// 读取ADC结果
        ADC_Data = (ADC_Data>>6) & 0x3FF;           // 提取AD转换值
        ADC_Data = ADC_Data * 3300/1024;                 // 数值转换
       
        sprintf(str, "VIN2=%dmV \r", ADC_Data);           
        UART0SendStr(str); 
    DelayNS(100);
    }

  }
