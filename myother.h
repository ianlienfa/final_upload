#ifndef MYOTHER_H
#define MYOTHER_H
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include "problemset.h"
#include <string>
#include <QDebug>

class MyOther : public ProblemSet
{
public:
    MyOther();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
};

#endif // MYOTHER_H

