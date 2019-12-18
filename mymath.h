#ifndef MYMATH_H
#define MYMATH_H

#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include "problemset.h"
#include <string>
#include <QDebug>
using namespace std;


class MyMath : public ProblemSet
{
    public:
        MyMath();
        virtual string solve(string) = 0;
        vector<int>stringtoVectorInt(string);
        vector<double>stringtoVectordouble(string);
        string vectorIntToString(vector<int>);
        string vectordoubleToString(vector<double>);
        vector<string> stringToVectorString(string);

};

#endif // MYMATH_H
