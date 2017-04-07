/****************************************************************************
* �� �� ����main.c
* ��    �ܣ���ȡI/O����ֵ�����������LED
*           ʹ��I/O�����뷽ʽ��P0.20�ڽ���ɨ�裬��LED���ơ�
* ˵    ��������KEY1�����۲�LEDЧ����
****************************************************************************/
#include  "config.h"
#define	  BEECON	1<<7     		// P0.7���ſ���B1���͵�ƽLED��
#define   KEY       1<<20	        // ���尴��
#define   LEDCON	0x00ff0000






void  DelayNS(uint32  dly)
{   uint32  i;

    for(; dly>0; dly--) 
    {
        for(i=0; i<50000; i++);
    }
}





/****************************************************************************
* ��    �ƣ�main()
* ��    �ܣ���ȡP0.20�ڵ�ֵ����������ƺ�ɫLED�� D9��
****************************************************************************/
int  main(void)
{   
	uint32  keystate = 0;
    int j=0;

    PINSEL0 = 0x00000000;		    // ���ùܽ�����GPIO
    PINSEL1 = 0x00000000;		    // ���ùܽ�����GPIO   
    
    IO0DIR = BEECON;			    // ����B1���ƿ�Ϊ���������I/OΪ����
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
                    if((IO0PIN&KEY)==0) break;		//�жϰ����Ƿ��£���ʱ�����ı�
                    
                    IO1CLR = 1<<(16+j);   
                    DelayNS(10);	       
                    IO1SET = 0xffffffff;
                 }
    	}
    	else
    	{
    	        for(j=7;j>=0; j--)
                {   
                   if((IO0PIN&KEY)==0) break;     	//ͬ��
                   
                   IO1CLR = 1<<(16+j);   
                   DelayNS(10);	       
                   IO1SET = 0xffffffff;
                } 
    	}		
	}
    return(0);
}