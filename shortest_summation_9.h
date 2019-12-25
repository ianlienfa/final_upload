#ifndef SHORTEST_SUMMATION_9_H
#define SHORTEST_SUMMATION_9_H
#include "mymath.h"
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Shortest_Summation_9 : public MyMath
{
public:
    Shortest_Summation_9();
    string solve(string s);
private:
    double dp[65536];
    struct Node
    {
        double x,y;
    };

    double dist(vector<Node> node,int a,int b)
    {
        double x=node[a].x-node[b].x;
        double y=node[a].y-node[b].y;
        return sqrt(x*x+y*y);
    }

};

#endif // SHORTEST_SUMMATION_9_H
