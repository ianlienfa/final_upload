#ifndef EASYCITY1_H
#define EASYCITY1_H
#include <mydatabase.h>


class Easycity1 : public MyDatabase
{
public:
    Easycity1();
    virtual string solve(string s);
};

#endif // EASYCITY1_H
