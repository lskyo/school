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

private slots:
    void on_apply_clicked();
    void on_clear_clicked();
    void on_stop_clicked();
    void on_start_clicked();
};

#endif // MYWIRESHARK_H
