#ifndef CLOSEST_PATH_H
#define CLOSEST_PATH_H
#include "mymath.h"
#include <iomanip>

using namespace std;
class closest_path : public MyMath
{
public:
    closest_path();
    string solve(string s);
    double rounding(double);
};

#endif // CLOSEST_PATH_H
