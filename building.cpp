#include "building.h"
#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "string.h"
#include <cstring>
#include <QSqlError>
Building::Building()
{
    floor[0] = new Floor(new Add1());
    floor[1] = new Floor(new Prime());
    floor[2] = new Floor(new closest_path());
    floor[3] = new Floor(new Minesweeper());
    floor[4] = new Floor(new PaperPassing());
    floor[5] = new Floor(new longest_path());
    //floor[6] = new Floor(new longest_path());
    floor[7] = new Floor(new fib());
    floor[8] = new Floor(new LargestRoot());
    floor[9] = new Floor(new factorial());
    floor[10] = new Floor(new TreeWalk());
    floor[11] = new Floor(new Escape());
    floor[12] = new Floor(new FindPeriodString());
    floor[13] = new Floor(new LargeFactorial());
    //floor[11] = new Floor(newtree());
    //connect(timer,SIGNAL(timeout()),this, SLOT(update()));

    p1.destination.clear();
    p1.peoplenum.clear();
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
    QSqlQuery query;
    QString command1 = QString::fromStdString("DROP DATABASE Course6");
    QString command2 = QString::fromStdString("create database Course6");
    QString command3 = QString::fromStdString("USE Course6");
    QString command4 = QString::fromStdString("CREATE TABLE peoplelist (id char(8),Nowfloor int ,Destination int ,Number int)");
    QString command5 = QString::fromStdString("select * FROM peoplelist");
    QString command6 = QString::fromStdString("SHOW TABLES");
    QString command7 = QString::fromStdString("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/data.csv' INTO TABLE peoplelist FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\n' IGNORE 1 ROWS");
    query.exec(command1);
    query.exec(command2);
    query.exec(command3);
    query.exec(command4);
    query.exec(command5);
    query.exec(command6);
    query.exec(command7);
    qDebug() << query.lastError();

    query.exec("select * from peoplelist");
    srand( time(NULL) );
    int random = rand()%30 + 1;
    qDebug() << random;
    string random_string = "000" + to_string (random);
    string real_string = "SELECT * from peoplelist WHERE id LIKE '%" + random_string + "%'";
    QString q_str = QString::fromStdString(real_string);
    query.exec(q_str);

    while(query.next())
    {
        /*
        qDebug() << QString::fromStdString(random_string) << QVariant(query.value(2)).toString() << QVariant(query.value(3)).toString();
        if(query.value(1).toString() == QString::fromStdString(to_string(index))){
            p1.destination = QVariant(query.value(2)).toString();
            p1.peoplenum = QVariant(query.value(3)).toString();
        }
        */
        p1.destination.push_back((query.value(2)).toInt());
        p1.peoplenum.push_back((query.value(3)).toInt());
    }
    qDebug() << p1.peoplenum;
    qDebug() << p1.destination;
    //schedule.setSchedule(p1);

}
void Building::run(int index)
{
    string s = judge.getData(index);
    data.testdata1 = s;
    //string s2 = add1.solve(s);
    //qDebug()<<QString::fromStdString(s);
    string s2 = floor[index] -> p -> solve(s);
    //qDebug()<<index<<QString::fromStdString(s2);
    //qDebug()<<"ENDTEST";
    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();
    data.score = judge.getScore();
}
void Building::start_simulation()
{
    timer.start(100);
    timer.setSingleShot(true);
    //index = index+ 1;
}
void Building::update()
{
    data.nowfloor = schedule.getNowFloor(); //注意!!!!!不能重複寫getNowFloor，會一直+1!!!
    if(data.nowfloor!=0){
        run(data.nowfloor);
        timer.start(1000);
    }
    else{
        timer.stop();
    }

    emit this->updateGUI();
}
