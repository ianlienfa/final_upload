#ifndef LS_DISTANCE_H
#define LS_DISTANCE_H
#include "mydatabase.h"

class LS_Distance : public MyDatabase
{
public:
    LS_Distance();
    string solve(string);
};

#endif // LS_DISTANCE_H
