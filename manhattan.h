#ifndef MANHATTAN_H
#define MANHATTAN_H
#include "mydatabase.h"

class Manhattan : public MyDatabase
{
public:
    Manhattan();
    string solve(string);
};

#endif // MANHATTAN_H
