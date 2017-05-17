#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "qextserialport.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

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
    QextSerialPort *pMycom;
    int baud;
    int dataNum;
    int parityType;
    int stopBites;
    QByteArray readBuf;
    QString com;
    bool isOpen;
    bool isShow;
    QString path;
    QFile *prFile;
    QFile *pwFile;
    long rxn,txn;
    QLabel *rx,*rxnl;
    QLabel *tx,*txnl;


private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_comboBox_5_currentIndexChanged(int index);
    void on_comboBox_4_currentIndexChanged(int index);
    void on_comboBox_3_currentIndexChanged(int index);
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_comboBox_2_currentIndexChanged(int index);
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void readMyCom();
};

#endif // MAINWINDOW_H
