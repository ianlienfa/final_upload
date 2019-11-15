#include "mymath.h"

MyMath::MyMath()
{

}
vector<int> MyMath::stringtoVectorInt(string s)
{
    vector<int> vec;
    /*string vec_element(1,s[0]);

    for(int i=0;i<s.size();i++)
    {
        if(i==s.size()-1) //to the last one
        {
            vec.push_back(stoi(vec_element));
            break;//結束了!!!
        }
        else if(s[i+1]==' ')
        {
            vec.push_back(stoi(vec_element));
            vec.element
        }
        else
        {
            string temp_element(1,s[i+1]);
            vec_element = vec_element + temp_element;
        }
     }*/
    string::size_type pos=0,prev=0;
    while((pos=s.find_first_of(' ',pos))!=string::npos)
    {
        vec.push_back(stoi(s.substr(prev,pos-prev)));
        prev = ++pos;
    }
    vec.push_back(stoi(s.substr(prev)));
    return vec;
}
//vector<int> MyMath::stringtoVectorInt(string s)
//{
//    string::size_type pt = 0;
//    vector<string> s_tmp;
//    vector<int> ans;
//    string int_temp, output;
//    s_tmp.push_back(s);
//    int count = 0;
//    while(s_tmp.back() != "")
//    {
//        ans.push_back(stoi(s_tmp[count], &pt));            //將遇到空格前的string轉成int加入ans，將空格位置記入pt
//        s_tmp.push_back(s_tmp[count].substr(pt));          //將後方剩餘傳入另一個substr，好讓我繼續用上面的function拿int
//        count++;    //count會是是全部的int - 1
//    }
//    return ans;
//}
string MyMath::vectorIntToString(vector<int> vec)
{
    string result;

    for(int i=0;i<vec.size();i++)
    {
        stringstream ss;//Be aware of the usage of stringstream. stringstream should be redefine for every element, or it will store former values.
        ss << vec[i];
        if(i==0)
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
