#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "myother.h"
#include <string>
class Minesweeper : public MyOther
{
public:
    Minesweeper();
    string solve(string s);
};

#endif // MINESWEEPER_H
