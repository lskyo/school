#include "stdio.h"
//unsigned char csum(unsigned char *addr, int count);

unsigned char data[] = 
{
    0x45,0x00,0x00,0x3c,
    0xe0,0x8a,0x00,0x00,
    0x40,0x01,0x00,0x00,//0x18,0xdd
    0xc0,0xa8,0x00,0x08,
    0xc0,0xa8,0x00,0x01
};

unsigned short csum(unsigned short *addr, int count)
{
    /* Compute Internet Checksum for "count" bytes
    * beginning at location "addr".
    */
    long sum = 0;
    unsigned short tmp = 0;
    while( count > 1 ) 
    {
        /* This is the inner loop */
        sum += (long)(* ((unsigned short *)addr++));
        count -= 2;
    }
    
    /* Add left-over byte, if any */
    if( count > 0 )
    {
        sum += * (unsigned char *) addr;
    }

    /* Fold 32-bit sum to 16 bits */
    while (sum>>16)
    {
        sum = (sum & 0xffff) + (sum >> 16);
    }
    
    return ~sum;
}

int main(void)
{
    printf("the check sum is 0x%x\n",csum((unsigned short *)data,sizeof(data)));
    return 0;
}



