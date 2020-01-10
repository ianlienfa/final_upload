
#ifndef MYSTRING_H
#define MYSTRING_H
#include "problemset.h"
#include <vector>
#include <QDebug>

class MyString : public ProblemSet
{
public:
    MyString();
    virtual string solve(string) = 0;
};

#endif // MYSTRING_H
