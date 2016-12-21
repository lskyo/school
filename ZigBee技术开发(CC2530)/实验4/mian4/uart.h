#ifndef __Uart_H__
#define __Uart_H__
#include <ioCC2530.h>
#define uint unsigned int 
#define uchar unsigned char
void uart_in(void);
void uartTX_send_string(unsigned char *data,int len);
void uartTX_send(unsigned char data);
#endif