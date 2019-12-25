#include "closest_path.h"

closest_path::closest_path()
{

}
string closest_path::solve(string s)
{
    vector<double> vec = stringtoVectordouble(s);
    vector<double> result,min_vec;

    for(int i=0;i<vec.size()/3;i++)
    {
        for(int j=i+1;j<vec.size()/3;j++)
        {
                double length = sqrt((vec[i*3]-vec[j*3])*(vec[i*3]-vec[j*3]) + (vec[i*3+1]-vec[j*3+1])*(vec[i*3+1]-vec[j*3+1]) + (vec[i*3+2]-vec[j*3+2])*(vec[i*3+2]-vec[j*3+2]));
                result.push_back(length);
                //qDebug() << vec[i*3]<< vec[i*3+1] << vec[i*3+2] << vec[j*3] << vec[j*3+1] << vec[j*3+2];
                //qDebug() << (vec[i*3]-vec[j*3])*(vec[i*3]-vec[j*3]) << (vec[i*3+1]-vec[j*3+1])*(vec[i*3+1]-vec[j*3+1]) << (vec[i*3+2]-vec[j*3+2])*(vec[i*3+2]-vec[j*3+2]);
        }
    }

    double min = 1000;
    for(int k=0;k<result.size();k++)
    {
        if(result[k] < min && result[k] > 0)
            min = result[k];
    }

    min = rounding(min);
    min_vec.push_back(min);
    string path = vectordoubleToString(min_vec);
    return path;
}
double closest_path::rounding(double s)
{
    double s_100 = s * 100;
    double s_1000 = s * 1000;
    double result;
    int s_1000_floor = floor(s_1000);
    if(s_1000_floor%10 < 5){
        double s_100_floor = floor(s_100);
        result = s_100_floor/100;
    }
    if(s_1000_floor%10 >= 5){
        double s_100_floor = floor(s_100) + 1;
        result = s_100_floor/100;
    }
    return result;

}
