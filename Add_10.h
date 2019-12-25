#ifndef ADD1_H
#define ADD1_H

#include <iostream>
using namespace std;
#include "mymath.h"

class Add1 : public MyMath
{
    public:
        Add1();
        string solve(string s);
};

#endif // ADD1_H
