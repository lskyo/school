/****************************************************************************
* 文 件 名：main.c
* 功    能：
*           
* 说    明：
*           
****************************************************************************/
#include  "config.h"
#include  "lcddriver.h"

#define SI  1<<0
#define SCL 1<<1
#define WR  1<<9
#define A0  1<<8
#define CS  1<<10


/* 定义显示缓冲区(可根据情况定义或直接使用LCM显示存储空间) */
TCOLOR  gui_disp_buf[GUI_LCM_YMAX][GUI_LCM_XMAX];



/****************************************************************************
* 名    称：DelayNS()
* 功    能：长软件延时
* 入口参数：dly		延时参数，值越大，延时越久
* 出口参数：无
****************************************************************************/
void  DelayNS(uint32  dly)
{   uint32  i;

    for(; dly>0; dly--) 
    {
        for(i=0; i<50; i++);
    }
}
         
void WR_CMD(char cmd)
{
int i;
  IO0CLR =A0;
  IO0CLR=0xFF;
  
  
  IO0CLR =WR;
  IO0CLR =CS;
  
  IO0SET=cmd;  
   DelayNS(2);
  IO0SET =WR;
   DelayNS(2);


  IO0SET =CS;


}



void WR_DATA(char dat)
{
  int i;
  IO0SET =A0;
  IO0CLR=0xFF;

  IO0CLR =WR;
  IO0CLR =CS;
  
  IO0SET=dat;  
  DelayNS(2);  
  IO0SET =WR;
  DelayNS(2);

  IO0SET =CS;
}         
    
    

 
/***********************************************************************
* 名称：LCD_Initialize()
* 功能：LCM初始化。将LCM初始化为纯图形模式，显示起始地址为0x0000。
* 入口参数：无
* 出口参数：无
* 说明：
***********************************************************************/
    
void  LCD_Initialize( )
{

  IO0DIR = 0xff|WR|A0|CS;    
  
   WR_CMD(0xD1);
   WR_CMD(0x94);//
           
    
   WR_CMD(0x20);  
   WR_DATA(0x0f);  
  
   WR_CMD(0x81);      
   WR_DATA(0x22);        
   WR_DATA(0x06);   
     
   WR_CMD(0xAF); 

}


/****************************************************************************
* 名称：GUI_Point()
* 功能：在指定位置上画点。
* 入口参数： x		指定点所在列的位置
*           y		指定点所在行的位置
*           color	显示颜色(对于黑白色LCM，为0时灭，为1时显示)
* 出口参数：返回值为1时表示操作成功，为0时表示操作失败。(操作失败原因是指定地址超出有
*          效范围)
* 说明：用户根据LCM的实际情况编写此函数。对于单色，只有一个位有效，则要使用左移的方法
*      实现point_dat = (point_dat&MASK_TAB [i]) | (color<<n)，其它位数的一样
*      处理。
****************************************************************************/
uint8  GUI_Point(uint32 x, uint32 y, TCOLOR color)
{  /* 参数过滤 */
   if(x>=GUI_LCM_XMAX) return(0);
   if(y>=GUI_LCM_YMAX) return(0);
   
     WR_CMD(0xBC); 
     WR_DATA(0);   
     WR_DATA(00);    
     WR_DATA(00);     
       
     WR_CMD(0x75); 
     WR_DATA(y);    WR_DATA(y);
     
     WR_CMD(0x15); 
     WR_DATA(x);    WR_DATA(x);    
     WR_CMD(0x5c); 
     
            
    WR_DATA(color);    
    WR_DATA(color>>8);
 
   return(1);
}
 
 

