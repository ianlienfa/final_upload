#include "longestpalindrome.h"

LongestPalindrome::LongestPalindrome()
{

}

string LongestPalindrome::solve(string s)
{
    return longestPan(puncRmv(s));
}
inline string LongestPalindrome::puncRmv(string s)
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
inline string LongestPalindrome::longestPan(string s)
{
    string rev;
    vector<string> Pans;
    for(string::reverse_iterator iterfromback = s.rbegin(); iterfromback != s.rend(); iterfromback++)
    {
        rev += *iterfromback;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(rev[i] == s[i])
            continue;
        else
        {
            string temp;
            temp += s[i];
            rev[i] = '#';
            Pans.push_back(temp);
        }
    }
    std::size_t find = 0, front = 0;
    do
    {
        find = rev.find_first_of("#", front);
        Pans.push_back(rev.substr(front,(find!= std::string::npos)?(find-front):(std::string::npos)));
        front = find + 1;
    }while(find != std::string::npos);

    string ans = Pans[0];
    for(int i = 1; i < Pans.size(); i++)
    {
        if(Pans[i].length() > ans.length() || (Pans[i].length() == ans.length() && (int)Pans[i][0] < (int)ans[0]))
            ans = Pans[i];
    }
    return ans;
}
