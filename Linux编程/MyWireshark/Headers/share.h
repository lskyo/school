#ifndef SHARE_H
#define SHARE_H

#include <string.h>

typedef struct _ethdr
{
        char src_mac[6];
        char dst_mac[6];
        short type;
}ETH_HEADER;


typedef struct _rowdata
{
    int num;
    char buffer[1518];
    char proto[20];
    char sip[100];
    char dip[100];
    char info[100];
} ROW_DATA;


typedef struct _iphdr
{
        unsigned char h_verlen;
        unsigned char tos;
        unsigned short total_len;
        unsigned short ident;
        unsigned short frag_and_flags;
        unsigned char ttl;
        unsigned char proto;
        unsigned short checksum;
        unsigned int sourceIP;
        unsigned int destIP;
}IP_HEADER;





#endif // SHARE_H
