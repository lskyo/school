#include "ray.h"

void ray_in()//初始化光照传感器
{ 
     ADCH&=0X00;
     ADCL&=0X00;
     ADCCFG|=0X20;//p0.5端口模拟I/O使能
     ADCCON3=0X35;//单次转换，对p0.5进行采样12位分辨率
     ADCCON1=0X30;//停止A\D
     ADCCON1|=0X40;//启动A\D
}