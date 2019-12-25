#ifndef GETSOLUTION_19_H
#define GETSOLUTION_19_H


#include "mymath.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
class Gaussian : public MyMath
{
public:
    Gaussian();
    // function to reduce matrix to r.e.f.  Returns a value to
    // indicate whether matrix is singular or not
    int forwardElim(double** mat,int N);
    // function to calculate the values of the unknowns
    string backSub(double** mat,int N);
    // function to get matrix content
    string gaussianElimination(double**,int N);
    // function for elementary operation of swapping two rows
    void swap_row(double**, int i, int j,int N);
    // function to print matrix content at any stage
    void print(double** );
    string solve(string s);
private:
    int N;
};
#endif // GETSOLUTION_19_H
