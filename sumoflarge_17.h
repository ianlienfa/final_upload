#ifndef SUMOFLARGE_17_H
#define SUMOFLARGE_17_H


#include "mymath.h"

class SumOfLarge : public MyMath
{
public:
    SumOfLarge();
    virtual string solve(string);
    char hexCharAdd(char , char , char&);
    string hexAdd(string s1, string s2);
    inline int hexCharToInt(char s);
    char intToHexChar(int s);
};
#endif // SUMOFLARGE_17_H
