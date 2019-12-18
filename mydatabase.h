#ifndef MYDATABASE_H
#define MYDATABASE_H
#include "problemset.h"
#include <vector>
#include <iomanip>
#include <sstream>
#include <QDebug>
using namespace std;

class MyDatabase
{
public:
    MyDatabase();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
};

#endif // MYDATABASE_H
