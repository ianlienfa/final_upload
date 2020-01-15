#include "symmmetric.h"

Symmmetric::Symmmetric()
{

}

string Symmmetric::solve(string s)
{
    string ans;
    vector<string> v = stringToVectorString(s);
    int ev_od = (v[0] == "ev")? 0:1;
    string m = v[1];
    string n = v[2];
    int k = stoi(v[3]);
    int from = k -1;
    qDebug() << "ev_od:" << QString::number(ev_od);
    qDebug() << "id end with:" << QString::fromStdString(m);
    qDebug() << "round to ::" << QString::fromStdString(n);
    qDebug() << "from:" << QString::number(from);

    QString query1 = "UPDATE citytable SET lat=@tmp:=lat, lat=lon, lon=@tmp where id%2 = "+QString::number(ev_od)+";";
    QString query2 = "UPDATE citytable SET lat = lon where id like '%"+QString::fromStdString(m)+"';";
    QString query3 = "select lat, lon from (select round(lat, "+QString::fromStdString(n)+") as lat, round(lon, "+QString::fromStdString(n)+") as lon, id from citytable)as a join (select round(lat, "+QString::fromStdString(n)+") as lat_b, round(lon, "+QString::fromStdString(n)+") as lon_b, id as id_b from citytable) as b where lat = lon_b and lon = lat_b and id != id_b and lat <= lon group by lat, lon order by lat , lon limit "+QString::number(from)+", 1;";


    qDebug() << query1;
    qDebug() << query2;
    qDebug() << query3;
    QSqlQuery query;
    query.exec("DROP SCHEMA IF EXISTS CITYDATABASE");
    query.exec("CREATE SCHEMA CITYDATABASE");
    query.exec("USE CITYDATABASE");
    query.exec("DROP TABLE CITYTABLE");
    query.exec("CREATE TABLE CITYTABLE(id int, COUNTRY VARCHAR(50), CITY VARCHAR(60), LAT DOUBLE, LON DOUBLE)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    query.exec(query1);
    query.exec(query2);
    query.exec(query3);

    while(query.next())
    {
        qDebug() << QString::number(query.value(0).toDouble(), 'f', stoi(n));
        ans = QString::number(query.value(0).toDouble(), 'f', stoi(n)).toStdString();
        ans += " ";
        ans += QString::number(query.value(1).toDouble(), 'f', stoi(n)).toStdString();
    }
    qDebug() << "ans:" << QString::fromStdString(ans);

    return ans;
}
