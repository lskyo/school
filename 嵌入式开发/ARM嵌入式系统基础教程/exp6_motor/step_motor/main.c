/****************************************************************************
* �� �� ����main.c
* ��    �ܣ�LED��ʾ���ơ�
*           ͨ��GPIO���Ʋ������
* ˵    ����������JP14��JP19ȫ���̽ӡ�      
****************************************************************************/
#include  "config.h"

#define   LED1      1<<16       // P2.16  
#define   MOTOD	    1<<24       // P2.24  
#define   MOTOC		1<<25		// P2.25 
#define   MOTOB 	1<<26		// P2.26 
#define   MOTOA		1<<27		// P2.27 
#define   LEDCON	0x00ff0000  // LED������
#define   MOTOCON	0x0f000000  // MOTO������
#define   GPIOSET(PIN)  IO1SET = PIN    // �����޸���λ�˿�
#define   GPIOCLR(PIN)	IO1CLR = PIN    // �����޸���λ�˿�

void DelayNS(uint32  dly);
void MOTO_Mode1(uint8 i);               // A-B-C-D
void MOTO_Mode2(uint8 i);               // AB-BC-CD-DA-AB
void MOTO_Mode3(uint8 i);               // A-AB-B-BC-C-CD-D-DA-A
                      
/****************************************************************************
* ��    �ƣ�main()
* ��    �ܣ����ݱ�DISP_TAB������LED��ʾ��
****************************************************************************/
int  main(void)
{   	
    /* PINSEL2ʹ�����������Ĭ�����ã�������������PINSEL2���������߻��ܵ����� */ 
    IO1DIR = LEDCON | MOTOCON;      // ����LED����I/O����
      
    MOTO_Mode1(1);               // A-B-C-D
 //   MOTO_Mode2(10);               // AB-BC-CD-DA-AB
    //MOTO_Mode3(10);               // A-AB-B-BC-C-CD-D-DA-A

    return(0);
}

/****************************************************************************
* ��    �ƣ�DelayNS()
* ��    �ܣ��������ʱ
* ��ڲ�����dly		��ʱ������ֵԽ����ʱԽ��
* ���ڲ�������
****************************************************************************/
void DelayNS(uint32  dly)
{   uint32  i;

    for(; dly>0; dly--) 
    {
        for(i=0; i<20000; i++);
    }
}

/****************************************************************************
* ��    �ƣ�MOTO_Mode1()
* ��    �ܣ������ĳ���
* ��ڲ�����uint8 i		��ʱ������ֵԽ����ʱԽ��
* ���ڲ�������
****************************************************************************/
void MOTO_Mode1(uint8 i)            // A-B-C-D
{



    while(1)
    {
        GPIOCLR(LED1);              // ����LED1��������ӳ���״̬
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

        GPIOSET(LED1);              //  Ϩ��LED1��������ӳ���״̬
        /* D */
       GPIOSET(MOTOD);            
        DelayNS(i);
        GPIOCLR(MOTOD);
    }
}

/****************************************************************************
* ��    �ƣ�MOTO_Mode2()
* ��    �ܣ�˫���ĳ���
* ��ڲ�����uint8 i		��ʱ������ֵԽ����ʱԽ��
* ���ڲ�������
****************************************************************************/
void MOTO_Mode2(uint8 i)            // AB-BC-CD-DA-AB
{  
    while(1)
    {
        GPIOCLR(LED1);              // ����LED1��������ӳ���״̬
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

        GPIOSET(LED1);              //  Ϩ��LED1��������ӳ���״̬
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
* ��    �ƣ�MOTO_Mode3()
* ��    �ܣ���˫���ĳ���
* ��ڲ�����uint8 i		��ʱ������ֵԽ����ʱԽ��
* ���ڲ�������
****************************************************************************/
void MOTO_Mode3(uint8 i)            // A-AB-B-BC-C-CD-D-DA-A
{
    while(1)	
    {  
        GPIOCLR(LED1);              // ����LED1��������ӳ���״̬
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

        GPIOSET(LED1);              //  Ϩ��LED1��������ӳ���״̬
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