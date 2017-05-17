#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    com = "COM1";
    isOpen = false;
    isShow = true;
    baud = 12;
    dataNum = 3;
    parityType = 0;
    stopBites = 0;
    rxn = 0;
    txn = 0;
    rxnl = new QLabel(QString::number(rxn));
    txnl = new QLabel(QString::number(txn));
    rx = new QLabel("RX:");
    tx = new QLabel("TX:");
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 5px}"));
    tx->setMinimumSize(tx->sizeHint());
    tx->setMaximumSize(tx->sizeHint());
    rx->setMaximumSize(rx->sizeHint());
    rx->setMinimumSize(rx->sizeHint());
    ui->statusBar->addWidget(rx);
    ui->statusBar->addWidget(rxnl);
    ui->statusBar->addPermanentWidget(tx);
    ui->statusBar->addPermanentWidget(txnl);

    pMycom = new QextSerialPort(com,QextSerialBase::EventDriven);
    connect(pMycom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    bool flag = pMycom->open(QIODevice::ReadWrite);

    if(flag == false){
        qDebug()<<"fail to open serial port!";
        isOpen = false;
        ui->pushButton->setText("OpenCom");
        QMessageBox::information(this,"Warning","Open com false!",QMessageBox::Yes,QMessageBox::Yes);
    }else{
        qDebug()<<"success to open serial port!";
        isOpen = true;
        ui->pushButton->setText("CloseCom");

        pMycom->setBaudRate((BaudRateType)baud);
        pMycom->setDataBits((DataBitsType)dataNum);
        pMycom->setParity((ParityType)parityType);
        pMycom->setStopBits((StopBitsType)stopBites);
        pMycom->setFlowControl(FLOW_OFF);
        pMycom->setTimeout(500);
        qDebug()<<"success to set serial port!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit_2->clear();
}


void MainWindow::readMyCom()
{
    qDebug()<<"This is readMyCom()!";
    //QByteArray temp = pMycom->readAll();
    //readBuf = pMycom->read(8);
    readBuf = pMycom->readAll();
    //int i = readBuf.indexOf('\n');
    qDebug() << "readBuf:" << readBuf;
    qDebug() << "readBuf length:" << readBuf.length();
    rxn+=readBuf.length();
    rxnl->setText(QString::number(rxn));
    if(isShow){
        ui->textEdit->insertPlainText(readBuf);
    }
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    //QString com;
    switch(index){
        case 0:com="COM1";break;
        case 1:com="COM2";break;
        case 2:com="COM3";break;
        case 3:com="COM4";break;
        case 4:com="COM5";break;
        case 5:com="COM6";break;
        case 6:com="COM7";break;
        case 7:com="COM8";break;
        case 8:com="COM9";break;
    }
    qDebug()<< "change " << index << " " << com;

    pMycom->close();
    pMycom = new QextSerialPort(com,QextSerialBase::EventDriven);
    connect(pMycom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    bool flag = pMycom->open(QIODevice::ReadWrite);

    if(flag == false){
        qDebug()<<"fail to open serial port!";
        isOpen = false;
        ui->pushButton->setText("OpenCom");

        QMessageBox::information(this,"Warning","Open com false!",QMessageBox::Yes,QMessageBox::Yes);
    }else{
        qDebug()<<"success to open serial port!";
        isOpen = true;
        ui->pushButton->setText("CloseCom");

        pMycom->setBaudRate((BaudRateType)baud);
        pMycom->setDataBits((DataBitsType)dataNum);
        pMycom->setParity((ParityType)parityType);
        pMycom->setStopBits((StopBitsType)stopBites);
        pMycom->setFlowControl(FLOW_OFF);
        pMycom->setTimeout(500);
        qDebug()<<"success to set serial port!";
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(isOpen){
        pMycom->close();
        qDebug()<<"close serial port!";
        isOpen = false;
        ui->pushButton->setText("OpenCom");
    }else{
       pMycom->open(QIODevice::ReadWrite);
       qDebug()<<"open serial port!";
       isOpen = true;
        ui->pushButton->setText("CloseCom");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(isShow){
        isShow = false;
        qDebug()<<"Don't show!";
        ui->pushButton_3->setText("Show");
    }else{
        isShow = true;
        qDebug()<<"Show!";
        ui->pushButton_3->setText("Don't Show");
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    baud = index;
    pMycom->setBaudRate((BaudRateType)baud);
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    parityType = index;
    pMycom->setParity((ParityType)parityType);
}

void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    dataNum = index;
    pMycom->setDataBits((DataBitsType)dataNum);
}

void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    stopBites = index;
    pMycom->setStopBits((StopBitsType)stopBites);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit_2->selectAll();
    QString str = ui->textEdit_2->toPlainText();
    QByteArray byte = str.toLatin1().data();
    pMycom->write(byte);
    txn+=str.length();
    txnl->setText(QString::number(txn));
}

void MainWindow::on_pushButton_6_clicked()
{
    path = QFileDialog::getOpenFileName(this, tr("File"), ".", tr("Files(*.*)"));
    if(path.length() != 0) {
        ui->lineEdit->setText(path);
        prFile = new QFile(path);
        if(!prFile->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"Warning","Open file false!",QMessageBox::Yes,QMessageBox::Yes);
        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    QTextStream txtInput(prFile);
    QString lineStr;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        QByteArray byte = lineStr.toLatin1().data();
        pMycom->write(byte);
        txn+=lineStr.length();
        txnl->setText(QString::number(txn));
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString wpath = QFileDialog::getSaveFileName(this, tr("File"), ".", tr("Files(*.*)"));
    if(wpath.length() != 0) {
        pwFile = new QFile(wpath);
        if(!pwFile->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::information(this,"Warning","Open file false!",QMessageBox::Yes,QMessageBox::Yes);
        }else{
            QTextStream txtOutput(pwFile);
            ui->textEdit->selectAll();
            QString str = ui->textEdit->toPlainText();
            txtOutput << str;
        }
    }
}
