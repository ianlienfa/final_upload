#ifndef LONGESTCOMMONSUBSTRING_18_H
#define LONGESTCOMMONSUBSTRING_18_H


#include "mystring.h"
#include <QDebug>

class LongestSubstring : public MyString
{
public:
    LongestSubstring();
    inline string puncRmv(string);
    inline string commonSub(string, string);
    string solve(string);
};

#endif // LONGESTCOMMONSUBSTRING_18_H
