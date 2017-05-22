#ifndef LISTENFORM_H
#define LISTENFORM_H

#include <QtGui/QWidget>
#include <QDesktopWidget>
#include <QHostAddress>




namespace Ui {
    class ListenForm;
}

class ListenForm : public QWidget {
    Q_OBJECT
public:
    ListenForm(QWidget *parent = 0);
    ~ListenForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ListenForm *m_ui;

signals:
    void sendListenReady(int);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // LISTENFORM_H
