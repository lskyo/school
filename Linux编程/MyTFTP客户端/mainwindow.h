#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QUdpSocket>
#include <QFile>
#include <QtEndian>
#include <QFileDialog>
//#include <QByteArray>
#include "tftp.h"


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QUdpSocket *udpSocket;
    QHostAddress chaddr;
    quint16 cport;
    char RecvData[1024];
    char DataBuff[512];
    //short toblock;
    short block;
    QFile *pFile;
    QFile *wFile;
    void sendDataAck(struct TFTPData *pData, QHostAddress haddr, quint16 port);
    void sendReadReq(QHostAddress haddr, quint16 port, char *pFilename);
    void sendWriteReq(QHostAddress haddr, quint16 port, char *pFilename);
    int sendData(QHostAddress haddr, quint16 port, QFile *p);

protected:
    void changeEvent(QEvent *e);


private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void readPendingDatagrams();
};

#endif // MAINWINDOW_H
