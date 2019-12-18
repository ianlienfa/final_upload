#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "building.h"
#include "shygame.h"
#include "largestroot.h"
#include "scheduler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectDB()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("12345678"); // your password
    database.setPort(3306);
    bool ok = database.open();
    if(ok){
    qDebug()<<"Successful Connection.";
    }else{
    qDebug()<<"Error: Cannot connect!!!";
    }
}


void MainWindow::on_pushButton_clicked()
{
     building.run(ui->comboBox->currentIndex());
     windata = building.getData();

     count = count + 1;
     spendtime = spendtime + windata.spendtime1;
     if(windata.spendtime1>400000)
     {
         spendtime = 0;
     }
     if(count > 200)
     {
         count = 0;
         spendtime = 0;
     }

     //qDebug() << count << " " << spendtime/count ;

     ui -> Testdata1 -> setText(QString::fromStdString(windata.testdata1));
     ui -> Submitdata1 -> setText(QString::fromStdString(windata.submit1));
     ui -> SpendTime1 -> setText(QString::number(windata.spendtime1));
     ui -> Correctornot1 -> setText(QString::number(windata.correct1));

}

void MainWindow::on_pushButton_2_clicked()
{
    innum = ui->comboBox->currentIndex();
    ui -> number -> setText(QString::number(building.p1.peoplenum[innum]));
    ui -> destination -> setText(QString::number(building.p1.destination[innum]));
    //qDebug() << building.p1.peoplenum[0];


    Scheduler scheduler;
    People people1; Data data2;
    people1.peoplenum.push_back(4);
    people1.peoplenum.push_back(8);
    people1.peoplenum.push_back(3);
    people1.peoplenum.push_back(11);
    people1.destination.push_back(5);
    people1.destination.push_back(7);
    people1.destination.push_back(2);
    people1.destination.push_back(1);
    scheduler.setSchedule(people1, data2);
}

void MainWindow::on_pushButton_3_clicked() //Start Simulation Button
{
    ui -> label->setVisible(false);
    building.start_simulation();
}
void MainWindow::slot_update_data()
{
    windata = building.getData();
    if(windata.nowfloor!=0){
        ui -> Testdata1 -> setText(QString::fromStdString(windata.testdata1));
        ui -> Submitdata1 -> setText(QString::fromStdString(windata.submit1));
        ui -> SpendTime1 -> setText(QString::number(windata.spendtime1));
        ui -> Correctornot1 -> setText(QString::number(windata.correct1));
        ui -> Score1 -> setText(QString::number(windata.score));
    }
    else{
        ui -> label->setVisible(true);
    }
}
