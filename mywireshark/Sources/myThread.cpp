
#include <Headers/myThread.h>
#include <QDebug>

extern int iscatch;
extern int rowcount;


myThread::myThread()
{

}



void myThread::run()
{
    qDebug()<<"myThread running!";
    while(1){
        if(iscatch)
        {
            rowcount++;
            usleep(10);
        }

    }
}
