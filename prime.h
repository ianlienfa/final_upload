#ifndef PRIME_H
#define PRIME_H
#include <iostream>
#include <math.h>
using namespace std;
#include "mymath.h"

class Prime : public MyMath
{
    public:
        Prime();
        string solve(string s);
};

#endif // PRIME_H
