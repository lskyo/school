#ifndef __UART_H__
#define __UART_H__


#define uint8 unsigned char
#define uint16 unsigned int

extern uint8 RTflag;
extern uint8 temp;

void Init_UART(void);
void UartTX_Send_String(char *Data,int len);
void UartTX_Send_data(int Data);


#endif

