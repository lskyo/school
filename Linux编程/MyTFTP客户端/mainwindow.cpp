#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 7755);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));

    memset(RecvData, 0, sizeof(RecvData));
    memset(DataBuff, 0, sizeof(DataBuff));

    block = 0;
}

void MainWindow::sendReadReq(QHostAddress haddr, quint16 port, char *pFilename)
{

    struct TFTPHeader header;
    header.opcode = qToBigEndian((short)OPCODE_RRQ);
    int filenamelen = strlen(pFilename) + 1;
    int packetsize = sizeof(header) + filenamelen + 5 + 1;
    char *packet = (char*)malloc(packetsize);
    memcpy(packet, &header, sizeof(header));
    memcpy(packet + sizeof(header), pFilename, filenamelen);
    char *mode = "octet";
    memcpy(packet + sizeof(header) + filenamelen, mode, strlen(mode) +1);

    int bytes = udpSocket->writeDatagram((char*)packet, packetsize, haddr, port);
    qDebug("%d bytes has been sent", bytes);
    pFile = new QFile(pFilename);
    if(!pFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug("sendReadReq Open file false!!!");
        return ;
    }
    qDebug() << "file info : " << pFile->fileName();

}


void MainWindow::sendWriteReq(QHostAddress haddr, quint16 port, char *pFilename)
{
    wFile = new QFile(pFilename);
    if(!wFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("sendWriteReq Open file false!!!");
        return ;
    }

    QString file_name;
    QFileInfo fi;
    fi = QFileInfo(pFilename);
    file_name = fi.fileName();

    struct TFTPHeader header;
    header.opcode = qToBigEndian((short)OPCODE_WRQ);
    int filenamelen = strlen(file_name) + 1;
    int packetsize = sizeof(header) + filenamelen + 5 + 1;
    char *packet = (char*)malloc(packetsize);
    memcpy(packet, &header, sizeof(header));
    memcpy(packet + sizeof(header), file_name, filenamelen);
    char *mode = "octet";
    memcpy(packet + sizeof(header) + filenamelen, mode, strlen(mode) +1);

    int bytes = udpSocket->writeDatagram((char*)packet, packetsize, haddr, port);
    qDebug("%d bytes has been sent", bytes);

    qDebug() << "file info : " << wFile->fileName();

}

int MainWindow::sendData(QHostAddress haddr, quint16 port, QFile *p)
{
    QString str = p->read(512);
    QByteArray bytes = str.toLatin1();

    struct TFTPData *tftpData =(struct TFTPData*) malloc(bytes.length()+sizeof(struct TFTPData));
    tftpData->header.opcode = qToBigEndian((short)OPCODE_DATA);
    tftpData->block = qToBigEndian((short)block);
    memcpy(tftpData->data,bytes.data(),bytes.length());

    udpSocket->writeDatagram((char *)tftpData,sizeof(tftpData)+bytes.length(), haddr, port);

    return bytes.length();
}

void MainWindow::sendDataAck(struct TFTPData *pData, QHostAddress haddr, quint16 port)
{

    struct TFTPACK ack;
    ack.header.opcode = qToBigEndian((short)OPCODE_ACK);
    ack.block = pData->block;

    udpSocket->writeDatagram((char*)&ack, sizeof(ack), haddr, port);

}

void MainWindow::readPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QHostAddress sender;
        quint16 senderPort;

        int readbytes = udpSocket->readDatagram(RecvData, sizeof(RecvData),
                                                &sender, &senderPort);

        qDebug("port %d ip %s", senderPort, sender.toString().toUtf8().data());
        struct TFTPHeader *header = (struct TFTPHeader *)RecvData;
        switch(qFromBigEndian(header->opcode))
        {
        case OPCODE_DATA:
            {
                qDebug("it is Data");
                struct TFTPData *data = (struct TFTPData*)RecvData;
                pFile->write(data->data, readbytes - sizeof(struct TFTPHeader) - sizeof(short));
                sendDataAck(data, sender, senderPort);

                if(readbytes < 512)
                {
                    qDebug("File Transfer Completed!");
                    pFile->close();
                }
            }
            break;
            case OPCODE_ACK:
            {
                qDebug("it is ACK");
                struct TFTPACK *ack = (struct TFTPACK*)RecvData;
                block = qFromBigEndian(ack->block);
                block++;
                int datalen = sendData(sender, senderPort, wFile);
                if(datalen < 512)
                {
                    qDebug("File Transfer Completed!");
                    wFile->close();
                }

            }
            break;
        default:
            qDebug("No match %d", header->opcode);
        }

    }

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


void MainWindow::on_pushButton_clicked()
{
    chaddr.setAddress(ui->lineEdit->text());
    cport = (quint16)ui->lineEdit_2->text().toUShort();
    QByteArray b = ui->lineEdit_3->text().toLatin1();
    char *p = b.data();


    ui->textEdit->append("------------------------------------------");
    ui->textEdit->append("Host: " + chaddr.toString());
    ui->textEdit->append("Port: " + ui->lineEdit_2->text());
    ui->textEdit->append("Method: Get");
    ui->textEdit->append("Filename: " + ui->lineEdit_3->text());
    ui->textEdit->append("------------------------------------------");

    sendReadReq(chaddr, cport, p);

}

void MainWindow::on_pushButton_2_clicked()
{
    chaddr.setAddress(ui->lineEdit->text());
    cport = (quint16)ui->lineEdit_2->text().toUShort();
    QByteArray b =  ui->lineEdit_4->text().toLatin1();
    char *p = b.data();

    ui->textEdit->append("------------------------------------------");
    ui->textEdit->append("Host: " + chaddr.toString());
    ui->textEdit->append("Port: " + ui->lineEdit_2->text());
    ui->textEdit->append("Method: Post");
    ui->textEdit->append("Filename: " + ui->lineEdit_3->text());
    ui->textEdit->append("------------------------------------------");

    block = 0;

    sendWriteReq(chaddr, cport, p);

}

void MainWindow::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("File"), " ",  tr("Allfile(*.*);;mp3file(*)"));
    ui->lineEdit_4->setText(filename);
}

MainWindow::~MainWindow()
{
    delete ui;
}




