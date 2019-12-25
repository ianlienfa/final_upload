#include "sumoflarge_17.h"

SumOfLarge::SumOfLarge()
{

}

string SumOfLarge::solve(string s)
{
    string ans = "0";
    vector<string> svc = stringToVectorString(s);
    for(int i = 0; i < svc.size(); i++)
    {
        ans = hexAdd(ans, svc[i]);
        //qDebug() << QString::fromStdString(ans);
    }
    return ans;
}

string SumOfLarge::hexAdd(string s1, string s2)
{
    string add1, add2;
    //make sure add1 is always the longer one
    if(s1.length() > s2.length())
    {
        add1 = s1;
        add2 = s2;
    }
    else
    {
        add1 = s2;
        add2 = s1;
    }
    char carry = '0';
    string ans;
    string::reverse_iterator iter1 = add1.rbegin();
    string::reverse_iterator iter2 = add2.rbegin();
    ans.resize(add1.length()+1);
    string::reverse_iterator iter_ans = ans.rbegin();
    for(; iter1 != add1.rend(); iter1++)
    {
        if(iter2 >= add2.rend())
        {
            *iter_ans = (hexCharAdd(*iter1, '0', carry));
        }
        else
            *iter_ans = (hexCharAdd(*iter1, *iter2, carry));
        iter2++;
        iter_ans++;
    }
    if(carry != '0')
    {
        *iter_ans = (hexCharAdd('0', '0', carry));
        iter_ans++;
    }

    if(iter_ans < ans.rend())
    {
        for(int i = 0; i < ans.length()-1; i++)
        {
            ans[i] = ans[i+1];
        }
        ans.resize(add1.length());
    }
    return ans;
}

char SumOfLarge::hexCharAdd(char s1, char s2, char &carry)
{
    int i1 = hexCharToInt(s1);
    int i2 = hexCharToInt(s2);
    int carry_temp = hexCharToInt(carry);
    int after_add_digit = (i1+i2+carry_temp)%16;
    int carry_i = (i1+i2+carry_temp)/16;
    carry = carry_i + '0';
    return intToHexChar(after_add_digit);
}

int SumOfLarge::hexCharToInt(char s)
{
    if(s == '0')
        return 0;
    else if(s == '1')
        return 1;
    else if(s == '2')
        return 2;
    else if(s == '3')
        return 3;
    else if(s == '4')
        return 4;
    else if(s == '5')
        return 5;
    else if(s == '6')
        return 6;
    else if(s == '7')
        return 7;
    else if(s == '8')
        return 8;
    else if(s == '9')
        return 9;
    else if(s == 'a')
        return 10;
    else if(s == 'b')
        return 11;
    else if(s == 'c')
        return 12;
    else if(s == 'd')
        return 13;
    else if(s == 'e')
        return 14;
    else if(s == 'f')
        return 15;
    else {
        qDebug() << "error hexStringToInt.";
        return NULL;
    }
}

char SumOfLarge::intToHexChar(int s)
{
    if(s == 0)
        return '0';
    else if(s == 1)
        return '1';
    else if(s == 2)
        return '2';
    else if(s == 3)
        return '3';
    else if(s == 4)
        return '4';
    else if(s == 5)
        return '5';
    else if(s == 6)
        return '6';
    else if(s == 7)
        return '7';
    else if(s == 8)
        return '8';
    else if(s == 9)
        return '9';
    else if(s == 10)
        return 'a';
    else if(s == 11)
        return 'b';
    else if(s == 12)
        return 'c';
    else if(s == 13)
        return 'd';
    else if(s == 14)
        return 'e';
    else if(s == 15)
        return 'f';
    else {
        qDebug() << "error intToHexChar.";
        return '0';
    }
}

