/****************************************************************************
* 文件名：I2CINT.C
* 功能：硬件I2C软件包，利用中断方式操作。
* 说明：主程序要配置好I2C总线接口(I2C引脚功能和I2C中断，并已使能I2C主模式)
****************************************************************************/
#include  "config.h" 

/* 以下为I2C操作时所需要的变量 */
volatile  uint8  I2C_sla;           // 从机地址(即器件地址)
volatile  uint8  I2C_suba;          // 子地址
volatile  uint8  *I2C_buf;          // 数据缓冲区指针 (读操作时会被更改)
volatile  uint8  I2C_num;           // 操作数据个数 (会被更改)
volatile  uint8  I2C_end;           // 操作结束标志，为1时表示操作结束，为0xFF时表示操作失败 (会被设置)
volatile  uint8  I2C_suba_en;       // 子地址使能控制，读操作时请设置为1，写操作时请设置为2 (会被更改)


/****************************************************************************
* 名称：IRQ_I2C()
* 功能：I2C中断，通过判断I2C状态字进行相应的操作。
* 入口参数：无
* 出口参数：无
****************************************************************************/
void  __irq  IRQ_I2C(void)
{  uint8  sta;

   sta = I2STAT;                    // 读出I2C状态字
   switch(sta)
   {  case  0x08:                   // 己发送起始条件
            if(1==I2C_suba_en) I2DAT = I2C_sla&0xFE;    // 指定子地址读时，先写入地址
              else I2DAT = I2C_sla;                     // 否则直接发送从机地址
            I2CONCLR = 0x28;        // SI=0
            break;
            
      case  0x10:
            I2DAT = I2C_sla;        // 重启动总线后，发送从地址
            I2CONCLR = 0x28;        // SI=0
            break;
   
      case  0x18:                   // 已发送SLA+W，并已接收应答
            if(0==I2C_suba_en)      // 无子地址，则直接发送数据
            {  if(I2C_num>0)
               {  I2DAT = *I2C_buf++;
                  I2CONCLR = 0x28; 
                  I2C_num--;
               }
               else
               {  I2CONSET = 0x10;  // 无数据发送，结束总线
                  I2CONCLR = 0x28;
                  I2C_end = 1;      // 设置总线操作结束标志
               }
               break;
            }
            if(1==I2C_suba_en)      // 发送子地址
            {  I2DAT = I2C_suba;
               I2CONCLR = 0x28;
            }
            if(2==I2C_suba_en)
            {  I2DAT = I2C_suba;
               I2CONCLR = 0x28;
               I2C_suba_en = 0;     // 子地址己处理
            }
            break;
            
      case  0x28:                   // 已发送I2C数据，并接收到应答
            if(0==I2C_suba_en)      // 无子地址，则直接发送数据
            {  if(I2C_num>0)
               {  I2DAT = *I2C_buf++;
                  I2CONCLR = 0x28; 
                  I2C_num--;
               }
               else
               {  I2CONSET = 0x10;  // 无数据发送，结束总线
                  I2CONCLR = 0x28;
                  I2C_end = 1; 
               }
               break;
            }
            if(1==I2C_suba_en)      // 若是指定地址读，则重新启动总线
            {  I2CONSET = 0x20;
               I2CONCLR = 0x08;
               I2C_suba_en = 0;     // 子地址己处理
            }
            break;
   
   
      case  0x20:
      case  0x30:
      case  0x38:
            I2CONCLR = 0x28;        // 总线进入不可寻址从模式
            I2C_end = 0xFF;         // 总线出错,设置标志
            break;
   
   
      case  0x40:                   // 己发送SLA+R，并已接收到应答
            if(1==I2C_num)          // 最后一字节，接收数据后发送非应答信号
            {  I2CONCLR = 0x2C;     // AA=0，接收到数据后产生非应答
            }
            else                    // 接收数据并发送应答信号
            {  I2CONSET = 0x04;     // AA=1，接收到数据后产生应答
               I2CONCLR = 0x28;
            }
            break;
            
      case  0x50:
            *I2C_buf++ = I2DAT;     // 读取数据
            I2C_num--;
            if(1==I2C_num)
            {  I2CONCLR = 0x2C;     // AA=0，接收到数据后产生非应答
            }
            else
            {  I2CONSET = 0x04;     // AA=1，接收到数据后产生应答
               I2CONCLR = 0x28;
            }
            break;
      
      case  0x58:
            *I2C_buf++ = I2DAT;     // 读取最后一字节数据
            I2CONSET = 0x10;        // 结束总线
            I2CONCLR = 0x28;
            I2C_end = 1; 
            break;
      
      case  0x48:
            I2CONCLR = 0x28;        // 总线进入不可寻址从模式
            I2C_end = 0xFF; 
            break;
            
      default: 
            break;
   }
   

   VICVectAddr = 0x00;              // 中断处理结束
}



