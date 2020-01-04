#include "judgewindow.h"
#include "ui_judgewindow.h"

JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    ui->setupUi(this); //ui->setup要放在前面，才能設定ui

    for(int i=0;i<27;i++)
    {
        for(int j=0;j<5;j++)
            ui -> gridLayout ->addWidget(&showline[i][j],i,j);
    }
    for(int i=0;i<27;i++)
    {
        for(int j=0;j<1;j++){
            ui -> checkbox ->addWidget(&showbox[i][j],i,j);
          //  showbox[i][j] = checked
        }
    }

    for(int i=0;i<21;i++)
        floordatatimes[i] = 10;
    for(int i=21;i<27;i++)
        floordatatimes[i] = 1;


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
    QSqlQuery query;
    QString command1 = QString::fromStdString("DROP DATABASE FINAL");
    QString command2 = QString::fromStdString("create database FINAL");
    QString command3 = QString::fromStdString("USE FINAL");
    QString command4 = QString::fromStdString("CREATE TABLE testdata (ID char(8),Floor int ,Question TEXT ,Answer TEXT)");
    QString command5 = QString::fromStdString("CREATE TABLE initial_condition (ID char(8),Nowfloor int ,Destination int ,Number int)");
    QString command6 = QString::fromStdString("select * FROM testdata");
    QString command7 = QString::fromStdString("SHOW TABLES");
    QString command8 = QString::fromStdString("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata.csv' INTO TABLE testdata FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS");
    QString command9 = QString::fromStdString("select * FROM initial_condition");
    QString command10 = QString::fromStdString("SHOW TABLES");
    QString command11 = QString::fromStdString("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/initial_condition.csv' INTO TABLE initial_condition FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\n' IGNORE 1 ROWS");
    query.exec(command1);
    query.exec(command2);
    query.exec(command3);
    query.exec(command4);
    query.exec(command5);
    query.exec(command6);
    query.exec(command7);
    query.exec(command8);
    query.exec(command9);
    query.exec(command10);
    query.exec(command11);
    qDebug() << query.lastError();
}
JudgeWindow::~JudgeWindow()
{
    delete ui;
}
string JudgeWindow::getData(int floor,int b,int& datatimes)
{
    if(floor_front==0)
    {
        distance_real=0;
        floor_front = floor;
    }

    else if(floor_front!=floor)
    {
        distance_real = distance_real + abs(floor-floor_front);
        floor_front = floor;
    }

    //distance_real = abs()
    for(int i=0;i<27;i++)
        showbox[i][0].setDisabled(true);

    //Get all the testdata from the selected floor
    QSqlQuery query;
    query.exec(QString::fromStdString("select * FROM testdata"));
    //Get Random testcase from the selected floor

    //長度 = 30，一筆一筆測資
    int random = test_data[floor-1];

    string floor_string;
    if (floor<10) //ex.07-
     {
       if(random<10)
           floor_string = "0" + to_string(floor) + "-" + "0000" + to_string(random);
       else
           floor_string = "0" + to_string(floor) + "-" + "000" + to_string(random);
     }
    else          //ex.21-
    {
       if(random<10)
           floor_string = to_string(floor) + "-" + "0000" + to_string(random);
       else
           floor_string = to_string(floor) + "-" + "000" + to_string(random);
    }

    string real_string = "SELECT * from testdata WHERE id LIKE '%" + floor_string + "%'";
    QString q_str = QString::fromStdString(real_string);
    query.exec(q_str);

    while(query.next())
    {
        ques  = (query.value(2).toString()).toStdString();
        ans   = (query.value(3).toString()).toStdString();
    }
    input = ques;
    //qDebug() << QString::fromStdString(ques);
    answer = ans;

    if(b==1)
     {  //people in
        p1.wait_to_leave[floor-1] = p1.wait_to_leave[floor-1] - 1;
     }
    else
     {
        //people out
        p1.arrive_people[floor-1] = p1.arrive_people[floor-1] - 1;
     }

    for(int i=0;i<27;i++){
        showline[i][0].setText(QString::number((p1.wait_to_leave[i])));
        showline[i][1].setText(QString::number((p1.arrive_people[i])));
    }
    datatimes = floordatatimes[floor-1];

    //測資index++
    test_data[floor-1] = test_data[floor-1] + 1;

    timer.start();

    //Showbox
    if(showbox[floor-1][0].isChecked())
        return "GIVEUP";
    return input;
}
bool JudgeWindow::submitData(string answer_cal,int floor)
{ 
    qDebug() << score[floor-1];
    if (answer == answer_cal){
        score[floor-1] = score[floor-1] + 10000000000 + pow(2,test_data[floor-1]-1);
        pass[floor-1] = pass[floor-1] + 1;
        if(floor<22){
            costtime = timer.nsecsElapsed();
            costtime = costtime/10; //costtime 平均(因為一筆測資跑了十次)
            total_cossttime[floor-1] =  total_cossttime[floor-1] + costtime;
            for(int i=0;i<27;i++){
                showline[i][2].setText(QString::number((total_cossttime[i])));
                showline[i][3].setText(QString::number((score[i])));
            }
            return 1;
        }
        else{
            costtime = timer.nsecsElapsed();
            total_cossttime[floor-1] = costtime;
            for(int i=0;i<27;i++){
                showline[i][2].setText(QString::number((total_cossttime[i])));
                showline[i][3].setText(QString::number((score[i])));
            }
            return 1;
        }

    }
    else
        return 0;
}
int JudgeWindow::getConditionNum()
{
    QSqlQuery query;
    //int random = rand()%300 + 1;
    int random = 1;

    string condition_string;
    if (random<10) //ex.00007-
       condition_string = "0000" + to_string(random) + "-";
    else if(random<100) //ex.00096-
       condition_string = "000" + to_string(random) + "-";
    else  //ex.00296-
       condition_string = "00" + to_string(random) + "-";

    //Get all floor information(peoplenum,destination) from a random condition
    query.exec(QString::fromStdString("select * FROM initial_condition"));
    string real_string = "SELECT * from initial_condition WHERE id LIKE '%" + condition_string + "%'";
    QString q_str = QString::fromStdString(real_string);
    query.exec(q_str);
    int index = 0;
    while(query.next())
    {
        p1.arrive_people[(query.value(2)).toInt()-1] = query.value(3).toInt();
        p1.wait_to_leave.push_back((query.value(3)).toInt());
    }

    for(int i=0;i<27;i++){
        showline[i][0].setText(QString::number((p1.wait_to_leave[i])));
        showline[i][1].setText(QString::number((p1.arrive_people[i])));
        showline[i][2].setText(QString::number(0));
        showline[i][3].setText(QString::number(0));
        showline[i][4].setText(QString::number(p1.wait_to_leave[i]+p1.arrive_people[i]));
        total_ques[i] = p1.wait_to_leave[i]+p1.arrive_people[i];
    }
    return random;
}


