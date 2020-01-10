#include "findperiodstring_15.h"

FindPeriodString::FindPeriodString()
{

}

string FindPeriodString::solve(string s)
{
    qDebug() << "findperiodstring, string:" << QString::fromStdString(s);

    string temp, ans, ans_f;
    int l = 1;
    while(true)
    {
        for(int i = 0; i < l; i++)
            ans += s[i];
        temp = ans;
        while(temp.length() < s.length())
            temp += temp;
        if(temp.compare(s) == 0)
        {
            ans_f = to_string(ans.length());
            return ans_f;
        }

        temp = "";
        ans = "";
        l++;
    }

}