/****************************************************************************
* 名称：ISendByte()
* 功能：向无子地址器件发送一字节数据。
* 入口参数：sla		器件地址
*          dat		要发送的数据
* 出口参数：返回值为0时表示出错，为1时表示操作正确。
* 说明：使用前要初始化好I2C引脚功能和I2C中断，并已使能I2C主模式
****************************************************************************/
uint8  ISendByte(uint8 sla, uint8 dat)
{  /* 参数设置 */
   I2C_sla = sla;		// 写操作的器件地址
   I2C_buf = &dat;		// 待发送的数据
   I2C_num = 1;			// 发送1字节数据
   I2C_suba_en = 0;		// 无子地址
   I2C_end = 0;
   
   I2CONCLR = 0x2C;
   I2CONSET = 0x60;             // 设置为主机，并启动总线
   
   while(0==I2C_end);
   if(1==I2C_end) return(1);
     else return(0);
}



/****************************************************************************
* 名称：ISendStr()
* 功能：向有子地址器件发送多字节数据。
* 入口参数：sla		器件从机地址
*          suba		器件子地址
*          s		数据发送缓冲区指针
*          no		发送数据个数
* 出口参数：返回值为0时表示出错，为1时表示操作正确。
* 说明：使用前要初始化好I2C引脚功能和I2C中断，并已使能I2C主模式
****************************************************************************/
uint8  ISendStr(uint8 sla, uint8 suba, uint8 *s, uint8 no)
{  /* 参数设置 */
   I2C_sla = sla;		// 写操作的器件地址
   I2C_suba = suba;		// 子地址
   I2C_buf = s;			
   I2C_num = no;	
   I2C_suba_en = 2;		// 有子地址写
   I2C_end = 0;
   
   I2CONCLR = 0x2C;
   I2CONSET = 0x60;             // 设置为主机，并启动总线
   
   while(0==I2C_end);
   if(1==I2C_end) return(1);
     else return(0);
}



/****************************************************************************
* 名称：IRcvByte()
* 功能：向无子地址器件读取一字节数据。
* 入口参数：sla		器件地址
*          dat		接收数据的变量指针
* 出口参数：返回值为0时表示操作出错，为1时表示操作正确。
* 说明：使用前要初始化好I2C引脚功能和I2C中断，并已使能I2C主模式
****************************************************************************/
uint8  IRcvByte(uint8 sla, uint8 *dat)
{  /* 参数设置 */
   I2C_sla = sla+1;		// 读操作的器件地址
   I2C_buf = dat;
   I2C_num = 1;
   I2C_suba_en = 0;		// 无子地址
   I2C_end = 0;
   
   I2CONCLR = 0x2C;
   I2CONSET = 0x60;             // 设置为主机，并启动总线
   
   while(0==I2C_end);
   if(1==I2C_end) return(1);
     else return(0);
}



/****************************************************************************
* 名称：IRcvStr()
* 功能：向有子地址器件读取多字节数据。
* 入口参数：sla		器件地址
*          suba		器件子地址
*          s		数据接收缓冲区指针
*	   	   no 		读取数据个数
* 出口参数：返回值为0时表示操作出错，为1时表示操作正确。
* 说明：使用前要初始化好I2C引脚功能和I2C中断，并已使能I2C主模式
****************************************************************************/
uint8  IRcvStr(uint8 sla, uint8 suba, uint8 *s, uint8 no)
{  if(0==no) return(0);
   
   /* 参数设置 */
   I2C_sla = sla+1;		// 读操作的器件地址
   I2C_suba = suba;		
   I2C_buf = s;
   I2C_num = no;
   I2C_suba_en = 1;		// 有子地址读
   I2C_end = 0;
   
   I2CONCLR = 0x2C;
   I2CONSET = 0x60;             // 设置为主机，并启动总线
   
   while(0==I2C_end);
   if(1==I2C_end) return(1);
     else return(0);
}

