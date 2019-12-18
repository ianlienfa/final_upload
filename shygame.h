#ifndef SHYGAME_H
#define SHYGAME_H
#include <iostream>
#include "mymath.h"
using namespace std;


class ShyGame : public MyMath
{
public:
    ShyGame();
    string solve(string s);
    void count(int &pos, int *people, int m, int n);

};

#endif // SHYGAME_H
