#include "mywireshark.h"
#include "ui_mywireshark.h"
#include <QtGui/QTableWidget>
#include <QtGui/QHeaderView>
#include <QTableWidgetItem>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <Headers/myThread.h>


myThread *cthread = new myThread();
int iscatch = 0;
int rowcount = 1;







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
    timer->setInterval(1);
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
    ui->tableWidget->setRowCount(rowcount);
    rowcount = ui->tableWidget->rowCount();
    ui->tableWidget->setItem(rowcount-1,0,new QTableWidgetItem(QString::number(rowcount)));
}



void mywireshark::on_start_clicked()
{
    iscatch = 1;
}

void mywireshark::on_stop_clicked()
{
    iscatch = 0;
}
