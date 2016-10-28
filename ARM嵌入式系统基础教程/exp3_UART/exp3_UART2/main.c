/****************************************************************************
* 文 件名：main.c
* 功   能：使用串口UART0接收上位机发送的数据，当接收到8个连续数据后，将接收计数值加一后输
*          出LED1--LED8显示，并将数据原封不动地发送回上位机。
* 说   明：将跳线器JP23全部短接。
*          通讯波特率115200，8位数据位，1位停止位，无奇偶校验。
*          中断服务程序不响应单字节发送累计至8 Bytes的情况，所以PC机必须连续发送8 Bytes。
****************************************************************************/
#include  "config.h" 

#define   LEDCON    0x00ff0000

/* 定义串口模式设置数据结构 */
typedef  struct  UartMode
{  
    uint8 datab;     		// 字长度，5/6/7/8
    uint8 stopb; 			// 停止位，1/2
    uint8 parity;  			// 奇偶校验位，0为无校验，1奇数校验，2为偶数校验
}   UARTMODE;

uint8  rcv_buf[8];          // UART0数据接收缓冲区
volatile uint8  rcv_new;    // 接收新数据标志


/****************************************************************************
* 名    称：IRQ_UART0()
* 功    能：串口UART0接收中断。
* 入口参数：无
* 出口参数：无
****************************************************************************/
void   __irq IRQ_UART0(void)
{  
    uint8  i;
     
    if( 0x04==(U0IIR&0x0F) ) rcv_new = 1;	// 设置接收到新的数据标志
    for(i=0; i<8; i++)
    {
        rcv_buf[i] = U0RBR;              	// 读取FIFO的数据，并清除中断标志
    }
    VICVectAddr = 0x00;              		// 中断处理结束
}               

/****************************************************************************
* 名    称：SendByte()
* 功    能：向串口UART0发送字节数据。
* 入口参数：data                要发送的数据
* 出口参数：无
****************************************************************************/
void  SendByte(uint8 data)
{  
    U0THR = data;                      		// 发送数据
}

/****************************************************************************
* 名称：ISendBuf()
* 功能：将缓冲区的数据发送回主机(使用FIFO)，并等待发送完毕。
* 入口参数：无
* 出口参数：无
****************************************************************************/
void  ISendBuf(void)
{  
    uint8  i;
  
    for(i=0; i<8; i++) SendByte(rcv_buf[i]);
    while( (U0LSR&0x40)==0 );         		// 等待数据发送
}               
                   
/****************************************************************************
* 名    称：UART0_Init()
* 功    能：初始化串口0。设置其工作模式及波特率。
* 入口参数：baud                波特率
*          set          模式设置(UARTMODE数据结构)
* 出口参数：返回值为1时表示初化成功，为0表除参数出错
****************************************************************************/
uint8  UART0_Init(uint32 baud, UARTMODE set)
{   uint32  bak;
   
    /* 参数过滤 */
    if( (0==baud)||(baud>115200) ) 
    {
        return(0);
    }
    if( (set.datab<5)||(set.datab>8) ) 
    {
        return(0);
    }
    if( (0==set.stopb)||(set.stopb>2) ) 
    {
        return(0);
    }
    if( set.parity>4 )
    {
        return(0);
    }

    /* 设置串口波特率 */
    U0LCR = 0x80;                        	// DLAB位置1
    bak = (Fpclk>>4)/baud;
    U0DLM = bak>>8;
    U0DLL = bak&0xff;
   
    /* 设置串口模式 */
    bak = set.datab-5;                   	// 设置字长度
    if(2==set.stopb) 
    {
       bak |= 0x04;				        	// 判断是否为2位停止位  
    }
    if(0!=set.parity) 
    {
        set.parity = set.parity-1; 
        bak |= 0x08;
    }
    bak |= set.parity<<4;              		// 设置奇偶校验
    U0LCR = bak;

    return(1);
}


void delay(int num)
{
 int i,j;
 for(i=num;i>=0;i--)
 {
   for(j=1000;j>=0;j--)
   {
   }
 }
}
        
/****************************************************************************
* 名    称：main()
* 功    能：初始化串口，并等待接收到串口数据。
****************************************************************************/
int  main(void)
{   uint8     rcv_counter;
    uint8   flash_num=0;
    UARTMODE  uart0_set;
    
    IRQEnable();
            
    PINSEL0 = 0x00000005;                	// 设置I/O连接到UART0
    
    /* PINSEL2使用启动代码的默认配置，切勿任意配置PINSEL2，否则总线会受到干扰 */ 
    IO1DIR = LEDCON;
    IO0DIR = 0x00000080;
               
    rcv_new = 0;                         	// 接收标志为0
    uart0_set.datab = 8;                 	// 8位数据位
    uart0_set.stopb = 1;                 	// 1位停止位
    uart0_set.parity = 0;                	// 无奇偶校验
    UART0_Init(57600, uart0_set);        	// 初始化串口模式
   
    U0FCR = 0x81;                        	// 使能FIFO，并设置触发点为8字节
    U0IER = 0x01;                        	// 允许RBR中断，即接收中断
   
    /* 设置中断允许 */
    VICIntSelect = 0x00000000;           	// 设置所有通道为IRQ中断
    VICVectCntl0 = 0x26;        			// UART0中断通道分配到IRQ slot 0，即优先级最高
    VICVectAddr0 = (int)IRQ_UART0;       	// 设置UART0向量地址
    VICIntEnable = 0x00000040;           	// 使能UART0中断
   
    rcv_counter = 0;
    IO1SET = 0xffffffff;
    IO0SET = 0xffffffff;

    while(1)             					// 等待中断
    { 

        if(1==rcv_new)  					// 是否已经接收到8 Bytes的数据
        {  
           rcv_new = 0;       				// 清除标志
           ISendBuf();        				// 将接收到的数据发送回主机

           if(rcv_buf[0]=='0' && rcv_buf[1]=='x' && rcv_buf[2]=='A' && rcv_buf[3]=='A')
           {
             flash_num = ((uint8)rcv_buf[6]-48)*16;
             flash_num = flash_num + ((uint8)rcv_buf[7]-48);
             
             while(flash_num>0)
             {
               flash_num--;
               IO0CLR = 0xffffffff;
               delay(3000);
               IO0SET = 0xffffffff;
               delay(3000);
             }
           } 
           if(rcv_buf[0]=='0' && rcv_buf[1]=='x' && rcv_buf[2]=='5' && rcv_buf[3]=='5')
           {
             flash_num = ((uint8)rcv_buf[6]-48)*16;
             flash_num = flash_num + ((uint8)rcv_buf[7]-48);
             
             while(flash_num>0)
             {
               flash_num--;
               IO1CLR = 0xffffffff;
               delay(3000);
               IO1SET = 0xffffffff;
               delay(3000);
             }
           } 
        }
    }
    return(0);
}
