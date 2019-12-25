#include "longestcommonsubstring_18.h"

LongestSubstring::LongestSubstring()
{

}

string LongestSubstring::solve(string s)
{
    qDebug()<<"LongestcommonSubstring";

    string ans;
    std::size_t find = 0, front = 0;

    find = s.find_first_of(" ", front);
    string str1 = s.substr(front,(find!= std::string::npos)?(find-front):(std::string::npos));
    front = find + 1;
    find = s.find_first_of(" ", front);
    string str2 = s.substr(front,(find!= std::string::npos)?(find-front):(std::string::npos));
    str1 = puncRmv(str1);
    str2 = puncRmv(str2);
    return commonSub(str1, str2);
}

inline string LongestSubstring::puncRmv(string s)
{
    string ans;
    std::size_t find = 0, front = 0;
    do
    {
        find = s.find_first_of(",?!.", front);
        ans += s.substr(front,(find!= std::string::npos)?(find-front):(std::string::npos));
        front = find + 1;
    }while(find != std::string::npos);

    for(int i = 0; i < ans.length(); i++)
    {
        if(islower(ans[i]))
            ans[i] = toupper(ans[i]);
    }
   // qDebug() << QString::fromStdString(ans);
    return ans;
}

inline string LongestSubstring::commonSub(string s, string rev)
{
    vector<string> commonSubs;
    string ans;

    //find the
    string *str_s, *str_l;
    if(s.length() > rev.length())
    {
        str_s = &rev;
        str_l = &s;
    }
    else
    {
        str_s = &s;
        str_l = &rev;
    }


    //iterate through the shortest string
    for(string::iterator iter_s = str_s->begin(); iter_s < str_s->end(); iter_s++)
    {
        //iterate through the short string
        //if find the same char, starting the iterate after it and get the longest same part with the string str_l pointing at
        std::size_t front = 0;
        qDebug() << *iter_s;
        for(std::size_t find = str_l->find_first_of(*iter_s, front); find != std::string::npos; find = str_l->find_first_of(*iter_s, front))
        {
            std::size_t find_inside = find;
            string::iterator iter_s_inside = iter_s;
            string temp = "";
            string the_same_part;
            //temp helps compare
            //if char is the same
            while((temp += *iter_s_inside) == str_l->substr(find_inside, 1))
            {
                the_same_part += temp;
                find_inside++;
                iter_s_inside++;
                temp = "";  //reset temp
            }
            commonSubs.push_back(the_same_part);
            front = find+1;
        }


    }
    ans = commonSubs[0];
    for(int i = 1; i < commonSubs.size(); i++)
    {
        if(commonSubs[i].length() > ans.length() || (commonSubs[i].length() == ans.length() && (int)commonSubs[i][0] < (int)ans[0]))
            ans = commonSubs[i];
    }
    return ans;
}
