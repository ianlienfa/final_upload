#include "easycity1.h"
#include "mydatabase.h"
easycity1::easycity1()
{

}
string easycity1::solve(string s)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    //database.setDatabaseName("Course6");
    database.setUserName("root");
<<<<<<< HEAD
    database.setPassword("12345678");
=======
    database.setPassword("et1214");
>>>>>>> branch1
    database.setPort(3306);
    bool ok = database.open();
        if(ok){
            qDebug() << "Succeessful Connection.";

        }
        else{
            qDebug() << "Error88787: Cannot connect!!!";
        }
    QSqlQuery query;
    QString command1 = QString::fromStdString("DROP DATABASE CITYDATABASE");
    QString command2 = QString::fromStdString("create database CITYDATABASE");
    QString command3 = QString::fromStdString("USE CITYDATABASE");
    QString command4 = QString::fromStdString("CREATE TABLE CITYTABLE (id char(8),Nowfloor int ,Destination int ,Number int)");
    QString command5 = QString::fromStdString("select * FROM peoplelist");
    QString command6 = QString::fromStdString("SHOW TABLES");
    QString command7 = QString::fromStdString("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/data.csv' INTO TABLE peoplelist FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\n' IGNORE 1 ROWS");
}
