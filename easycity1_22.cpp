#include "easycity1_22.h"

Easycity1::Easycity1()
{

}
string Easycity1::solve(string s)
{
    /*
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    //database.setDatabaseName("Course6");
    database.setUserName("root");
    database.setPassword("12345678");
    database.setPort(3306);
    bool ok = database.open();
        if(ok){
            qDebug() << "Succeessful Connection.";

        }
        else{
            qDebug() << "Error88787: Cannot connect!!!";
        }
        */
        QSqlQuery query;
        query.exec("DROP SCHEMA IF EXISTS CITYDATABASE");
        query.exec("CREATE SCHEMA CITYDATABASE");
        query.exec("USE CITYDATABASE");
        query.exec("DROP TABLE CITYTABLE");
        query.exec("CREATE TABLE CITYTABLE(id int, COUNTRY VARCHAR(50), CITY VARCHAR(60), LAT DOUBLE, LON DOUBLE)");
        query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");

        vector<string> s_que = stringToVectorString(s);
        string ch = "nz", la = "121.5", lo = "25.3", p = "2", q = "5", ev_od = "od", m = "5", even_odd = "even", asc_des = "des", n = "3";

        ch = s_que[0];
        la = s_que[1];
        lo = s_que[2];
        p = s_que[3];
        q = s_que[4];
        ev_od = s_que[5];
        m = s_que[6];
        even_odd = s_que[7];
        asc_des = s_que[8];
        n = s_que[9];

        vector<string> s_out;

        if(asc_des == "des")
            asc_des = "desc";


        query.exec("select count(city)-count(distinct city) as diff from (SELECT * FROM citytable WHERE city REGEXP '^[" + QString::fromStdString(ch) + "]' and city NOT REGEXP'[aeiou]$' and lat > " +QString::fromStdString(la)+ " and lon < "+ QString::fromStdString(lo) +" < 25.3) as t1");

        while(query.next())
        {
            s_out.push_back(query.value(0).toString().toStdString());

            //qDebug() << query.value(0).toString();
        }

        qDebug() << "select count(city)-count(distinct city) as diff from (SELECT * FROM citytable WHERE city REGEXP '^[" + QString::fromStdString(ch) + "]' and city NOT REGEXP'[aeiou]$' and lat > " +QString::fromStdString(la)+ " and lon < "+ QString::fromStdString(lo) +" < 25.3) as t1";

        if(ev_od == "od")
            query.exec("UPDATE citytable SET lat = lat*" +QString::fromStdString(p)+ ", Lon = lon*"+QString::fromStdString(q)+" WHERE id%2 = 1");
        else {
            query.exec("UPDATE citytable SET lat = lat*" +QString::fromStdString(p)+ ", Lon = lon*"+QString::fromStdString(q)+" WHERE id%2 = 0");

        }

        qDebug() << "UPDATE citytable SET lat = lat*" +QString::fromStdString(p)+ ", Lon = lon*"+QString::fromStdString(q)+" WHERE id%2 = 0";

        if(even_odd == "even")
            query.exec("select round(sum(lat), "+QString::fromStdString(n)+"), round(sum(lon), "+QString::fromStdString(n)+"), max(l) - min(l) from ( select length(city) as l, s0.* from (select * from citytable where id%2 = 0) as s0 order by length(city) "+QString::fromStdString(asc_des)+", city desc limit "+QString::fromStdString(m)+") as s1");
        else
            query.exec("select round(sum(lat), "+QString::fromStdString(n)+"), round(sum(lon), "+QString::fromStdString(n)+"), max(l) - min(l) from ( select length(city) as l, s0.* from (select * from citytable where id%2 = 1) as s0 order by length(city) "+QString::fromStdString(asc_des)+", city desc limit "+QString::fromStdString(m)+") as s1");

        qDebug() << "select round(sum(lat), "+QString::fromStdString(n)+"), round(sum(lon), "+QString::fromStdString(n)+"), max(l) - min(l) from ( select length(city) as l, s0.* from (select * from citytable where id%2 = 1) as s0 order by length(city) "+QString::fromStdString(asc_des)+", city desc limit "+QString::fromStdString(m)+") as s1";


        while(query.next())
        {
            s_out.push_back(query.value(0).toString().toStdString());
            s_out.push_back(query.value(1).toString().toStdString());
            s_out.push_back(query.value(2).toString().toStdString());

            //qDebug() << query.value(0).toString();
        }
        string ans = vectorStringToString(s_out);

        qDebug() << QString::fromStdString(ans);

        return ans;


}
