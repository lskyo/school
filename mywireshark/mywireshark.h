#ifndef MYWIRESHARK_H
#define MYWIRESHARK_H

#include <QMainWindow>

namespace Ui {
    class mywireshark;
}

class mywireshark : public QMainWindow {
    Q_OBJECT
public:
    mywireshark(QWidget *parent = 0);
    ~mywireshark();

signals:
public slots:
    void onTimerOut();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::mywireshark *ui;
    QTimer *timer;
};

#endif // MYWIRESHARK_H
