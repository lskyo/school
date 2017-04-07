/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Nov 24 04:59:20 2016
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(600, 400);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    textEdit_2 = new QTextEdit(centralWidget);
    textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

    gridLayout->addWidget(textEdit_2, 14, 2, 1, 2);

    pushButton = new QPushButton(centralWidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout->addWidget(pushButton, 12, 3, 1, 1);

    pushButton_2 = new QPushButton(centralWidget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    gridLayout->addWidget(pushButton_2, 12, 1, 1, 1);

    textEdit = new QTextEdit(centralWidget);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));

    gridLayout->addWidget(textEdit, 14, 0, 1, 2);

    lineEdit = new QLineEdit(centralWidget);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    gridLayout->addWidget(lineEdit, 3, 1, 1, 1);

    label = new QLabel(centralWidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 3, 0, 1, 1);

    lineEdit_2 = new QLineEdit(centralWidget);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

    gridLayout->addWidget(lineEdit_2, 3, 3, 1, 1);

    label_2 = new QLabel(centralWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 3, 2, 1, 1);

    label_3 = new QLabel(centralWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 13, 1, 1, 1);

    label_4 = new QLabel(centralWidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 13, 3, 1, 1);

    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 600, 24));
    MainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindow);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    MainWindow->setStatusBar(statusBar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("MainWindow", "Send to Service", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Service IP", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Service Port", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Receive Message", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "Send Message", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
