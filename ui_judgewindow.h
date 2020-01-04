/********************************************************************************
** Form generated from reading UI file 'judgewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUDGEWINDOW_H
#define UI_JUDGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JudgeWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *checkbox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QLabel *label_5;

    void setupUi(QWidget *JudgeWindow)
    {
        if (JudgeWindow->objectName().isEmpty())
            JudgeWindow->setObjectName(QString::fromUtf8("JudgeWindow"));
        JudgeWindow->resize(1291, 920);
        gridLayoutWidget = new QWidget(JudgeWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 521, 681));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(JudgeWindow);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(570, 40, 371, 681));
        checkbox = new QGridLayout(gridLayoutWidget_2);
        checkbox->setObjectName(QString::fromUtf8("checkbox"));
        checkbox->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(JudgeWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 91, 20));
        label_2 = new QLabel(JudgeWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 20, 101, 20));
        label_3 = new QLabel(JudgeWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 20, 71, 20));
        label_4 = new QLabel(JudgeWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 20, 81, 16));
        lineEdit = new QLineEdit(JudgeWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(1010, 60, 113, 20));
        lineEdit_2 = new QLineEdit(JudgeWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(1010, 90, 113, 20));
        lineEdit_3 = new QLineEdit(JudgeWindow);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(1160, 60, 113, 20));
        lineEdit_4 = new QLineEdit(JudgeWindow);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(1160, 90, 113, 20));
        pushButton = new QPushButton(JudgeWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1120, 630, 141, 51));
        label_5 = new QLabel(JudgeWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(430, 20, 81, 16));

        retranslateUi(JudgeWindow);

        QMetaObject::connectSlotsByName(JudgeWindow);
    } // setupUi

    void retranslateUi(QWidget *JudgeWindow)
    {
        JudgeWindow->setWindowTitle(QCoreApplication::translate("JudgeWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("JudgeWindow", "Wait to Leave", nullptr));
        label_2->setText(QCoreApplication::translate("JudgeWindow", "Arrive People", nullptr));
        label_3->setText(QCoreApplication::translate("JudgeWindow", "TotalCost", nullptr));
        label_4->setText(QCoreApplication::translate("JudgeWindow", "WinOrLost", nullptr));
        lineEdit->setText(QCoreApplication::translate("JudgeWindow", "0610789", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("JudgeWindow", "0710735", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("JudgeWindow", "\351\231\263\345\245\225\347\276\244", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("JudgeWindow", "\346\236\227\346\201\251\350\241\215", nullptr));
        pushButton->setText(QCoreApplication::translate("JudgeWindow", "Export to Database", nullptr));
        label_5->setText(QCoreApplication::translate("JudgeWindow", "PeopleSum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JudgeWindow: public Ui_JudgeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUDGEWINDOW_H
