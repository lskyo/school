#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define RET_OK   0
#define RET_ERR -1

#define LISTEN_QUEUE_NUM 5

#define BUFFER_SIZE 256

#define ECHO_PORT 2029


int sockfd = -1 ;
int opt = 1;
struct sockaddr_in cliaddr;
uint8_t buffer[BUFFER_SIZE];
int sendbytes = 0;
int ret = -1;
struct hostent *host;
struct sockaddr_in serv_addr;




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

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().isEmpty()==true)
    {
         ui->lineEdit->setText(QString("Please enter the server's hostname!"));
    }
    else if((host=gethostbyname(ui->lineEdit->text().toAscii()))==NULL)
    {
        ui->lineEdit->setText(QString("The server's hostname is worring!"));
    }
}

void MainWindow::on_pushButton_clicked()
{

}
