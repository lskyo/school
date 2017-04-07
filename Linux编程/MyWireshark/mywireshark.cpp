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
long rowcount = 0;
long old_rowcount = 0;
unsigned char *p = NULL;
QVector<ROW_DATA> rowdata;
QVector<ROW_DATA> sel_rowdata;
ROW_DATA rowdatabuffer;
QString sel = "";





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
    timer->setInterval(20);
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
    if(sel == "" && sel_rowdata.empty()){
        old_rowcount = ui->tableWidget->rowCount();
        rowcount = rowdata.count();

        if(old_rowcount < rowcount){
            ui->tableWidget->setRowCount(rowcount);

            for(long num = old_rowcount; num < rowcount; num++){
                ui->tableWidget->setItem(num,0,new QTableWidgetItem(QString::number(num)));
                ui->tableWidget->setItem(num,1,new QTableWidgetItem(rowdata[num].sip));
                ui->tableWidget->setItem(num,2,new QTableWidgetItem(rowdata[num].dip));
                ui->tableWidget->setItem(num,3,new QTableWidgetItem(rowdata[num].proto));
                //ui->tableWidget->setItem(num,4,new QTableWidgetItem(QString::number(old_rowcount)));
            }
        }
    }
    else {
        old_rowcount = ui->tableWidget->rowCount();
        rowcount = sel_rowdata.count();

        if(old_rowcount < rowcount){
            ui->tableWidget->setRowCount(rowcount);

            for(long num = old_rowcount; num < rowcount; num++){
                //if(std::string(sel_rowdata[num].proto) == sel.toStdString())
                ui->tableWidget->setItem(num,0,new QTableWidgetItem(QString::number(num)));
                ui->tableWidget->setItem(num,1,new QTableWidgetItem(sel_rowdata[num].sip));
                ui->tableWidget->setItem(num,2,new QTableWidgetItem(sel_rowdata[num].dip));
                ui->tableWidget->setItem(num,3,new QTableWidgetItem(sel_rowdata[num].proto));
                //ui->tableWidget->setItem(num,4,new QTableWidgetItem(QString::number(old_rowcount)));
            }
        }
    }

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

void mywireshark::on_clear_clicked()
{
    ui->lineEdit->clear();
    ui->tableWidget->setRowCount(0);
    sel_rowdata.clear();
    sel="";
}

void mywireshark::on_apply_clicked()
{
    sel = ui->lineEdit->text();
    ui->tableWidget->setRowCount(0);
    sel_rowdata.clear();
    //char mychar[] = "test";
    //if(sel.toStdString() == std::string(mychar)){
    //    qDebug("==");
    //}
    for(int i = 0; i < rowdata.count(); i++){
        if(std::string(rowdata[i].proto) == sel.toStdString()){
            sel_rowdata.append(rowdata[i]);
        }
    }
}
