#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>


QString cheGenerate(QString che)
{
    QString r_string;
    QString help = "city like '%";
    QString help_back = "'";
    for(int i = 0; i < che.length(); i++)
    {
        r_string += help + che[i] + help_back;
        if(i != che.length()-1)
            r_string += " or ";
    }
    return r_string;
}

QString chsGenerate(QString chs)
{
    QString r_string;
    QString help = "city not like '";
    QString help_back = "%'";
    for(int i = 0; i < chs.length(); i++)
    {
        r_string += help + chs[i] + help_back;
        if(i != chs.length()-1)
            r_string += " and ";

    }
    return r_string;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   int n = 2, m = 4;
   int sn = 0;
   int la = 122, ha = 123, lo = 25, ho = 26;
   QString nc, che, chs;
   che = "nz";
   chs = "aeiou";



//   w.connectDB();
//   QSqlQuery query;
//   query.exec("DROP SCHEMA IF EXISTS CITYDATABASE");
//   query.exec("CREATE SCHEMA CITYDATABASE");
//   query.exec("USE CITYDATABASE");
//   query.exec("DROP TABLE CITYTABLE");
//   query.exec("CREATE TABLE CITYTABLE(id int, COUNTRY VARCHAR(50), CITY VARCHAR(60), LAT DOUBLE, LON DOUBLE)");
//   query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
//   query.exec("SELECT * FROM CITYTABLE");
//   query.exec("select count(city) as c ,t7.subb from (Select city from citytable as t2 where country = (select country from (SELECT COUNTRY FROM CITYTABLE as t1 ORDER BY LENGTH(COUNTRY) desc) as t limit "+QString::number(n)+ ", 1)) as t6, (select SUBSTRING(COUNTRY, 1, 3) as subb from (SELECT COUNTRY FROM CITYTABLE as t3 ORDER BY LENGTH(COUNTRY) desc) as t4 limit 4, 1) as t7");
//   while(query.next())
//   {
//       sn = query.value(0).toInt();
//       nc = query.value(1).toString();
//       qDebug()<<"sn:"<<sn<<"nc:"<<nc;
//   }
//   query.exec("delete from citytable where ("+cheGenerate(che)+ " or (" +chsGenerate(chs)+")) or "+"(lat between " + QString::number(la) +" and " + QString::number(ha) +" and lon between " +QString::number(lo) + " and "+QString::number(ho) +")");
//   while(query.next())
//   {
//       qDebug()<<query.value(2).toString();
//   }
//   query.exec("UPDATE citytable SET lat=(@temp:=lat), lat = lon, lon = @temp where id like '%" + QString::number(m) +"'");

   //qDebug() << "delete from citytable where ("+cheGenerate(che)+ " or (" +chsGenerate(chs)+")) or "+"(lat between " + QString::number(la) +" and " + QString::number(ha) +" and lon between " +QString::number(lo) + " and "+QString::number(ho) +")";
   //CODE




   return a.exec();

}

