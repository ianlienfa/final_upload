#include "median.h"

Median::Median()
{

}

string Median::solve(string s)
{
    vector<string> v = stringToVectorString(s);
    qDebug()<< "v[0]" << QString::fromStdString(v[0]);
    qDebug()<< "v[1]" << QString::fromStdString(v[1]);
    qDebug() << "v[2]" << QString::fromStdString(v[2]);
    qDebug() << "v[3]" << QString::fromStdString(v[3]);
    qDebug() << "v[4]" << QString::fromStdString(v[4]);


    int a = stoi(v[0]);
    int b = stoi(v[1]);
    int from = a - 1;
    int to = b - from;
    string lat_lon = (v[2] == "lat")? "lat": "lon";
    int m = stoi(v[3]);
    string asc_dsc = (v[4] == "asc")? "asc": "desc";

    QString query0 = "set @c := (select count(1) from (select "+ QString::fromStdString(lat_lon) +", (@cnt := @cnt + 1) AS rowNumber from(select "+ QString::fromStdString(lat_lon) +" from citytable where id like '%"+ QString::number(m) +"' order by "+ QString::fromStdString(lat_lon) +" "+ QString::fromStdString(asc_dsc) +" limit "+ QString::number(from) +", "+ QString::number(to) +")as dataset CROSS JOIN (SELECT @cnt := 0) AS dummy) as t2);";
    QString query1 = "select round(avg("+ QString::fromStdString(lat_lon) +"), 4) as ans from (select "+ QString::fromStdString(lat_lon) +", (@cnt := @cnt + 1) AS rownumber from (select "+ QString::fromStdString(lat_lon) +" from citytable where id like '%"+ QString::number(m) +"' order by "+ QString::fromStdString(lat_lon) +" "+ QString::fromStdString(asc_dsc) +" limit "+ QString::number(from) +", "+ QString::number(to) +") as dataset CROSS JOIN (SELECT @cnt := 0) AS dummy) as t1 where rownumber IN ( FLOOR((@c)/2), ceil((@c+1)/2) );";
    qDebug() << query0;
    qDebug() <<  query1;
    QSqlQuery query;
    query.exec("DROP SCHEMA IF EXISTS CITYDATABASE");
    query.exec("CREATE SCHEMA CITYDATABASE");
    query.exec("USE CITYDATABASE");
    query.exec("DROP TABLE CITYTABLE");
    query.exec("CREATE TABLE CITYTABLE(id int, COUNTRY VARCHAR(50), CITY VARCHAR(60), LAT DOUBLE, LON DOUBLE)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    query.exec(query0);
    query.exec(query1);

    string ans;
    while(query.next())
    {
        ans = query.value(0).toString().toStdString();
    }
    return ans;
}
