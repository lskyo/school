/****************************************************************************
* �� ������main.c
* ��   �ܣ�ʹ�ô���UART0������λ�����͵����ݣ������յ�8���������ݺ󣬽����ռ���ֵ��һ����
*          ��LED1--LED8��ʾ����������ԭ�ⲻ���ط��ͻ���λ����
* ˵   ������������JP23ȫ���̽ӡ�
*          ͨѶ������115200��8λ����λ��1λֹͣλ������żУ�顣
*          �жϷ��������Ӧ���ֽڷ����ۼ���8 Bytes�����������PC��������������8 Bytes��
****************************************************************************/
#include  "config.h" 

#define   LEDCON    0x00ff0000

/* ���崮��ģʽ�������ݽṹ */
typedef  struct  UartMode
{  
    uint8 datab;     		// �ֳ��ȣ�5/6/7/8
    uint8 stopb; 			// ֹͣλ��1/2
    uint8 parity;  			// ��żУ��λ��0Ϊ��У�飬1����У�飬2Ϊż��У��
}   UARTMODE;

uint8  rcv_buf[8];          // UART0���ݽ��ջ�����
volatile uint8  rcv_new;    // ���������ݱ�־


/****************************************************************************
* ��    �ƣ�IRQ_UART0()
* ��    �ܣ�����UART0�����жϡ�
* ��ڲ�������
* ���ڲ�������
****************************************************************************/
void   __irq IRQ_UART0(void)
{  
    uint8  i;
     
    if( 0x04==(U0IIR&0x0F) ) rcv_new = 1;	// ���ý��յ��µ����ݱ�־
    for(i=0; i<8; i++)
    {
        rcv_buf[i] = U0RBR;              	// ��ȡFIFO�����ݣ�������жϱ�־
    }
    VICVectAddr = 0x00;              		// �жϴ������
}               

/****************************************************************************
* ��    �ƣ�SendByte()
* ��    �ܣ��򴮿�UART0�����ֽ����ݡ�
* ��ڲ�����data                Ҫ���͵�����
* ���ڲ�������
****************************************************************************/
void  SendByte(uint8 data)
{  
    U0THR = data;                      		// ��������
}

/****************************************************************************
* ���ƣ�ISendBuf()
* ���ܣ��������������ݷ��ͻ�����(ʹ��FIFO)�����ȴ�������ϡ�
* ��ڲ�������
* ���ڲ�������
****************************************************************************/
void  ISendBuf(void)
{  
    uint8  i;
  
    for(i=0; i<8; i++) SendByte(rcv_buf[i]);
    while( (U0LSR&0x40)==0 );         		// �ȴ����ݷ���
}               
                   
/****************************************************************************
* ��    �ƣ�UART0_Init()
* ��    �ܣ���ʼ������0�������乤��ģʽ�������ʡ�
* ��ڲ�����baud                ������
*          set          ģʽ����(UARTMODE���ݽṹ)
* ���ڲ���������ֵΪ1ʱ��ʾ�����ɹ���Ϊ0�����������
****************************************************************************/
uint8  UART0_Init(uint32 baud, UARTMODE set)
{   uint32  bak;
   
    /* �������� */
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

    /* ���ô��ڲ����� */
    U0LCR = 0x80;                        	// DLABλ��1
    bak = (Fpclk>>4)/baud;
    U0DLM = bak>>8;
    U0DLL = bak&0xff;
   
    /* ���ô���ģʽ */
    bak = set.datab-5;                   	// �����ֳ���
    if(2==set.stopb) 
    {
       bak |= 0x04;				        	// �ж��Ƿ�Ϊ2λֹͣλ  
    }
    if(0!=set.parity) 
    {
        set.parity = set.parity-1; 
        bak |= 0x08;
    }
    bak |= set.parity<<4;              		// ������żУ��
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
* ��    �ƣ�main()
* ��    �ܣ���ʼ�����ڣ����ȴ����յ��������ݡ�
****************************************************************************/
int  main(void)
{   uint8     rcv_counter;
    uint8   flash_num=0;
    UARTMODE  uart0_set;
    
    IRQEnable();
            
    PINSEL0 = 0x00000005;                	// ����I/O���ӵ�UART0
    
    /* PINSEL2ʹ�����������Ĭ�����ã�������������PINSEL2���������߻��ܵ����� */ 
    IO1DIR = LEDCON;
    IO0DIR = 0x00000080;
               
    rcv_new = 0;                         	// ���ձ�־Ϊ0
    uart0_set.datab = 8;                 	// 8λ����λ
    uart0_set.stopb = 1;                 	// 1λֹͣλ
    uart0_set.parity = 0;                	// ����żУ��
    UART0_Init(57600, uart0_set);        	// ��ʼ������ģʽ
   
    U0FCR = 0x81;                        	// ʹ��FIFO�������ô�����Ϊ8�ֽ�
    U0IER = 0x01;                        	// ����RBR�жϣ��������ж�
   
    /* �����ж����� */
    VICIntSelect = 0x00000000;           	// ��������ͨ��ΪIRQ�ж�
    VICVectCntl0 = 0x26;        			// UART0�ж�ͨ�����䵽IRQ slot 0�������ȼ����
    VICVectAddr0 = (int)IRQ_UART0;       	// ����UART0������ַ
    VICIntEnable = 0x00000040;           	// ʹ��UART0�ж�
   
    rcv_counter = 0;
    IO1SET = 0xffffffff;
    IO0SET = 0xffffffff;

    while(1)             					// �ȴ��ж�
    { 

        if(1==rcv_new)  					// �Ƿ��Ѿ����յ�8 Bytes������
        {  
           rcv_new = 0;       				// �����־
           ISendBuf();        				// �����յ������ݷ��ͻ�����

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
