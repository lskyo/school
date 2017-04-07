/*******************************************************************************
*文件名   ： People.h
*实现功能 ： 热释电红外传感器(人体红外检测)
*实验平台 ： 秉火 Zigbee 开发板
*硬件连接 ： PEOPLE P0_0 
             LED1   P1_0
*作者     ： fire 
*创建时间 ： 2015/xx/xx
*论坛     ： http://www.chuxue123.com
*淘宝     ： http://firestm32.taobao.com
*******************************************************************************/

#ifndef __People_H__
#define __People_H__

#include <ioCC2530.h>
#define uint unsigned int 
#define uchar unsigned char

//定义控制LED灯的端口
#define LED1 P1_0	//LED1为P1.0口控制
#define PEOPLE P0_7     //热释电红外传感器为P0.0口控制

//函数声明
void Delayms(uint xms);		  //延时函数
void InitLed(void);		  //初始化LED1
void PeopleInit(void);            //热释电红外传感器初始化
uchar PeopleScan(void);           //人体检测程序

#endif

/*********************************************END OF FILE**********************/

