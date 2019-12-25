#ifndef LSDISTANCE_H
#define LSDISTANCE_H
#include "mydatabase.h"

class LSdistance : public MyDatabase
{
public:
    LSdistance();
    string solve(string);
};

#endif // LSDISTANCE_H
