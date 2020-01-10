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

    floor[0] = new Floor(new Shortest_Longest_1);
    floor[1] = new Floor(new Minesweeper());
    floor[2] = new Floor(new PaperPassing());
    floor[3] = new Floor(new ShyGame());
    floor[4] = new Floor(new fib);
    floor[5] = new Floor(new LargestRoot());
    floor[6] = new Floor(new TreeWalk());
    floor[7] = new Floor(new factorial());
    floor[8] = new Floor(new Shortest_Summation_9);
    floor[9] = new Floor(new Add1());
    floor[10] = new Floor(new PrimeDistance());
    floor[11] = new Floor(new MarioCoin());
    floor[12] = new Floor(new Escape());
    floor[13] = new Floor(new Sub_14());
    floor[14] = new Floor(new FindPeriodString());
    floor[15] = new Floor(new LargeFactorial());
    floor[16] = new Floor(new SumOfLarge());
    floor[17] = new Floor(new LongestSubstring());
    floor[18] = new Floor(new Gaussian());
    floor[19] = new Floor(new LongestPalindrome());
    floor[20] = new Floor(new Maze());
    floor[21] = new Floor(new Easycity1());
    //floor[15] = new Floor(new Add1());
    floor[24] = new Floor(new EasyCity2());
    //floor[11] = new Floor(new TreeWalk());
    //floor[11] = new Floor(newtree());
    connect(&timer,SIGNAL(timeout()),this, SLOT(update()));

    judge.show();
    judge.setSeed(0);
    int random = judge.getConditionNum(); //get People data according variable n

    /*
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("et1214");
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
    //QString command1 = QString::fromStdString("DROP DATABASE FINAL");
    //QString command2 = QString::fromStdString("create database FINAL");
    //QString command3 = QString::fromStdString("USE FINAL");
    //QString command4 = QString::fromStdString("CREATE TABLE initial_condition (ID char(8),Nowfloor int ,Destination int ,Number int)");
    //QString command5 = QString::fromStdString("select * FROM initial_condition");
    //QString command6 = QString::fromStdString("SHOW TABLES");
    //QString command7 = QString::fromStdString("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/initial_condition.csv' INTO TABLE initial_condition FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\n' IGNORE 1 ROWS");
    //query.exec(command1);
    //query.exec(command2);
    //query.exec(command3);
    //query.exec(command4);
    //query.exec(command5);
    //query.exec(command6);
    //query.exec(command7); JudgeWindow load 過 data，Building 不要再load!!!!，會重複load
    //qDebug() << query.lastError();

    //Create condition_string for random number we get
    string condition_string;
    if (random<10) //ex.00007-
       condition_string = "0000" + to_string(random) + "-";
    else if(random<100) //ex.00096-
       condition_string = "000" + to_string(random) + "-";
    else  //ex.00296-
       condition_string = "00" + to_string(random) + "-";

    qDebug() << random;
    //Get all floor information(peoplenum,destination) from a random condition
    query.exec(QString::fromStdString("select * FROM initial_condition"));
    string real_string = "SELECT * from initial_condition WHERE id LIKE '" + condition_string + "%'";

    QString q_str = QString::fromStdString(real_string);
    query.exec(q_str);
    qDebug()<<q_str;
    int index = 0;
    p1.wait_to_leave.clear();
    int index2=0;
    while(query.next())
    {
        p1.arrive_people[(query.value(2)).toInt()-1] = query.value(3).toInt();
        p1.wait_to_leave.push_back((query.value(3)).toInt());
        p1.destination.push_back((query.value(2)).toInt());
        qDebug()<<index2;
        index2++;
    }

    for(int j=0;j<p1.wait_to_leave.size();j++)
        qDebug() << p1.arrive_people[j] << p1.wait_to_leave[j] << p1.destination[j];
    //Call scheduling Algorithm，store all information in p1
    schedule.setSchedule(p1,data);

}
void Building::run(int index)
{
    int times;
    qDebug() << index << schedule.getDoorIO(schedule.index) << schedule.getElevatorPeople(schedule.index);
    //取測資
    string s = judge.getData(index,schedule.getDoorIO(schedule.index),times);
    //qDebug() << times;
    data.testdata1 = s;
    qDebug() << QString::fromStdString(s);
    string s2;

    //單一測資重複run，取時間平均
    for(int i=0;i<times;i++)
    {
        if(s=="GIVEUP")
            s2 = "";
        else{
            qDebug() << "Building run";
            s2 = floor[index-1] -> p -> solve(s);
            qDebug() << QString::fromStdString(s2);
        }
    }
    data.submit1 = s2;
    bool correct = judge.submitData(s2,index);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();
}
void Building::start_simulation()
{
    timer.start(100);
    timer.setSingleShot(true);
}
void Building::update()
{
    qDebug() << "RRRR" ;
    qDebug() << schedule.index;
    data.nowfloor = schedule.getNowFloor(schedule.index); //注意!!!!!不能重複寫getNowFloor，會一直+1!!!
    qDebug() << data.nowfloor << schedule.getDoorIO(schedule.index);
    if(schedule.terminate)
    {
        if(schedule.getDoorIO(schedule.index)==1)//People in, elevator people ++,solve problem
        {
            data.elevatorpeople = data.elevatorpeople + schedule.getElevatorPeople(schedule.index);

            if(schedule.index ==0)
                data.distance = 0;
            else
                data.distance = data.distance + abs(schedule.getNowFloor(schedule.index) - schedule.getNowFloor(schedule.index-1));

            for(int i=0;i<schedule.getElevatorPeople(schedule.index);i++)
            {
                run(data.nowfloor); //run完之後
                timer.start(100);   //再跑timer
            }
        }
        else //People out, elevator people--, peoplenum of departure -- (arrived at destination), solve problem
        {
            data.elevatorpeople = data.elevatorpeople - schedule.getElevatorPeople(schedule.index);

            if(schedule.index ==0)
                data.distance = 0;
            else
                data.distance = data.distance + abs(schedule.getNowFloor(schedule.index) - schedule.getNowFloor(schedule.index-1));

            for(int i=0;i<schedule.getElevatorPeople(schedule.index);i++)
            {
                run(data.nowfloor); //run完之後
                timer.start(100);   //再跑timer
            }
        }

        schedule.index = schedule.index + 1; //跑完一行scheduling後，index++
    }
    else
    {
        timer.stop();
    }
    qDebug() << "DDDD" ;
    emit this->updateGUI();
    qDebug() << "CCCC" ;
}
