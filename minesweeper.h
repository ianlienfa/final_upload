#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <myother.h>

class Minesweeper : public MyOther
{
public:
    Minesweeper();
    string solve(string s);
    vector<int>stringtoVectorInt(string,int&);
};

#endif // MINESWEEPER_H
