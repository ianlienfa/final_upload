#ifndef MYTREE_H
#define MYTREE_H
#include "problemset.h"
#include <vector>
#include <iomanip>
#include <sstream>
#include <QDebug>
using namespace std;

class MyTree : public ProblemSet
{
public:
    MyTree();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    vector<double>stringtoVectordouble(string);
    //vector<char>stringtoVectorchar(string);
    //string Vectorchartostring(vector<char>);
    struct node {
        struct node *left;  //left child node
        struct node *right; //right child node
        string keyStr;
        int keyInt;
    };

};

#endif // MYTREE_H