void JudgeWindow::on_pushButton_clicked()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("140.113.146.126");
    database.setUserName("aoopstudent");
    database.setPassword("tsaimother");
    database.setDatabaseName("aoopstudentuse");
    database.setPort(3306);
    bool ok = database.open();
        if(ok){
            qDebug() << "Succeessful Connection.TA";
        }
        else{
            qDebug() << "Error88787: Cannot connect!!!";
        }
    for(int i=0;i<27;i++){
        QString command2 = QString::fromStdString("INSERT INTO floorscore VALUES('0610789' , '陳奕群','0713415' , '林恩衍',")+QString::number(i+1)+", "+QString::number(total_cossttime[i])+", "+QString::number(pass[i])+", " +QString::number(total_ques[i])+", "+QString::number(score[i])+")";
        QSqlQuery query;
        query.exec(command2)?qDebug()<<"CORRECT":qDebug()<<query.lastError();
        qDebug()<<command2;
    }
    QSqlQuery query;
    QString command3 = QString::fromStdString("INSERT INTO totalpath VALUES ( '0610789' , '陳奕群','0713415' , '林恩衍',")+QString::number(distance_real)+")";
    //QString command4 = QString::fromStdString("INSERT INTO floorscore (floor,timespent,pass,'totalques','totalscore')VALUES(")+QString::number()+")";
    query.exec(command3)?qDebug()<<"CORRECT":qDebug()<<query.lastError();
    qDebug()<<command3;
}
