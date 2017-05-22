#include "mainwindow.h"
#include "ui_mainwindow.h"


QHostAddress address;
quint16 port;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_3->hide();
    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);


    lf = new ListenForm();
    cf = new ConnectForm();

    connect(cf, SIGNAL(sendConnectReady(int)),
            this, SLOT(readPendingDatagrams(int)));
    connect(lf, SIGNAL(sendListenReady(int)),
            this, SLOT(readPendingDatagrams(int)));

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),
                this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
                this,SLOT(displayError(QAbstractSocket::SocketError)));

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()),
                this, SLOT(getConnection()));

    role = 0;
    isConnectioning = false;
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
    readBuf = pMycom->readAll();
    qDebug() << "readBuf:" << readBuf;
    rxn+=readBuf.length();
    rxnl->setText(QString::number(rxn));
    qDebug()<<"isShow:" << isShow;

    if(isShow){
        ui->textEdit->insertPlainText(readBuf);
    }

    qDebug()<<"isConnectioning:" << isConnectioning;
    if(isConnectioning){
        sendRecvMessage();
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
    if(role==1)sendMessage();
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
        if(role==1){

            tcpSocket->write(QByteArray(lineStr.toLocal8Bit()));
            qDebug() << "send message successful!";
        }else{
            pMycom->write(byte);
        }
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

void MainWindow::on_pushButton_9_clicked()
{
    cf->show();
}

void MainWindow::on_pushButton_10_clicked()
{
    lf->show();
}

void MainWindow::readPendingDatagrams(int value)
{
    qDebug() << "This is readPendingDatagrams...";
    qDebug() << "value:" << value ;
    qDebug() << "address:" << address.toString() ;
    qDebug() << "port:" << port ;

    if(value == 1){
        qDebug() << "connecting...";
        if(isOpen)role = 0;
        else role = 1;
        isConnectioning = true;
        tcpSocket->abort();
        blockSize = 0;
        tcpSocket->connectToHost(address, port);
        qDebug() << "tcpSocket->localAddress().toIPv4Address():" << tcpSocket->localAddress().toIPv4Address();
        qDebug() << "tcpSocket->localPort():" << tcpSocket->localPort();
        qDebug()<<"tcpSocket->peerAddress():"<<tcpSocket->peerAddress();
        qDebug()<<"tcpSocket->peerPort():"<<tcpSocket->peerPort();

        ui->widget_3->show();
        ui->label_8->setText("connecting...");

    }else if(value ==2){
        qDebug() << "listening...";
        ui->label_8->setText("listening...");
        ui->widget_3->show();
        if(isOpen)role = 0;
        else role = 1;
        if(!tcpServer->listen(QHostAddress::LocalHost,port)){
            qDebug() << tcpServer->errorString();
        }
        qDebug() << "tcpServer->serverAddress().toString()" << tcpServer->serverAddress().toString();
        qDebug() << "tcpServer->serverPort():" << tcpServer->serverPort();
    }
}

void MainWindow::sendMessage()
{
    qDebug() << "This is sendMessage...";
    QString str;
    ui->textEdit_2->selectAll();
    str = ui->textEdit_2->toPlainText();
    qDebug() << "str:" << str;
    tcpSocket->write(QByteArray(str.toLocal8Bit()));
    qDebug() << "send message successful!";
}


void MainWindow::sendRecvMessage()
{
    qDebug() << "This is sendRecvMessage...";
    qDebug() << "readBuf:" << QString::fromLocal8Bit(readBuf);
    clientSocket->write(readBuf);
    qDebug() << "send message successful!";
}

void MainWindow::getConnection()
{
    qDebug() << "This is getConnection...";
    clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket,SIGNAL(readyRead()),
                this,SLOT(readClientMessage()));
    connect(clientSocket,SIGNAL(error(QAbstractSocket::SocketError)),
                this,SLOT(displayError2(QAbstractSocket::SocketError)));
    qDebug() << "clientSocket->peerAddress():" << clientSocket->peerAddress();
    qDebug() << "clientSocket->peerPort():" << clientSocket->peerPort();
    qDebug() << "clientSocket->localAddress().toIPv4Address():" << clientSocket->localAddress().toIPv4Address();
    qDebug() << "clientSocket->localPort()" << clientSocket->localPort();
    isConnectioning = true;
    ui->label_8->setText("connecting...");
    ui->widget_3->show();
}

void MainWindow::readMessage()
{
    qDebug() << "This is readMessage...";
    message = QString::fromLocal8Bit(tcpSocket->readAll());
    if(role == 1){
        ui->textEdit->insertPlainText(message);
    }else{
        pMycom->write(message.toLatin1().data());
    }
    qDebug() << message;
}
void MainWindow::readClientMessage()
{
    qDebug() << "This is readClientMessage...";
    message = QString::fromLocal8Bit(clientSocket->readAll());
    if(role == 1){
        ui->textEdit->insertPlainText(message);
    }else{
        pMycom->write(message.toLatin1().data());
    }
    qDebug() << message;
}

void MainWindow::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
    ui->widget_3->hide();
}
void MainWindow::displayError2(QAbstractSocket::SocketError)
{
    qDebug() << clientSocket->errorString();
    ui->widget_3->hide();
}

