#ifndef LONGESTPEEKPALINDROME_20_H
#define LONGESTPEEKPALINDROME_20_H

#include "mystring.h"


class LongestPalindrome : public MyString
{
public:
    LongestPalindrome();
    string solve(string);
    inline string puncRmv(string);
    inline string longestPan(string);
};

#endif // LONGESTPEEKPALINDROME_20_H
