#ifndef MYTREE_H
#define MYTREE_H
#include "problemset.h"
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

class MyTree : public ProblemSet
{
public:
    MyTree();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    vector<double>stringtoVectordouble(string);
};

#endif // MYTREE_H
