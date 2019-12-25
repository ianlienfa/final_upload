#include "largefactorial_16.h"

LargeFactorial::LargeFactorial()
{

}

string LargeFactorial::solve(string s)
{
    int in = stoi(s);
    vector<int> tempvc;
    tempvc = toReverseVec(in);
    qDebug() << "Reverse...";
    qDebug() << tempvc;
    for(int i = in; i > 2; i--)
    {
        tempvc = multiply(tempvc, i-1);
    }
    qDebug() << "result vector...";
    qDebug() << tempvc;
    string result;
    //copy tempvc into result in the reverse way
    for(vector<int>::reverse_iterator it = tempvc.rbegin(); it != tempvc.rend(); it++)
    {
        result += to_string(*it);
    }
    return result;

}

vector<int> LargeFactorial::multiply(vector<int> vc, int multnum)
{
    //input a reverse vector, ex: If the number is 9876, send in the vector {6, 7, 8, 9}
    //vc is long, i is short
    int carry = 0;
    vector<int> result;
    for(int i = 0; i < vc.size(); i++)
    {
        int temp = vc[i]*multnum;
        //cout << "temp:" << temp << endl;
        result.push_back((temp+carry)%10);
        //cout << "result[" << i << "]:" << result[i] << endl;
        carry = (temp+carry)/10;
    }
    //cout << "carry:" << carry << endl;
    while(carry)
    {
        //cout << "here in carry fix." << endl;
        result.push_back(carry%10);
        carry /= 10;
    }
    return result;
}

inline vector<int> LargeFactorial::toReverseVec(int in)
{
    vector<int> ans;
    while(in)
    {
        ans.push_back(in%10);
        in /= 10;
    }
    if(in == 0)
        ans.push_back(0);
    return ans;
}
