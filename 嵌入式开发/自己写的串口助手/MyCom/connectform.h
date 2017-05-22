#ifndef CONNECTFORM_H
#define CONNECTFORM_H

#include <QtGui/QWidget>
#include <QDesktopWidget>
#include <QHostAddress>



namespace Ui {
    class ConnectForm;
}

class ConnectForm : public QWidget {
    Q_OBJECT
public:
    ConnectForm(QWidget *parent = 0);
    ~ConnectForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ConnectForm *m_ui;

signals:
    void sendConnectReady(int);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // CONNECTFORM_H
