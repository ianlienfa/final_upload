#ifndef BUILDING_H
#define BUILDING_H

#include "data.h"
#include "judge.h"
#include "add1.h"
#include "prime.h"
#include "paperpassing.h"
#include <iostream>
using namespace std;



class Building
{
    public:
        Building();
        void run();
        Data getData(){return data;}
    private:
        Judge judge;
        Data data;

        //以下開始為小遊戲
        Add1 add1;
        Prime prime;
        PaperPassing paperpassing;

};

#endif // BUILDING_H
