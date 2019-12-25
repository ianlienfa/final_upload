#ifndef LARGEFACTORIAL_16_H
#define LARGEFACTORIAL_16_H


#include "mymath.h"
#include <string>

class LargeFactorial : public MyMath
{
public:
    LargeFactorial();
    string solve(string s);
    vector<int> multiply(vector<int>, int);
    inline vector<int> toReverseVec(int);
};

#endif // LARGEFACTORIAL_16_H
