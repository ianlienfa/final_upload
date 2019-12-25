#ifndef LONGESTSUBSTRING_H
#define LONGESTSUBSTRING_H
#include "mystring.h"

class LongestSubstring : public MyString
{
public:
    LongestSubstring();
    inline string puncRmv(string);
    inline string commonSub(string, string);
    string solve(string);
};

#endif // LONGESTSUBSTRING_H
