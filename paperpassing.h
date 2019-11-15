#ifndef PAPERPASSING_H
#define PAPERPASSING_H
#include "myother.h"
#include <vector>

class PaperPassing:public MyOther
{
public:
    PaperPassing();
    string solve(string s);
    vector<int> stringtoVectorInt(string s)
    {
        vector<int> vec;
        string::size_type pos=0,prev=0;
        while((pos=s.find_first_of(' ',pos))!=string::npos)
        {
            vec.push_back(stoi(s.substr(prev,pos-prev)));
            prev = ++pos;
        }
        vec.push_back(stoi(s.substr(prev)));
        return vec;
    }
    string vectorIntToString(vector<int> ans)
    {
         string output;
         for(int i = 0; i < ans.size(); i++)
         {
             output += ((to_string(ans.at(i))));
             if(i != ans.size()-1){output += ' ';}
         }
         return output;
    }

};

#endif // PAPERPASSING_H
