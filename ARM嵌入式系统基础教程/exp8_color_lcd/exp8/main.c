/****************************************************************************************
* �� �� ����main.c
* ��    �ܣ�ͨ��ͼ�κ����ӿڣ���ʾ���β��ĸ���Ҷ�ƽ�����
* ˵    ������JP3�̽ӡ�
****************************************************************************************/
#include "config.h"
#include <math.h>
#define PI 3.1415
#define key   0x0000000F<<16
#define TEST   0x80000000
#define left  0x00000001<<27
#define right 0x00000001<<28
#define up    0x00000001<<29
#define down  0x00000001<<30
/*#define left  0x01<<14
#define right 0x01<<15
#define up    0x01<<16
#define down  0x01<<17*/

char  h_shift=0,v_shift=0;

/****************************************************************************
* ��    �ܣ���ʼ������������ϵ
* ��ڲ�������
* ���ڲ�������
****************************************************************************/
void  Coordinate(void)
{
    GUI_FillSCR(BLACK);               // ����ɫ���� WHITE 
    GUI_HLine(  0,  32 , 96, WHITE);    // �滭x������  BLACK
    GUI_RLine(48,   0 , 64, WHITE);    // �滭y������
}

/****************************************************************************
* ��    �ܣ���ʾ���β��ĸ���Ҷ�ƽ�����
* ��ڲ�������
* ���ڲ�������
****************************************************************************/

void __irq EINT_ISR(void)
{
	
//	flag = VICIRQStatus;
	
//	if(flag & right!=0)
	h_shift=h_shift+6;
//	if(flag &up!=0)
//		 v_shift++;
	
		 
	EXTINT   = 0x08;
	VICVectAddr = 0;

}
void INT_Init(void)
{
//	PINSEL0 &=0x0fffffff;
//	PINSEL0 |=0x2<<28;
	
	PINSEL1 &=0x0fffffff;
	PINSEL1 |=0x20000000;
	PINSEL2 =0;
	IO1DIR = TEST;
	
	EXTMODE  = 0x01<<3;
	EXTPOLAR = 0x00;
	EXTINT   = 0x0f;
	
	VICIntSelect =0x00;
	VICVectCntl0=0x20|17;
	VICVectAddr0=(uint32)EINT_ISR;
	VICIntEnable = 0x01<<17;

}
void DELAY( uint16 del)
{
	uint16 i;
	for(del;del>0;del--)
		for(i=500;i>0;i--);
	
	
	
	
	}

int  main(void)
{   
    float   x,y; 
    
   
	 
	TCOLOR data[96];
	int i = 0;
	for(; i<32; ++i)
	{
		data[i] = RED;
	}
	for(; i<64; ++i)
	{
		data[i] = GREEN;
	}
    for(; i<96; ++i)
	{
		data[i] = BLUE;
	}	
    
    PINSEL2 =0;
	IO1DIR = TEST;  
//	IRQEnable();
 
	// ��ʼ��LCM
    GUI_Initialize();	
   // IO0DIR &= ~(left|right|up|down); 
    while(1)
    {
     
      Coordinate(); // ��ʼ������������ϵ 
   	        
      
      /* ���ƿ��ƶ������� */  
     
      
     
       
       
       // h_shift=h_shift+6;
       /* GUI_HLine(  15,  15 , 75, RED);    // �滭x������  RED
        GUI_HLine(  15,  55 , 75, RED);    // �滭y������
        GUI_RLine(  15,  15 , 55, RED);    // �滭x������  RED
        GUI_RLine(  75,  15 , 55, RED);    // �滭y������*/
     
/*       if(h_shift >=96)
       		h_shift =0;
        GUI_HLine(  0+h_shift,  36+v_shift , 6+h_shift, RED);    // �滭x������  RED
        GUI_HLine(0+h_shift,   40+v_shift , 6+h_shift, RED);    // �滭y������
        GUI_RLine( 0+h_shift,  36+v_shift , 40+v_shift, RED);    // �滭x������  RED
        GUI_RLine(6+h_shift,   36+v_shift , 40+v_shift, RED);    // �滭y������
  		
  	  */
  	  if((IO1PIN & (1<<16)) == 0 )
	       {
	       
	       	 IO1SET  = TEST; 
	       	
	       
	 //      	break;	
	       	        
	       }
  	  
  	  
  	//   while(1)
  //    {
  //    	 	
  //    }
	      /* if(IO0PIN & left == 0 )
	       {
	       	 break;
	         while(IO0PIN & left==0);
	         h_shift--;
	         break;
	       
	       }
	        if(IO0PIN & right == 0 )
	       {
	       	 break;
	         while(IO0PIN & right ==0);
	         h_shift++;
	         break;
	       }
	        if(IO0PIN & up == 0 )
	       {
	         while(IO0PIN & up ==0);
	         v_shift++;
	         break;
	       }
	        if(IO0PIN & down == 0 )
	       {
	         while(IO0PIN & down ==0);
	         v_shift--;
	         break;
	       }*/
      
  		 /* ȫ������+��+����ɫ */
  		//LCD_FillAll_S(data);
  		 
  		 /* ������Ҳ��� */
  		 
  
     /*   for(i=0; i<96; i++)              
        {    
            x =  -PI +2.0*PI*i/95.0;           
            y = (32.0*sin(x) + 32.0); 
            GUI_Point(i, 62.0-y, WHITE);
        }*/
        
    }
    return 0;
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/