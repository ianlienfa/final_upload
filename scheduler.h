#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include <iostream>
#include <QtGlobal>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "people.h"
#include "data.h"
using namespace std;
typedef bool Behavior;  //1進電梯, 0出電梯


class Scheduler
{
    public:
        Scheduler(){}
        void setSchedule(People p, Data data);
        int getNowFloor();
        void toFile(vector<int> nowFloor, vector<bool> IO, vector<int> number);

    private:
        vector<int> nowFloor;  // temp
        vector<bool> IO;
        vector<int> number;    //how many people in the elevator
        int index;             // temp
        int costtime;
        int distance;
};

#endif // SCHEDULER_H
