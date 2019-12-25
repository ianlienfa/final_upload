#ifndef LONGESTPALINDROME_H
#define LONGESTPALINDROME_H
#include "mystring.h"


class LongestPalindrome : public MyString
{
public:
    LongestPalindrome();
    string solve(string);
    inline string puncRmv(string);
    inline string longestPan(string);
};

#endif // LONGESTPALINDROME_H
