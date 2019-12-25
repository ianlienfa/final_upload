#ifndef EASYCITY2_H
#define EASYCITY2_H
#include "mydatabase.h"

class EasyCity2 : public MyDatabase
{
public:
    EasyCity2();
    string solve(string);
    QString chsGenerate(string);
    QString cheGenerate(string);
};

#endif // EASYCITY2_H
