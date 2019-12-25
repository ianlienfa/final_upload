#ifndef BUILDING_H
#define BUILDING_H

#include "data.h"
#include "judge.h"
#include "judgewindow.h"
#include "problemset.h"
#include "floor.h"
#include "scheduler.h"
#include <QTimer>
#include <iostream>
#include <cmath>

#include "shortest_longest_1.h"
#include "minesweeper_2.h"
#include "paperpassing_3.h"
#include "shygame_4.h"
#include "fib_5.h"
#include "largestroot_6.h"
#include "treewalk_7.h"
#include "factorial_8.h"
#include "shortest_summation_9.h"
#include "Add_10.h"
#include "primedistance_11.h"
#include "mario_12.h"
#include "escape_13.h"
#include "sub_14.h"
#include "findperiodstring_15.h"
#include "largefactorial_16.h"
#include "sumoflarge_17.h"
#include "longestcommonsubstring_18.h"
#include "getsolution_19.h"
#include "longestpeekpalindrome_20.h"
#include "maze_21.h"
#include "easycity2_25.h"

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
        JudgeWindow judge;
        Data data;
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
