#include "listenform.h"
#include "ui_listenform.h"

extern QHostAddress address;
extern quint16 port;

ListenForm::ListenForm(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ListenForm)
{
    m_ui->setupUi(this);
    m_ui->pushButton->setFocus();
    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

    setWindowFlags(windowFlags() &~ Qt::WindowMinMaxButtonsHint);
}

ListenForm::~ListenForm()
{
    delete m_ui;
}

void ListenForm::changeEvent(QEvent *e)
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

void ListenForm::on_pushButton_2_clicked()
{
    this->hide();
}

void ListenForm::on_pushButton_clicked()
{
    address.setAddress(m_ui->lineEdit->text());
    port = m_ui->lineEdit_2->text().toUShort();
    emit sendListenReady(2);
    this->hide();
}
