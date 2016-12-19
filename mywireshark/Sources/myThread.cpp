
#include <Headers/myThread.h>
#include <QDebug>
#include <sys/socket.h>
#include <QVector>
#include <netinet/in.h>   //htons
#include <linux/if_ether.h>  //ETH_P_IP
#include <Headers/share.h>




extern int iscatch;
extern int rowcount;
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
    //qToBigEndian
    if((sock=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP)))<0)
    {
            perror("socket");
    }
    while(1){

        if(iscatch){
            n = recvfrom(sock,rowdatabuffer.buffer,sizeof(rowdatabuffer.buffer),0,NULL,NULL);
            if(n>0)printf("%d bytes read\n",n);

            IP_HEADER *ipHdr = (IP_HEADER *)(rowdatabuffer.buffer+sizeof(ETH_HEADER));
            unsigned char *p = (unsigned char*)&ipHdr->sourceIP;

            //if(0x01==ipHdr->proto){
                printf("thread Source IP\t: %u.%u.%u.%u\n",p[0],p[1],p[2],p[3]);
                sprintf(rowdatabuffer.sip,"%u.%u.%u.%u",p[0],p[1],p[2],p[3]);
                p = (unsigned char*)&ipHdr->destIP;
                printf("thread Destination IP\t: %u.%u.%u.%u\n",p[0],p[1],p[2],p[3]);
                sprintf(rowdatabuffer.dip,"%u.%u.%u.%u",p[0],p[1],p[2],p[3]);
                rowdata.append(rowdatabuffer);
            //}
        }
    }
}

