/****************************************************************************
* 文 件 名：main.c
* 功    能：使用外部中断3进行D9的控制，每当有一次中断时，即取反D9控制口，
*           使用非向量中断方式。
* 说    明：将跳线器JP9、JP22短接，JP20断开。按下KEY1观察LED效果。
****************************************************************************/
#include  "config.h"
#define	  BEEPCON	1<<7	        // P0.7引脚控制D9，低电平LED亮1<<7 等价于 0x80
#define   LEDCON	0x00ff0000
int8  ioro=1;            //控制跑马灯正跑还是反跑


/****************************************************************************
* 名    称：IRQ_Eint3()
* 功    能：外部中断EINT3服务函数，取反B1控制口。
* 入口参数：无
* 出口参数：无
****************************************************************************/
void   __irq IRQ_Eint3(void)
{  
	uint32  i;
   
    i = IO0SET;					        // 读取当前D9控制值
    if( (i&BEEPCON)==0 )	            // 控制B1输出取反
    {  
        IO0SET = BEEPCON;
    }
    else
    {  
        IO0CLR = BEEPCON;
    }
    
    if(ioro==1)
      ioro=0;
    else
      ioro=1;
   
    /* 等待外部中断信号恢复为高电平(若信号保持为低电平，中断标志会一直置位) */
    while( (EXTINT&1<<3)!=0 )	
    {  
        EXTINT = 1<<3;			        // 清除EINT3中断标志，1<<3 等价于 0x08
    }
   
    VICVectAddr = 0;		            // 向量中断结束
}		
			
			
			
void  DelayNS(uint32  dly)
{   uint32  i;

    for(; dly>0; dly--) 
    {
        for(i=0; i<50000; i++);
    }
}
			

/****************************************************************************
* 名    称：main()
* 功    能：初始化外部中断3(EINT3)为非向量中断，并设置为电平触发模式，然后等待外部中断。
* 说    明：在STARTUP.S文件中使能IRQ中断(清零CPSR中的I位)。
****************************************************************************/
int  main(void)
{  
    int i;
    
    IRQEnable();                        // 开IRQ中断

    PINSEL1 = 3<<8;			            // 设置管脚连接，P0.20设置为EINT3
    IO0DIR = BEEPCON;			        // 设置D9控制口为输出，其它I/O为输入
                                   
    /* 打开EINT3中断(使用非向量IRQ) */
    VICIntSelect = 0x00000000;	        // 设置所有中断分配为IRQ中断
    VICVectAddr15 = (int)IRQ_Eint3;    // 设置中断服务程序地址
    VICVectCntl15 =0x20 | 17;
    EXTMODE = 0x00;				        // 设置EINT3中断为电平触发模式
    EXTINT = 1<<3;					    // 清除EINT3中断标志
    VICIntEnable = 1<<17;		    	// 使能EINT3中断，EINT3在Bit17上
    
    IO1DIR = LEDCON; 
       	    
    while(1)	
    {  
      if(ioro==0)
      {
        for(i=0; i<8; i++)
        {   
            if(ioro!=0)     //因为外部中断会改变ioro的值，此处判断ioro的值及时改变动作
            break;
            
            IO1CLR = 1<<(16+i);   
            DelayNS(10);	      
            IO1SET = 0xffffffff;
        } 
      }    
      else
      {   
        for(i=7; i>=0; i--)
        {   
            if(ioro==0)     //同上
            break;
            
            IO1CLR = 1<<(16+i);   
            DelayNS(10);	       
            IO1SET = 0xffffffff;
        } 
      }
   }
   return(0);
}