#include <QtGui/QApplication>
#include "mywireshark.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mywireshark w;
    w.show();
    return a.exec();
}
