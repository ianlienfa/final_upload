#include "lsdistance.h"

LSdistance::LSdistance()
{

}

string LSdistance::solve(string s)
{
    string result;
    vector<string> vc = stringToVectorString(s);
    //vc[0] -- n, vc[1] -- a, vc[2] -- b, vc[3] -- al/ra

    QSqlQuery query;
    query.exec("DROP SCHEMA IF EXISTS CITYDATABASE");
    query.exec("CREATE SCHEMA CITYDATABASE");
    query.exec("USE CITYDATABASE");
    query.exec("DROP TABLE CITYTABLE");
    query.exec("CREATE TABLE CITYTABLE(id int, COUNTRY VARCHAR(50), CITY VARCHAR(60), LAT DOUBLE, LON DOUBLE)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    query.exec("select round(LAT, " +QString::fromStdString(vc[0])+") as LAT_rounded, round(LON, " + QString::fromStdString(vc[0])+ ") as LON_rounded from citytable");  //接下來的code



    return result;
}
