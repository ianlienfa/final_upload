#include "mydatabase.h"

MyDatabase::MyDatabase()
{

}

vector<string> MyDatabase::stringToVectorString(string s)
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

vector<QString> MyDatabase::stringToVectorQString(string s)
{
    vector<string> vec;
    vector<QString> Qvc;
    string::size_type pos=0,prev=0;
    while((pos=s.find_first_of(' ',pos))!=string::npos) //txt輸入最後不能有空格!!!!!!!
    {
        vec.push_back(s.substr(prev,pos-prev));
        prev = ++pos;
    }
    vec.push_back(s.substr(prev));
    for(int i = 0; i < vec.size(); i++)
    {
        Qvc.push_back(QString::fromStdString(vec[i]));
    }
    return Qvc;
}


string MyDatabase::vectorStringToString(vector<string> vc)
{
//    qDebug() << "vecStringToString enter";
    string result;
    for(int i = 0; i < vc.size()-1; i++)
    {

        result += vc[i];
        result += " ";
    }
    result += vc.back();
//    qDebug() << "vecStringToString out";
    return result;
}


string MyDatabase::vectorStringToStringForSQL(vector<string> vc)
{
//    qDebug() << "vecStringToString enter";
    string result;
    for(int i = 0; i < vc.size()-1; i++)
    {
        if(vc[i] == "")
        {
            result += "NULL";
        }
        else
            result += vc[i];
        result += " ";
    }
    result += vc.back();
//    qDebug() << "vecStringToString out";
    return result;
}

