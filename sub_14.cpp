#include "sub_14.h"

Sub_14::Sub_14()
{

}
string Sub_14::solve(string s)
{
    qDebug()<<"sub";

    vector<int> vec = stringtoVectorInt(s);
    for(int i=0;i<vec.size();i++)
    {
        vec[i] = vec[i] - 1;
    }

    string sub = vectorIntToString(vec);
    return sub;
}
