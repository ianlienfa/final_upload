#include "ls_distance.h"

LS_Distance::LS_Distance()
{

}

string LS_Distance::solve(string s)
{
    vector<string> v = stringToVectorString(s);
    int n = stoi(v[0]);
    int a = stoi(v[1]);
    int b = stoi(v[2]);
    int from = a - 1;
    int to = b - from;
    string al_ra = (v[3] == "al") ? "asc" : "desc";
    QString query1 = "select round(max(distance), 4), round(min(distance), 4) from (select * , sqrt(power(a.r_lat-b.r_lat_b, 2) + power(a.r_lon-b.r_lon_b, 2)) as Distance from (select lat as r_lat, lon as r_lon , city as city_from , country as country_from from (select round(lat, " +QString::number(n)+ ") as lat, round(lon, " +QString::number(n)+ ") as lon, city, country, id from citytable) as tb group by lat, lon order by city " +QString::fromStdString(al_ra)+ ", id asc limit " +QString::number(from)+ ", " +QString::number(to)+ ")as a join (select lat as r_lat_b, lon as r_lon_b , city as city_to , country as country_to  from (select round(lat, " +QString::number(n)+ ") as lat, round(lon, " +QString::number(n)+ ") as lon, city, country, id from citytable) as tb group by lat, lon order by city " +QString::fromStdString(al_ra)+ ", id asc limit " +QString::number(from)+ ", " +QString::number(to)+ ") as b on a.r_lat >= b.r_lat_b) as disTable  where r_lat != r_lat_b or r_lon != r_lon_b;";

    qDebug() << "v[0]" << QString::fromStdString(v[0]);
    qDebug() << "v[1]" << QString::fromStdString(v[1]);
    qDebug() << "v[2]" << QString::fromStdString(v[2]);
    qDebug() << "v[3]" << QString::fromStdString(v[3]);
    qDebug() << "from: " << QString::number(from);
    qDebug() << "to: " << QString::number(to);
    qDebug() << "al_ra" << QString::fromStdString(al_ra);
    qDebug() << query1;


    QSqlQuery query;
    query.exec("DROP SCHEMA IF EXISTS CITYDATABASE");
    query.exec("CREATE SCHEMA CITYDATABASE");
    query.exec("USE CITYDATABASE");
    query.exec("DROP TABLE CITYTABLE");
    query.exec("CREATE TABLE CITYTABLE(id int, COUNTRY VARCHAR(50), CITY VARCHAR(60), LAT DOUBLE, LON DOUBLE)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    query.exec(query1);

    string ans;
    while(query.next())
    {
        ans = query.value(0).toString().toStdString();
    }
    qDebug() << "ans:" << QString::fromStdString(ans);
    return ans;
}
