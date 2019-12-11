#ifndef TREEWALK_H
#define TREEWALK_H
#include "mytree.h"

class TreeWalk : public MyTree
{
public:
    TreeWalk();
    string solve(string s);
    int search(char arr[], char x, int n);
    void printPostOrder(char in[], char pre[], int n, string&);

};

#endif // TREEWALK_H
