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
        void string_tidy_up(string &s)
        {
            string::size_type pos = 0;
            while(pos != string::npos)
            {
                pos = s.find_first_of("\r\n", pos);
                if(pos != string::npos)
                    s.erase(pos, 1);
            }
            while (s.at(s.length()-1) == ' ')
            {
                s.erase(s.length()-1, 1);
            }
        }

};

#endif // JUDGE_H
