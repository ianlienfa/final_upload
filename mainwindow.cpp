#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "building.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&building,SIGNAL(updateGUI()),this, SLOT(slot_update_data()));
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
    database.setDatabaseName("Course6");
    database.setUserName("root");
    database.setPassword("et1214");
    database.setPort(3306);
    bool ok = database.open();
    if(ok){
        qDebug() << "Succeessful Connection.";

    }
    else{
        qDebug() << "Error: Cannot connect!!!";
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
    ui -> number -> setText(building.p1.peoplenum[innum]);
    ui -> destination -> setText(building.p1.destination[innum]);
    //qDebug() << building.p1.peoplenum[0];
}

void MainWindow::on_pushButton_3_clicked() //Start Simulation Button
{
    ui -> label->setVisible(false);
    building.start_simulation();
}
void MainWindow::slot_update_data()
{
    windata = building.getData();
    if(building.schedule.getNowFloor()!=0){
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
