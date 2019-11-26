#include "mytree.h"

MyTree::MyTree()
{

}

vector<int> MyTree::stringtoVectorInt(string s)
{

    vector<int> vec;

    string::size_type pos=0,prev=0;
    while((pos=s.find_first_of(' ',pos))!=string::npos) //txt輸入最後不能有空格!!!!!!!
    {
        vec.push_back(stoi(s.substr(prev,pos-prev)));
        prev = ++pos;
    }
    vec.push_back(stoi(s.substr(prev)));
    return vec;

}

vector<double> MyTree::stringtoVectordouble(string s)
{
    vector<double> vec;

    string::size_type pos=0,prev=0;
    while((pos=s.find_first_of(' ',pos))!=string::npos)
    {
        vec.push_back(stod(s.substr(prev,pos-prev)));
        prev = ++pos;
    }
    vec.push_back(stod(s.substr(prev)));
    return vec;
}
