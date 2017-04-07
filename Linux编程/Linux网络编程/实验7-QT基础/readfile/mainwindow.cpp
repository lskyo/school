#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/file.h>
#include <QFileDialog>
#include <stdlib.h>

#define BUF_LEN 100

int fd=-1,nread=0;
char buf[BUF_LEN];


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*
    ui->textEdit->clear();
    fd=open(ui->lineEdit->text().toAscii(),O_RDONLY, 0666);
    if(fd < 0)ui->textEdit->append(QString("open file is woring!"));
    while(1)
    {
        nread=read(fd,buf,BUF_LEN);
        if(nread<=0)break;
        ui->textEdit->append((QString(buf)));
    }
    */
    /* 上面读取文件的数据每100字节之间的衔接有问题 */


    ui->textEdit->clear();
    QFile file(ui->lineEdit->text().toAscii());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        ui->textEdit->append(QString("open file is woring!"));

    QTextStream in(&file);
    QString line = in.readLine();
    while(!line.isNull())
    {
        ui->textEdit->append((QString(line.toAscii())));
        line = in.readLine();
    }
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(QFileDialog::getOpenFileName(this,"",".",""));
}
