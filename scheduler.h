#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include <iostream>
#include <QtGlobal>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
#include <utility>
#include "people.h"
#include "data.h"
typedef bool Behavior;  //1進電梯, 0出電梯

using namespace std;

class Scheduler
{
    public:
        Scheduler(){}
        void setSchedule(People p, Data data);
        int getNowFloor(int);
        int getDoorIO(int);
        int getElevatorPeople(int);
        void toFile(vector<int> nowFloor, vector<bool> IO, vector<int> number);
        int index = 0; //index to access nowFloor,IO,number
        bool terminate = 1;

    private:
        vector<int> nowFloor;  // temp
        vector<bool> IO;       // In or Out
        vector<int> number;    //how many people in the elevator
        int costtime;
        int distance;
};

#endif // SCHEDULER_H
