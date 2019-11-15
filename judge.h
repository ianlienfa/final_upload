#ifndef JUDGE_H
#define JUDGE_H
#include <iostream>
#include <QtGlobal>
#include <fstream>
#include <QElapsedTimer>
#include <stdlib.h>
#include <time.h> //for random number
#include <vector>
using namespace std;

class Judge
{
    public:
        Judge();
        string getData(int question);
        bool submitData(string answer);
        qint64 getSpendTime(){return costtime;}
    private:
        string ans;
        ifstream in;
        QElapsedTimer timer;
        qint64 costtime;
};

#endif // JUDGE_H
