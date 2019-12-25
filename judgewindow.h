#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QElapsedTimer>
#include <time.h> //for random number
#include "math.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <string>
#include "people.h"
#include <QLineEdit>
#include <QCheckBox>
using namespace std;
namespace Ui {
class JudgeWindow;
}

class JudgeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit JudgeWindow(QWidget *parent = nullptr);
    ~JudgeWindow();
    string getData(int floor,int b,int& datatimes);//input 0-26
    bool submitData(string ans,int floor);
    void setSeed(int seed){srand(seed);}
    qint64 getSpendTime(){return costtime;}
    int getConditionNum();//return 1-300
    int getDistance(){return distance;}
    void scheduleEnd();
    People p1;

private:
    Ui::JudgeWindow *ui;
    QLineEdit showline[27][4];
    QCheckBox showbox [27][1];
    QElapsedTimer timer;
    qint64 costtime,total_cossttime[27];//cosstime of an attempt; total costtime of successful attempts in a question
    int distance;
    string ques,ans;
    int testdata_groupnum_length,testdata_groupnum_random_element;
    string input,answer;
    int floordatatimes[27];
    int test_data[27]={0};//紀錄要執行哪一筆測資，給judge.getData()用，決定要拿哪一筆測資。
    int score[27];
};

#endif // JUDGEWINDOW_H