/***********************************************************************
* 名称：LCD_FillAll()
* 功能：LCD填充。以图形方式进行填充，起始地址为0x0000。
* 入口参数：dat		要填充的颜色数据
* 出口参数：无
***********************************************************************/
    
  void  LCD_FillAll(TCOLOR dat)
   {                  
       int i,j;  
     
     WR_CMD(0xBC); 
     WR_DATA(0);   
     WR_DATA(00);    
     WR_DATA(00);     
       
     WR_CMD(0x75); 
     WR_DATA(0);    WR_DATA(63);
     WR_CMD(0x15); 
     WR_DATA(0);    WR_DATA(95);    
     WR_CMD(0x5c); 
     
            
        for(j=0;j<GUI_LCM_YMAX;j++)   {
        for(i=0;i<GUI_LCM_XMAX;i++)    {
            WR_DATA(dat);    
            WR_DATA(dat>>8);
          }
     }
} 

 void  LCD_FillAll_S(TCOLOR dat[96])
   {                  
       int i,j;  
     
     WR_CMD(0xBC); 
     WR_DATA(0);   
     WR_DATA(00);    
     WR_DATA(00);     
       
     WR_CMD(0x75); 
     WR_DATA(0);    WR_DATA(63);
     WR_CMD(0x15); 
     WR_DATA(0);    WR_DATA(95);    
     WR_CMD(0x5c); 
     
            
        for(j=0;j<GUI_LCM_YMAX;j++)   {
        for(i=0;i<GUI_LCM_XMAX;i++)    {
            WR_DATA(dat[i]);    
            WR_DATA(dat[i]>>8);
          }
     }
} 
/****************************************************************************
* 名称：GUI_FillSCR()
* 功能：全屏填充。直接使用数据填充显示缓冲区。
* 入口参数：dat		填充的数据
* 出口参数：无
* 说明：用户根据LCM的实际情况编写此函数。
****************************************************************************/
void  GUI_FillSCR(TCOLOR dat)
{ 

   /* 填充LCM */
   LCD_FillAll(dat);
}



    

/****************************************************************************
* 名称：GUI_Initialize()
* 功能：初始化GUI，包括初始化显示缓冲区，初始化LCM并清屏。
* 入口参数：无
* 出口参数：无
* 说明：用户根据LCM的实际情况编写此函数。
****************************************************************************/
void  GUI_Initialize(void)
{  LCD_Initialize();					// 初始化LCM模块工作模式，纯图形模式
 //  GUI_FillSCR(0x00);					// 初始化缓冲区为0x00，并输出屏幕(清屏)
}




/****************************************************************************
* 名称：GUI_HLine()
* 功能：画水平线。
* 入口参数： x0		水平线起点所在列的位置
*           y0		水平线起点所在行的位置
*           x1      水平线终点所在列的位置
*           color	显示颜色(对于黑白色LCM，为0时灭，为1时显示)
* 出口参数：无
* 说明：对于单色、4级灰度的液晶，可通过修改此函数作图提高速度，如单色LCM，可以一次更
*      新8个点，而不需要一个点一个点的写到LCM中。
****************************************************************************/
void  GUI_HLine(uint32 x0, uint32 y0, uint32 x1, TCOLOR color) 
{  uint32  bak;

   if(x0>x1) 						// 对x0、x1大小进行排列，以便画图
   {  bak = x1;
      x1 = x0;
      x0 = bak;
   }
   
   do
   {  GUI_Point(x0, y0, color);		// 逐点显示，描出垂直线
      x0++;
   }while(x1>=x0);
}


/****************************************************************************
* 名称：GUI_RLine()
* 功能：画垂直线。
* 入口参数： x0		垂直线起点所在列的位置
*           y0		垂直线起点所在行的位置
*           y1      垂直线终点所在行的位置
*           color	显示颜色
* 出口参数：无
* 说明：对于单色、4级灰度的液晶，可通过修改此函数作图提高速度，如单色LCM，可以一次更
*      新8个点，而不需要一个点一个点的写到LCM中。
****************************************************************************/
void  GUI_RLine(uint32 x0, uint32 y0, uint32 y1, TCOLOR color) 
{  uint32  bak;

   if(y0>y1) 						// 对y0、y1大小进行排列，以便画图
   {  bak = y1;
      y1 = y0;
      y0 = bak;
   }
   do
   {  GUI_Point(x0, y0, color);		// 逐点显示，描出垂直线
      y0++;
   }while(y1>=y0);	
}



      
    
                 

