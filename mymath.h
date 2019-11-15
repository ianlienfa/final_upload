#ifndef MYMATH_H
#define MYMATH_H

#include <iostream>
#include <sstream>
#include <vector>
#include "problemset.h"
#include <string>
#include <QDebug>
using namespace std;


class MyMath : public ProblemSet
{
    public:
        MyMath();
        string solve(string);
        vector<int>stringtoVectorInt(string);
        string vectorIntToString(vector<int>);
};

#endif // MYMATH_H
