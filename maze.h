#ifndef MAZE_H
#define MAZE_H
#define YES 0
#define NO 1
#define WALL 2
#define ANS 3
#include "myother.h"

class Maze : public MyOther
{
public:
    Maze();
    string solve(string s);
    class Direction;
    class PPos;
    class Mousee;


};

#endif // MAZE_H
