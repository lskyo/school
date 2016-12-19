#include "mywireshark.h"
#include "ui_mywireshark.h"
#include <QtGui/QTableWidget>
#include <QtGui/QHeaderView>
#include <QTableWidgetItem>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <Headers/myThread.h>
#include <QVector>
#include <Headers/share.h>



myThread *cthread = new myThread();
int iscatch = 0;
int rowcount = 0;
int old_rowcount = 0;
QVector<QString> ipp;
char *databuffer;
QByteArray pa;
char sipbuffer[100],dipbuffer[100];
unsigned char *p;





mywireshark::mywireshark(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mywireshark)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setColumnWidth(1,130);
    ui->tableWidget->setColumnWidth(2,130);

    timer = new QTimer();
    timer->setInterval(1000);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

    cthread->start();
}

mywireshark::~mywireshark()
{
    delete ui;
}

void mywireshark::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void mywireshark::onTimerOut()
{
    old_rowcount = ui->tableWidget->rowCount();
    rowcount = ipp.count();
    printf("old_rowcount = %d\nrowcount = %d\n",old_rowcount,rowcount);

    if(old_rowcount < rowcount){
        ui->tableWidget->setRowCount(rowcount);
        for(int num= old_rowcount; num < rowcount; num++){

            pa = ipp[num].toLatin1();
            databuffer = pa.data();
            IP_HEADER *ipHdr = (IP_HEADER *)(databuffer+sizeof(ETH_HEADER));

            p = (unsigned char*)&ipHdr->sourceIP;
            sprintf(sipbuffer,"%u.%u.%u.%u",p[0],p[1],p[2],p[3]);
            printf("Source IP\t: %u.%u.%u.%u\n",p[0],p[1],p[2],p[3]);
            p = (unsigned char*)&ipHdr->destIP;
            sprintf(dipbuffer,"%u.%u.%u.%u",p[0],p[1],p[2],p[3]);
            printf("Destination IP\t: %u.%u.%u.%u\n",p[0],p[1],p[2],p[3]);

            ui->tableWidget->setItem(num,0,new QTableWidgetItem(QString::number(num)));
            ui->tableWidget->setItem(num,1,new QTableWidgetItem(sipbuffer));
            ui->tableWidget->setItem(num,2,new QTableWidgetItem(dipbuffer));
            //ui->tableWidget->setItem(old_rowcount-1,3,new QTableWidgetItem(QString::number()));
            //ui->tableWidget->setItem(old_rowcount-1,4,new QTableWidgetItem(QString::number(old_rowcount)));

        }
    }
    //ui->tableWidget->setRowCount(rowcount);
    //ui->tableWidget->setItem(rowcount-1,0,new QTableWidgetItem(QString::number(rowcount)));
}



void mywireshark::on_start_clicked()
{
    iscatch = 1;
    printf("iscatch = %d\n",iscatch);
}

void mywireshark::on_stop_clicked()
{
    iscatch = 0;
    printf("iscatch = %d\n",iscatch);
}
