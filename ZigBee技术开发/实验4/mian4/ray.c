#include "ray.h"

void ray_in()//��ʼ�����մ�����
{ 
     ADCH&=0X00;
     ADCL&=0X00;
     ADCCFG|=0X20;//p0.5�˿�ģ��I/Oʹ��
     ADCCON3=0X35;//����ת������p0.5���в���12λ�ֱ���
     ADCCON1=0X30;//ֹͣA\D
     ADCCON1|=0X40;//����A\D
}