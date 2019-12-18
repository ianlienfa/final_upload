#ifndef PRIMEDISTANCE_H
#define PRIMEDISTANCE_H
#include "mymath.h"

class PrimeDistance : public MyMath
{
public:
    PrimeDistance();
    bool prime(int s);
    string solve(string s);
};

#endif // PRIMEDISTANCE_H
