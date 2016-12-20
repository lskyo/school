
#include <Headers/myThread.h>
#include <QDebug>
#include <sys/socket.h>
#include <QVector>
#include <netinet/in.h>   //htons
#include <linux/if_ether.h>  //ETH_P_IP
#include <Headers/share.h>




extern int iscatch;
extern long rowcount;
int sock,n;
unsigned char *iphead,*ethhead;
extern QVector<ROW_DATA> rowdata;
extern ROW_DATA rowdatabuffer;

myThread::myThread()
{
}



void myThread::run()
{
    qDebug()<<"myThread running!";
    if((sock=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP)))<0)
    {
            perror("socket");
    }
    while(1){
        if(iscatch){
            n = recvfrom(sock,rowdatabuffer.buffer,sizeof(rowdatabuffer.buffer),0,NULL,NULL);
            IP_HEADER *ipHdr = (IP_HEADER *)(rowdatabuffer.buffer+sizeof(ETH_HEADER));
            unsigned char *p = (unsigned char*)&ipHdr->sourceIP;
            switch(ipHdr->proto)
            {
                case IPPROTO_IP :    sprintf(rowdatabuffer.proto,"IP"); break;
                case IPPROTO_ICMP:   sprintf(rowdatabuffer.proto,"ICMP"); break;
                case IPPROTO_IGMP :  sprintf(rowdatabuffer.proto,"IGMP"); break;
                case IPPROTO_TCP :   sprintf(rowdatabuffer.proto,"TCP"); break;
                case IPPROTO_PUP :   sprintf(rowdatabuffer.proto,"PUP"); break;
                case IPPROTO_UDP :   sprintf(rowdatabuffer.proto,"UDP"); break;
                case IPPROTO_IDP :   sprintf(rowdatabuffer.proto,"IDP"); break;
                case IPPROTO_RAW :   sprintf(rowdatabuffer.proto,"RAW"); break;
                case IPPROTO_MAX :   sprintf(rowdatabuffer.proto,"MAX"); break;
            }
            sprintf(rowdatabuffer.sip,"%u.%u.%u.%u",p[0],p[1],p[2],p[3]);
            p = (unsigned char*)&ipHdr->destIP;
            sprintf(rowdatabuffer.dip,"%u.%u.%u.%u",p[0],p[1],p[2],p[3]);
            rowdata.append(rowdatabuffer);
        }
    }
}

