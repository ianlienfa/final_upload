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

#include <iostream>
using namespace std;



class Building
{
    public:
        Building();
        void run(int);
        Data getData(){return data;}
    private:
        Judge judge;
        Data data;
        Add1 add1;
        Prime prime;
        Floor *floor[30];
};

#endif // BUILDING_H
