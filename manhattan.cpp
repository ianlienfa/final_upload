#include "manhattan.h"

Manhattan::Manhattan()
{

}

string Manhattan::solve(string s)
{
    string ans;
    vector<int> vec = stringtoVectorInt(s);
    QSqlQuery query;
    query.exec("DROP SCHEMA IF EXISTS CITYDATABASE");
    query.exec("CREATE SCHEMA CITYDATABASE");
    query.exec("USE CITYDATABASE");
    query.exec("DROP TABLE CITYTABLE");
    query.exec("CREATE TABLE CITYTABLE(id int, COUNTRY VARCHAR(50), CITY VARCHAR(60), LAT DOUBLE, LON DOUBLE)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    QString query1;
    int from = vec[0] - 1;
    int to = vec[1] - vec[0] - 1;
    int v1 = vec[2];
    int v2 = vec[3];
//    query1 = "select round((x_minus + y_minus), 4) as ans from (select lar_lon_x1-sml_lon_x2 as x_minus, lar_lat_y1-sml_lat_y2 as y_minus from (select max(t1.lon) as lar_lon_x1, min(t1.lon) as sml_lon_x2, max(t2.lat) as lar_lat_y1, min(t2.lat) as sml_lat_y2  from (select lat, lon from citytable where lat < "+ QString::number(v1) +" order by lat desc limit ( "+ QString::number(from) +" , "+ QString::number(to) +") as t1,  (select lon, lat from citytable where lon > "+ QString::number(v2) +" order by lon asc limit ("+ QString::number(from) +", "+ QString::number(to) +") as t2) as min_max) as minus";
    query1 = "select  round((x_minus + y_minus), 4) as ans from(select lar_lon_x1-sml_lon_x2 as x_minus, lar_lat_y1-sml_lat_y2 as y_minus from (select max(t1.lon) as lar_lon_x1, min(t1.lon) as sml_lon_x2, max(t2.lat) as lar_lat_y1, min(t2.lat) as sml_lat_y2  from (select lat, lon from citytable where lat < "+ QString::number(v1) +" order by lat desc limit "+ QString::number(from) +", "+ QString::number(to) +") as t1,  (select lon, lat from citytable where lon > "+ QString::number(v2) +" order by lon asc limit "+ QString::number(from) +", "+ QString::number(to) +") as t2)as min_max)as minus";
    qDebug() << query1;
    query.exec(query1);
    while(query.next())
    {
        ans = query.value(0).toString().toStdString();
        //qDebug() << query.value(0).toString();
    }

    qDebug() << "ans:" <<QString::fromStdString(ans);
    return ans;
}
