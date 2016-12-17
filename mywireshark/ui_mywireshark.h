/********************************************************************************
** Form generated from reading ui file 'mywireshark.ui'
**
** Created: Fri Dec 16 18:30:43 2016
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MYWIRESHARK_H
#define UI_MYWIRESHARK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mywireshark
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;
    QPushButton *apply;
    QPushButton *clear;
    QPushButton *start;
    QPushButton *stop;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mywireshark)
    {
    if (mywireshark->objectName().isEmpty())
        mywireshark->setObjectName(QString::fromUtf8("mywireshark"));
    mywireshark->resize(760, 560);
    centralWidget = new QWidget(mywireshark);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    lineEdit = new QLineEdit(centralWidget);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    gridLayout->addWidget(lineEdit, 2, 0, 1, 1);

    tableWidget = new QTableWidget(centralWidget);
    if (tableWidget->columnCount() < 5)
        tableWidget->setColumnCount(5);
    QTableWidgetItem *__colItem = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(0, __colItem);
    QTableWidgetItem *__colItem1 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(1, __colItem1);
    QTableWidgetItem *__colItem2 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(2, __colItem2);
    QTableWidgetItem *__colItem3 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(3, __colItem3);
    QTableWidgetItem *__colItem4 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(4, __colItem4);
    if (tableWidget->rowCount() < 1)
        tableWidget->setRowCount(1);
    QTableWidgetItem *__rowItem = new QTableWidgetItem();
    tableWidget->setVerticalHeaderItem(0, __rowItem);
    QTableWidgetItem *__tableItem = new QTableWidgetItem();
    tableWidget->setItem(0, 0, __tableItem);
    QTableWidgetItem *__tableItem1 = new QTableWidgetItem();
    tableWidget->setItem(0, 1, __tableItem1);
    QTableWidgetItem *__tableItem2 = new QTableWidgetItem();
    tableWidget->setItem(0, 2, __tableItem2);
    QTableWidgetItem *__tableItem3 = new QTableWidgetItem();
    tableWidget->setItem(0, 3, __tableItem3);
    QTableWidgetItem *__tableItem4 = new QTableWidgetItem();
    tableWidget->setItem(0, 4, __tableItem4);
    tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setTextElideMode(Qt::ElideNone);

    gridLayout->addWidget(tableWidget, 3, 0, 1, 3);

    apply = new QPushButton(centralWidget);
    apply->setObjectName(QString::fromUtf8("apply"));

    gridLayout->addWidget(apply, 2, 2, 1, 1);

    clear = new QPushButton(centralWidget);
    clear->setObjectName(QString::fromUtf8("clear"));

    gridLayout->addWidget(clear, 2, 1, 1, 1);

    start = new QPushButton(centralWidget);
    start->setObjectName(QString::fromUtf8("start"));

    gridLayout->addWidget(start, 0, 0, 1, 3);

    stop = new QPushButton(centralWidget);
    stop->setObjectName(QString::fromUtf8("stop"));

    gridLayout->addWidget(stop, 1, 0, 1, 3);

    mywireshark->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(mywireshark);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 760, 24));
    mywireshark->setMenuBar(menuBar);
    mainToolBar = new QToolBar(mywireshark);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    mywireshark->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(mywireshark);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    mywireshark->setStatusBar(statusBar);

    retranslateUi(mywireshark);

    QMetaObject::connectSlotsByName(mywireshark);
    } // setupUi

    void retranslateUi(QMainWindow *mywireshark)
    {
    mywireshark->setWindowTitle(QApplication::translate("mywireshark", "mywireshark", 0, QApplication::UnicodeUTF8));
    tableWidget->horizontalHeaderItem(0)->setText(QApplication::translate("mywireshark", "NO.", 0, QApplication::UnicodeUTF8));
    tableWidget->horizontalHeaderItem(1)->setText(QApplication::translate("mywireshark", "Source", 0, QApplication::UnicodeUTF8));
    tableWidget->horizontalHeaderItem(2)->setText(QApplication::translate("mywireshark", "Destination", 0, QApplication::UnicodeUTF8));
    tableWidget->horizontalHeaderItem(3)->setText(QApplication::translate("mywireshark", "Protocol", 0, QApplication::UnicodeUTF8));
    tableWidget->horizontalHeaderItem(4)->setText(QApplication::translate("mywireshark", "Info", 0, QApplication::UnicodeUTF8));
    tableWidget->verticalHeaderItem(0)->setText(QApplication::translate("mywireshark", "New Row", 0, QApplication::UnicodeUTF8));

    const bool __sortingEnabled = tableWidget->isSortingEnabled();
    tableWidget->setSortingEnabled(false);
    tableWidget->item(0, 0)->setText(QApplication::translate("mywireshark", "1", 0, QApplication::UnicodeUTF8));
    tableWidget->item(0, 1)->setText(QApplication::translate("mywireshark", "123.123.123.123", 0, QApplication::UnicodeUTF8));
    tableWidget->item(0, 2)->setText(QApplication::translate("mywireshark", "123.123.123.123", 0, QApplication::UnicodeUTF8));
    tableWidget->item(0, 3)->setText(QApplication::translate("mywireshark", "123.123.123.123", 0, QApplication::UnicodeUTF8));
    tableWidget->item(0, 4)->setText(QApplication::translate("mywireshark", "123.123.123.123", 0, QApplication::UnicodeUTF8));

    tableWidget->setSortingEnabled(__sortingEnabled);
    apply->setText(QApplication::translate("mywireshark", "Apply", 0, QApplication::UnicodeUTF8));
    clear->setText(QApplication::translate("mywireshark", "Clear", 0, QApplication::UnicodeUTF8));
    start->setText(QApplication::translate("mywireshark", "Start", 0, QApplication::UnicodeUTF8));
    stop->setText(QApplication::translate("mywireshark", "Stop", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(mywireshark);
    } // retranslateUi

};

namespace Ui {
    class mywireshark: public Ui_mywireshark {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIRESHARK_H
