#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include "floor.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    w.connectDB();
    /*
    QSqlQuery query;
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/data.csv' INTO TABLE peoplelist FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\\r\\n' IGNORE 1 ROWS");

    query.exec("select * from peoplelist");
    srand( time(NULL) );
    int random = rand()%30 + 1;
    string random_string = "000" + to_string (random);
    string real_string = "SELECT * from peoplelist WHERE id LIKE '%" + random_string + "%'";
    QString q_str = QString::fromStdString(real_string);
    query.exec(q_str);
*/
/*
    Floor f1;
    while(query.next())
    {
        if(query.value(1).toString() =="1"){
            f1.p1.destination = query.value(2);
            f1.p1.peoplenum = query.value(3);
        }
        if(query.value(1).toString() =="2"){
            f1.p1.destination = query.value(2).toString();
            f1.p1.destination = query.value(2).toString();
        }
        if(query.value(1).toString() =="1"){
            f1.p1.destination = query.value(2).toString();
            f1.p1.destination = query.value(2).toString();
        }
        if(query.value(1).toString() =="1"){
            f1.p1.destination = query.value(2).toString();
            f1.p1.destination = query.value(2).toString();
        }
        if(query.value(1).toString() =="1"){
            f1.p1.destination = query.value(2).toString();
            f1.p1.destination = query.value(2).toString();
        }
        if(query.value(1).toString() =="1"){
            f1.p1.destination = query.value(2).toString();
            f1.p1.destination = query.value(2).toString();
        }
        if(query.value(1).toString() =="1"){
            f1.p1.destination = query.value(2).toString();
            f1.p1.destination = query.value(2).toString();
        }
        if(query.value(1).toString() =="1"){
            f1.p1.destination = query.value(2).toString();
            f1.p1.destination = query.value(2).toString();
        }
        if(query.value(1).toString() =="1"){
            f1.p1.destination = query.value(2).toString();
            f1.p1.destination = query.value(2).toString();
        }
    }*/
    return a.exec();
}
