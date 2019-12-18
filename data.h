#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <QtGlobal>
#include <fstream>
#include <QElapsedTimer>
#include <vector>
using namespace std;

class Data
{
    public:
        Data();
        qint64 spendtime1,spendtime2;
        string testdata1,testdata2;
        string submit1,submit2;
        bool correct1,correct2;
        int nowfloor,score;
        vector<int> distance, elevatorpeople;
};

#endif // DATA_H
