
#include <Headers/myThread.h>
#include <QDebug>
#include <sys/socket.h>
#include <QVector>
#include <netinet/in.h>   //htons
#include <linux/if_ether.h>  //ETH_P_IP
#include <Headers/share.h>




extern QVector<QString> ipp;
extern int iscatch;
extern int rowcount;
int sock,n;
char buffer[1518];
unsigned char *iphead,*ethhead;

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

        n = recvfrom(sock,buffer,sizeof(buffer),0,NULL,NULL);
        if(n>0)printf("%d bytes read\n",n);

        if(iscatch){
            IP_HEADER *ipHdr = (IP_HEADER *)(buffer+sizeof(ETH_HEADER));
            //unsigned char *p = (unsigned char*)&ipHdr->sourceIP;
            if(0x01==ipHdr->proto){
                //rowcount++;
                ipp.append(QString(buffer));
            }
                //printf("Source IP\t: %u.%u.%u.%u\n",p[0],p[1],p[2],p[3]);
                //p = (unsigned char*)&ipHdr->destIP;
                //printf("Destination IP\t: %u.%u.%u.%u\n",p[0],p[1],p[2],p[3]);

                //qDebug()<<ipp.count();
        }
            //rowcount++;
            //usleep(10);
    }
}

