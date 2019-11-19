#ifndef FIB_H
#define FIB_H
#include "mymath.h"
#include <iomanip>

using namespace std;

class fib : public MyMath
{
public:
    fib();
    string solve(string s);
};

#endif // FIB_H
