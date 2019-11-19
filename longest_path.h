#ifndef LONGEST_PATH_H
#define LONGEST_PATH_H
#include "mymath.h"
#include <iomanip>

using namespace std;
class longest_path : public MyMath
{
public:
    longest_path();
    string solve(string s);
    double rounding(double);
};

#endif // LONGEST_PATH_H
