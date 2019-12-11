#ifndef BUILDING_H
#define BUILDING_H

#include "data.h"
#include "judge.h"
#include "add1.h"
#include "prime.h"
#include "closest_path.h"
#include "problemset.h"
#include "floor.h"
#include "longest_path.h"
#include "minesweeper.h"
#include "paperpassing.h"
#include "fib.h"
#include "largestroot.h"
#include "factorial.h"
#include "treewalk.h"
#include "escape.h"
#include "scheduler.h"

#include <QTimer>
#include <iostream>
using namespace std;



class Building:public QObject
{
    Q_OBJECT
    public:
        Building();
        void run(int);
        void start_simulation();
        Data getData(){return data;}
        People p1;
        Scheduler schedule;
    private:
        Judge judge;
        Data data;
        Add1 add1;
        Prime prime;
        Floor *floor[30];
        int innum;
        QTimer timer;


    public slots:
        //declare the slot function here
        void update();
        //void slot_update_data();
    signals:
        //declare the signal function here ex::void updateGUI()
        void updateGUI();
};

#endif // BUILDING_H
