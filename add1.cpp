#include "add1.h"

Add1::Add1()
{

}
string Add1::solve(string s)
{
    vector<int> vec = stringtoVectorInt(s);
    for(int i=0;i<vec.size();i++)
    {
        //qDebug() << vec[i];
        vec[i] = vec[i] + 1;
        //qDebug() << vec[i];
    }

    string add = vectorIntToString(vec);
    return add;
}
