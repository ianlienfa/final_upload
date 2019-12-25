#ifndef MYDATABASE_H
#define MYDATABASE_H
#include "problemset.h"
#include <vector>
#include <iomanip>
#include <sstream>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;

class MyDatabase: public ProblemSet
{
public:
    MyDatabase();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
    vector<string> stringToVectorString(string);
    vector<QString> stringToVectorQString(string);
    string vectorStringToString(vector<string>);

};

#endif // MYDATABASE_H
