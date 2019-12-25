#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "building.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&building,SIGNAL(updateGUI()),this, SLOT(slot_update_data())); //if updateGUI() happens, then invoke slot_update_data()
}

MainWindow::~MainWindow()
{
    delete ui;
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
        ui -> NowElevator -> display(windata.nowfloor);
        ui -> PeopleinElevator-> display(windata.elevatorpeople);
        ui -> DIstance -> display(windata.distance);
    }
    else{
        ui -> label->setVisible(true);
    }
}
