#include "easycity2.h"

EasyCity2::EasyCity2()
{

}

QString EasyCity2::cheGenerate(string s)
{
    QString che = QString::fromStdString(s);
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

QString EasyCity2::chsGenerate(string s)
{
    QString chs = QString::fromStdString(s);
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

string EasyCity2::solve(string s)
{

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

    vector<string> s_in = stringToVectorString(s);
    vector<string> s_out;

    //set Input parameters
    int n = 2, m = 4;
    double la = 121.5, ha = 131.5, lo = 25.3, ho = 30.3;
    string nc, che, chs, lar_or_small;
    che = "aeiou";
    chs = "NZ";

    n = stoi(s_in[0]);
    lar_or_small = s_in[1];
    chs = s_in[2];
    che = s_in[3];
    la = stod(s_in[4]);
    ha = stod(s_in[5]);
    lo = stod(s_in[6]);
    ho = stod(s_in[7]);
    m = stoi(s_in[8]);

    QSqlQuery query;
    query.exec("DROP SCHEMA IF EXISTS CITYDATABASE");
    query.exec("CREATE SCHEMA CITYDATABASE");
    query.exec("USE CITYDATABASE");
    query.exec("DROP TABLE CITYTABLE");
    query.exec("CREATE TABLE CITYTABLE(id int, COUNTRY VARCHAR(50), CITY VARCHAR(60), LAT DOUBLE, LON DOUBLE)");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    query.exec("SELECT * FROM CITYTABLE");
    query.exec("select count(city) as c ,t7.subb from (Select city from citytable as t2 where country = (select country from (SELECT COUNTRY FROM CITYTABLE as t1 ORDER BY LENGTH(COUNTRY) desc) as t limit "+QString::number(n)+ ", 1)) as t6, (select SUBSTRING(COUNTRY, 1, 3) as subb from (SELECT COUNTRY FROM CITYTABLE as t3 ORDER BY LENGTH(COUNTRY) desc) as t4 limit 4, 1) as t7");
    while(query.next())
    {
    s_out.push_back(query.value(1).toString().toStdString());
    s_out.push_back(query.value(0).toString().toStdString());
    //qDebug()<<"sn:"<<query.value(1).toString()<<"nc:"<<query.value(0).toString();
    }
    query.exec("delete from citytable where ("+cheGenerate(che)+ " or (" +chsGenerate(chs)+")) or "+"(lat between " + QString::number(la) +" and " + QString::number(ha) +" and lon between " +QString::number(lo) + " and "+QString::number(ho) +")");
    //qDebug() << "delete from citytable where ("+cheGenerate(che)+ " or (" +chsGenerate(chs)+")) or "+"(lat between " + QString::number(la) +" and " + QString::number(ha) +" and lon between " +QString::number(lo) + " and "+QString::number(ho) +")";

//    while(query.next())
//    {
//    qDebug()<<query.value(0).toString();
//    qDebug()<<query.value(1).toString();
//    qDebug()<<query.value(2).toString();
//    }

    query.exec("UPDATE citytable SET lat=(@temp:=lat), lat = lon, lon = @temp where id like '%" + QString::number(m) +"'");
    //qDebug() << "UPDATE citytable SET lat=(@temp:=lat), lat = lon, lon = @temp where id like '%" + QString::number(m) +"'";

    query.exec("select round(c.ans, 4) from (select sqrt(x_dif + y_dif) as ans from (select pow(x1-x2, 2) as x_dif, pow(y1-y2, 2) as y_dif from(select min(LAT) as x1 ,max(LAT) as x2, max(LON) as y1, min(LON) as y2 from citytable )as minmax)as square) as c");
    //qDebug() << "select round(c.ans, 4) from (select sqrt(x_dif + y_dif) as ans from (select pow(x1-x2, 2) as x_dif, pow(y1-y2, 2) as y_dif from(select min(LAT) as x1 ,max(LAT) as x2, max(LON) as y1, min(LON) as y2 from citytable )as minmax)as square) as c";
    while(query.next())
    {
        s_out.push_back(query.value(0).toString().toStdString());
        //qDebug() << query.value(0).toString();
    }
    string result = vectorStringToString(s_out);
    return result;
}
