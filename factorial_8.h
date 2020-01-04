#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <mymath.h>
class factorial : public MyMath
{
public:
    factorial();
    int decomposition(int);
    void swap(int* a,int* b);
    int Partition(int *arr, int *recover, int front, int end);
    void QuickSort(int *arr, int *recover, int front, int end);
    //void swap(int* a,int* b);
    string solve(string s);
private:
    int index,count,prime_factor_sum;//給定初值不要寫在.h檔!!!因為只會Initialize一次，會導致後面的出錯。
};

#endif // FACTORIAL_H
