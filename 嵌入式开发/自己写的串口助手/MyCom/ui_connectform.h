/********************************************************************************
** Form generated from reading ui file 'connectform.ui'
**
** Created: Sat May 20 10:03:54 2017
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONNECTFORM_H
#define UI_CONNECTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ConnectForm)
    {
        if (ConnectForm->objectName().isEmpty())
            ConnectForm->setObjectName(QString::fromUtf8("ConnectForm"));
        ConnectForm->setWindowModality(Qt::ApplicationModal);
        ConnectForm->resize(223, 169);
        verticalLayout_2 = new QVBoxLayout(ConnectForm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(ConnectForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addWidget(widget1);

        widget2 = new QWidget(widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_2 = new QLineEdit(widget2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addWidget(widget2);

        widget3 = new QWidget(widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        horizontalLayout_3 = new QHBoxLayout(widget3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton = new QPushButton(widget3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(80, 16777215));
        pushButton->setAutoDefault(true);
        pushButton->setDefault(true);

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout->addWidget(widget3);


        verticalLayout_2->addWidget(widget);


        retranslateUi(ConnectForm);

        QMetaObject::connectSlotsByName(ConnectForm);
    } // setupUi

    void retranslateUi(QWidget *ConnectForm)
    {
        ConnectForm->setWindowTitle(QApplication::translate("ConnectForm", "Connect", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConnectForm", "Port:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ConnectForm", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConnectForm", "Host:", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("ConnectForm", "1122", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ConnectForm", "Connect", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ConnectForm", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ConnectForm);
    } // retranslateUi

};

namespace Ui {
    class ConnectForm: public Ui_ConnectForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTFORM_H
