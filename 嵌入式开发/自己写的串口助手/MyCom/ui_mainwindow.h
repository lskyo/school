/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon May 22 18:04:37 2017
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QLabel *label_5;
    QComboBox *comboBox_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QTextEdit *textEdit;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QTextEdit *textEdit_2;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit;
    QPushButton *pushButton_7;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(915, 560);
        MainWindow->setMinimumSize(QSize(600, 0));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setMargin(11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        comboBox_5 = new QComboBox(groupBox);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_5);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(5, QFormLayout::LabelRole, pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        formLayout->setWidget(6, QFormLayout::LabelRole, pushButton_3);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        formLayout->setWidget(6, QFormLayout::FieldRole, pushButton_8);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        formLayout->setWidget(7, QFormLayout::LabelRole, pushButton_9);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        formLayout->setWidget(7, QFormLayout::FieldRole, pushButton_10);


        gridLayout->addWidget(groupBox, 2, 0, 1, 2);

        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        sizePolicy.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(label_6);

        textEdit = new QTextEdit(widget1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textEdit);


        gridLayout->addWidget(widget1, 2, 2, 1, 1);

        widget2 = new QWidget(widget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget2->sizePolicy().hasHeightForWidth());
        widget2->setSizePolicy(sizePolicy3);
        widget2->setMinimumSize(QSize(0, 0));
        widget2->setMaximumSize(QSize(16777215, 120));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(widget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        textEdit_2 = new QTextEdit(widget2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
        textEdit_2->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(textEdit_2, 2, 0, 1, 1);

        widget3 = new QWidget(widget2);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget3->sizePolicy().hasHeightForWidth());
        widget3->setSizePolicy(sizePolicy5);
        verticalLayout_3 = new QVBoxLayout(widget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_4 = new QPushButton(widget3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy6);
        pushButton_4->setMinimumSize(QSize(0, 30));
        pushButton_4->setMaximumSize(QSize(16777215, 30));
        pushButton_4->setDefault(true);

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy7);
        pushButton_5->setMinimumSize(QSize(0, 20));

        verticalLayout_3->addWidget(pushButton_5);


        gridLayout_2->addWidget(widget3, 2, 1, 1, 1);


        gridLayout->addWidget(widget2, 3, 0, 1, 3);

        widget4 = new QWidget(widget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        horizontalLayout = new QHBoxLayout(widget4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_6 = new QPushButton(widget4);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);

        lineEdit = new QLineEdit(widget4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit);

        pushButton_7 = new QPushButton(widget4);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);


        gridLayout->addWidget(widget4, 4, 0, 1, 3);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setEnabled(true);
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy8);
        widget_3->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setMargin(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(50, 0));
        label_8->setMaximumSize(QSize(16777215, 16777215));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_8);


        gridLayout->addWidget(widget_3, 0, 0, 1, 3);


        verticalLayout_2->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 915, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(12);
        comboBox_4->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MyCom", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM9", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "75", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "134", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "150", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "300", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "56000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "76800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "128000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "256000", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ODD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "EVEN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "MARK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SPACK", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1_5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
        );
        pushButton->setText(QApplication::translate("MainWindow", "OpenCom", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Don't show", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\230\276\347\244\272\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("MainWindow", "Listed", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", 0, QApplication::UnicodeUTF8));
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">test</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "\346\202\250\350\277\230\346\262\241\346\234\211\351\200\211\346\213\251\346\226\207\344\273\266...", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
