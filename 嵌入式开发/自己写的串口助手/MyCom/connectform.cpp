#include "connectform.h"
#include "ui_connectform.h"

extern QHostAddress address;
extern quint16 port;

ConnectForm::ConnectForm(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ConnectForm)
{
    m_ui->setupUi(this);

    m_ui->pushButton->setFocus();

    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

    setWindowFlags(windowFlags() &~ Qt::WindowMinMaxButtonsHint);
}

ConnectForm::~ConnectForm()
{
    delete m_ui;
}

void ConnectForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ConnectForm::on_pushButton_2_clicked()
{
    this->hide();
}

void ConnectForm::on_pushButton_clicked()
{
    address.setAddress(m_ui->lineEdit->text());
    port = m_ui->lineEdit_2->text().toUShort();
    emit sendConnectReady(1);
    this->hide();
}
