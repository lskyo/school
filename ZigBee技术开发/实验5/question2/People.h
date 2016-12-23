/*******************************************************************************
*�ļ���   �� People.h
*ʵ�ֹ��� �� ���͵���⴫����(���������)
*ʵ��ƽ̨ �� ���� Zigbee ������
*Ӳ������ �� PEOPLE P0_0 
             LED1   P1_0
*����     �� fire 
*����ʱ�� �� 2015/xx/xx
*��̳     �� http://www.chuxue123.com
*�Ա�     �� http://firestm32.taobao.com
*******************************************************************************/

#ifndef __People_H__
#define __People_H__

#include <ioCC2530.h>
#define uint unsigned int 
#define uchar unsigned char

//�������LED�ƵĶ˿�
#define LED1 P1_0	//LED1ΪP1.0�ڿ���
#define PEOPLE P0_7     //���͵���⴫����ΪP0.0�ڿ���

//��������
void Delayms(uint xms);		  //��ʱ����
void InitLed(void);		  //��ʼ��LED1
void PeopleInit(void);            //���͵���⴫������ʼ��
uchar PeopleScan(void);           //���������

#endif

/*********************************************END OF FILE**********************/

