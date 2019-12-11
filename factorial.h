#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <mymath.h>
class factorial : public MyMath
{
public:
    factorial();
    int decomposition(int);
    //void swap(int* a,int* b);
    //void swap(int* a,int* b);
    string solve(string s);
private:
    int count = 0;
    int count_sum = 0;
    int all_sum = 0;
};

#endif // FACTORIAL_H
