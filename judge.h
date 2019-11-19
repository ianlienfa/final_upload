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
        string geteveryData (string file_name);
        bool submitData(string answer);
        qint64 getSpendTime(){return costtime;}
    private:
        string input,ans;
        ifstream in;
        QElapsedTimer timer;
        qint64 costtime;
        void string_tidy_up(string &s); //去除txt每一行尾端的空白鍵
};

#endif // JUDGE_H
