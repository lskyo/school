/********************************************************************************
** Form generated from reading ui file 'listenform.ui'
**
** Created: Sat May 20 13:18:05 2017
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LISTENFORM_H
#define UI_LISTENFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListenForm
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ListenForm)
    {
        if (ListenForm->objectName().isEmpty())
            ListenForm->setObjectName(QString::fromUtf8("ListenForm"));
        ListenForm->setWindowModality(Qt::ApplicationModal);
        ListenForm->resize(223, 169);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ListenForm->sizePolicy().hasHeightForWidth());
        ListenForm->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ListenForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(ListenForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addWidget(widget1);

        widget2 = new QWidget(widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addWidget(widget2);

        widget3 = new QWidget(widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(80, 0));
        pushButton->setMaximumSize(QSize(80, 16777215));
        pushButton->setAutoDefault(true);
        pushButton->setDefault(true);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addWidget(widget3);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(ListenForm);

        QMetaObject::connectSlotsByName(ListenForm);
    } // setupUi

    void retranslateUi(QWidget *ListenForm)
    {
        ListenForm->setWindowTitle(QApplication::translate("ListenForm", "Listen", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ListenForm", "Host:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ListenForm", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ListenForm", "Port:", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("ListenForm", "1122", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ListenForm", "Listen", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ListenForm", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ListenForm);
    } // retranslateUi

};

namespace Ui {
    class ListenForm: public Ui_ListenForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTENFORM_H
