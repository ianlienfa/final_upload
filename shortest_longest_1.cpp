#include "shortest_longest_1.h"

Shortest_Longest_1::Shortest_Longest_1()
{

}
string Shortest_Longest_1::solve(string s)
{
    vector<double> vec = stringtoVectordouble(s);
    qDebug() << "WINN";
    vector<double> result,max_vec;

    for(int i=0;i<vec.size()/3;i++)
    {
        for(int j=i+1;j<vec.size()/3;j++)
        {
                double length = sqrt((vec[i*3]-vec[j*3])*(vec[i*3]-vec[j*3]) + (vec[i*3+1]-vec[j*3+1])*(vec[i*3+1]-vec[j*3+1]) + (vec[i*3+2]-vec[j*3+2])*(vec[i*3+2]-vec[j*3+2]));
                result.push_back(length);
        }
    }
    vector<double>::iterator biggest = max_element(begin(result),end(result));
    vector<double>::iterator smallest = min_element(begin(result),end(result));

    stringstream ss;
    ss << fixed<<setprecision(2) << *smallest << " " << fixed<<setprecision(2) << *biggest;
    return ss.str();
}
