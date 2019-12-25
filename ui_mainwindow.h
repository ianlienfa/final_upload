/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Testdata;
    QLabel *Submitdata;
    QLabel *Spendtime;
    QLabel *Correctornot;
    QLineEdit *Testdata1;
    QLineEdit *Submitdata1;
    QLineEdit *SpendTime1;
    QLineEdit *Correctornot1;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QLabel *Score;
    QLineEdit *Score1;
    QLabel *label;
    QLCDNumber *NowElevator;
    QLCDNumber *PeopleinElevator;
    QLCDNumber *DIstance;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Testdata = new QLabel(centralwidget);
        Testdata->setObjectName(QString::fromUtf8("Testdata"));
        Testdata->setGeometry(QRect(30, 10, 51, 16));
        Submitdata = new QLabel(centralwidget);
        Submitdata->setObjectName(QString::fromUtf8("Submitdata"));
        Submitdata->setGeometry(QRect(30, 40, 51, 16));
        Spendtime = new QLabel(centralwidget);
        Spendtime->setObjectName(QString::fromUtf8("Spendtime"));
        Spendtime->setGeometry(QRect(30, 70, 51, 16));
        Correctornot = new QLabel(centralwidget);
        Correctornot->setObjectName(QString::fromUtf8("Correctornot"));
        Correctornot->setGeometry(QRect(30, 100, 51, 16));
        Testdata1 = new QLineEdit(centralwidget);
        Testdata1->setObjectName(QString::fromUtf8("Testdata1"));
        Testdata1->setGeometry(QRect(90, 10, 511, 20));
        Submitdata1 = new QLineEdit(centralwidget);
        Submitdata1->setObjectName(QString::fromUtf8("Submitdata1"));
        Submitdata1->setGeometry(QRect(90, 40, 511, 20));
        SpendTime1 = new QLineEdit(centralwidget);
        SpendTime1->setObjectName(QString::fromUtf8("SpendTime1"));
        SpendTime1->setGeometry(QRect(90, 70, 151, 20));
        Correctornot1 = new QLineEdit(centralwidget);
        Correctornot1->setObjectName(QString::fromUtf8("Correctornot1"));
        Correctornot1->setGeometry(QRect(90, 100, 151, 20));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 170, 55, 21));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(380, 150, 111, 71));
        Score = new QLabel(centralwidget);
        Score->setObjectName(QString::fromUtf8("Score"));
        Score->setGeometry(QRect(30, 130, 61, 20));
        Score1 = new QLineEdit(centralwidget);
        Score1->setObjectName(QString::fromUtf8("Score1"));
        Score1->setGeometry(QRect(90, 130, 171, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 250, 101, 51));
        NowElevator = new QLCDNumber(centralwidget);
        NowElevator->setObjectName(QString::fromUtf8("NowElevator"));
        NowElevator->setGeometry(QRect(700, 160, 64, 23));
        PeopleinElevator = new QLCDNumber(centralwidget);
        PeopleinElevator->setObjectName(QString::fromUtf8("PeopleinElevator"));
        PeopleinElevator->setGeometry(QRect(700, 200, 64, 23));
        DIstance = new QLCDNumber(centralwidget);
        DIstance->setObjectName(QString::fromUtf8("DIstance"));
        DIstance->setGeometry(QRect(700, 240, 64, 23));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(550, 160, 113, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(550, 200, 113, 20));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(550, 240, 113, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Testdata->setText(QCoreApplication::translate("MainWindow", "Testdata", nullptr));
        Submitdata->setText(QCoreApplication::translate("MainWindow", "Submitdata", nullptr));
        Spendtime->setText(QCoreApplication::translate("MainWindow", "Spend Time", nullptr));
        Correctornot->setText(QCoreApplication::translate("MainWindow", "Correct or not", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "11", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MainWindow", "12", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("MainWindow", "13", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("MainWindow", "14", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("MainWindow", "15", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("MainWindow", "16", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("MainWindow", "17", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("MainWindow", "18", nullptr));
        comboBox->setItemText(18, QCoreApplication::translate("MainWindow", "19", nullptr));
        comboBox->setItemText(19, QCoreApplication::translate("MainWindow", "20", nullptr));
        comboBox->setItemText(20, QCoreApplication::translate("MainWindow", "21", nullptr));
        comboBox->setItemText(21, QCoreApplication::translate("MainWindow", "22", nullptr));
        comboBox->setItemText(22, QCoreApplication::translate("MainWindow", "23", nullptr));

        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Start Simulation", nullptr));
        Score->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Finish!!!", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "Now Elevator", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "People in Elevator", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
