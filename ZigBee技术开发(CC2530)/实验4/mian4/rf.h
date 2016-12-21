#ifndef __RF_H__
#define __RF_H__
#include <ioCC2530.h>
#define uint unsigned int 
#define uchar unsigned char
#define ON    0
#define OFF   1
void rf_in(void);
void rf_send_string(unsigned char *data,int len);
void rf_send(unsigned char *data);
#endif