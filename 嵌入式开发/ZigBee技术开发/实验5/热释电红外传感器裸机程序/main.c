/*******************************************************************************
*文件名   ： main.c
*实现功能 ： 热释电红外传感器(人体红外检测)
*实验平台 ： 秉火 Zigbee 开发板
*硬件连接 ： PEOPLE P0_0 
             LED1   P1_0
*作者     ： fire 
*创建时间 ： 2015/xx/xx
*论坛     ： http://www.chuxue123.com
*淘宝     ： http://firestm32.taobao.com
*******************************************************************************/

#include "People.h"

/**************************************************
 函 数 名  : main
 功能描述  :  热释电红外传感器(人体红外检测)
 输入参数  : NONE  
 输出参数  : NONE
 返 回 值  : NONE
***************************************************/
void main(void)
{
    InitLed();         //调用初始化函数
    PeopleInit();
    while(1)
    {
        if(PeopleScan())   //改变LED状态
           LED1=0;         //有人，LED1点亮
        else 
           LED1=1;         //无人，LED1灭掉
    }
}



/*********************************************END OF FILE**********************/


