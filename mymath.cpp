#include "mymath.h"

MyMath::MyMath()
{

}
vector<int> MyMath::stringtoVectorInt(string s)
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
vector<double> MyMath::stringtoVectordouble(string s)
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
string MyMath::vectorIntToString(vector<int> vec)
{
    string result;

    for(int i=0;i<vec.size();i++)
    {
        stringstream ss;//Be aware of the usage of stringstream. stringstream should be redefine for every element, or it will store former values.
        ss << vec[i];
        if(i==0 && vec.size() == 1)
        {
            result = ss.str();
        }
        else if(i==0 && vec.size() > 1)
        {
            result = ss.str();
            result = result + " ";
        }
        else if(i==vec.size()-1)
        {
            result = result + ss.str();

        }
        else
        {
            result = result + ss.str();
            result = result + " ";
            //qDebug() << QString::fromStdString(ss.str()) << "KK";
        }


    }

    return result;
}
string MyMath::vectordoubleToString(vector<double> vec)
{
    string result;
    for(int i=0;i<vec.size();i++)
    {
        stringstream ss;//Be aware of the usage of stringstream. stringstream should be redefine for every element, or it will store former values.
        ss << vec[i];
        if(i==0 && vec.size() == 1)
        {
            result = ss.str();
            //qDebug() << QString::fromStdString(result) << "dddd";
        }
        else if(i==0 && vec.size() > 1)
        {
            result = ss.str();
            result = result + " ";
        }
        else if(i==vec.size()-1)
        {
            result = result + ss.str();

        }
        else
        {
            result = result + ss.str();
            result = result + " ";
        }


    }
    return result;
}

vector<string> MyMath::stringToVectorString(string s)
{
    vector<string> vec;

    string::size_type pos=0,prev=0;
    while((pos=s.find_first_of(' ',pos))!=string::npos) //txt輸入最後不能有空格!!!!!!!
    {
        vec.push_back(s.substr(prev,pos-prev));
        prev = ++pos;
    }
    vec.push_back(s.substr(prev));
    return vec;
}
