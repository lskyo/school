/****************************************************************************
* 文 件 名：main.c
* 功    能：读取I/O引脚值，并输出控制LED
*           使用I/O口输入方式对P0.20口进行扫描，对LED控制。
* 说    明：按动KEY1按键观察LED效果。
****************************************************************************/
#include  "config.h"
#define	  BEECON	1<<7     		// P0.7引脚控制B1，低电平LED亮
#define   KEY       1<<20	        // 定义按键
#define   LEDCON	0x00ff0000






void  DelayNS(uint32  dly)
{   uint32  i;

    for(; dly>0; dly--) 
    {
        for(i=0; i<50000; i++);
    }
}





/****************************************************************************
* 名    称：main()
* 功    能：读取P0.20口的值，并输出控制红色LED灯 D9。
****************************************************************************/
int  main(void)
{   
	uint32  keystate = 0;
    int j=0;

    PINSEL0 = 0x00000000;		    // 设置管脚连接GPIO
    PINSEL1 = 0x00000000;		    // 设置管脚连接GPIO   
    
    IO0DIR = BEECON;			    // 设置B1控制口为输出，其它I/O为输入
    IO1DIR = LEDCON; 
    
    while(1)	
    {  	
    
  
    	if( (IO0PIN&KEY)==0 ) 
    	{ 
    	    
    		if(keystate)
    		{   
    		    keystate = 0;
    			IO0CLR |= BEECON;
    		}
    		else
    		{
    			keystate = 1;
    			IO0SET |=  BEECON;
    	    }
    	    while((IO0PIN&KEY)==0);
    	} 
    	
    	if(keystate == 1)
    	{ 
    	         for(j=0; j<8; j++)
                 {   
                    if((IO0PIN&KEY)==0) break;		//判断按键是否按下，及时做出改变
                    
                    IO1CLR = 1<<(16+j);   
                    DelayNS(10);	       
                    IO1SET = 0xffffffff;
                 }
    	}
    	else
    	{
    	        for(j=7;j>=0; j--)
                {   
                   if((IO0PIN&KEY)==0) break;     	//同上
                   
                   IO1CLR = 1<<(16+j);   
                   DelayNS(10);	       
                   IO1SET = 0xffffffff;
                } 
    	}		
	}
    return(0);
}