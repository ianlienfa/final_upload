#include "fib.h"

fib::fib()
{

}
string fib::solve(string s)
{
    vector<int> vec = stringtoVectorInt(s);
    vector<int> result;
    int fib_series_10[60] = {0,1,1,2,3,5,8,3,1,4,5,9,4,3,7,0,7,7,4,1,5,6,1,7,8,5,3,8,1,9,0,9,9,8,7,5,2,7,9,6,5,1,6,7,3,0,3,3,6,9,5,4,9,3,2,5,7,2,9,1};
    int fib_series_60[120] = {0,1,1,2,3,5,8,13,21,34,55,29,24,53,17,10,27,37,4,41,45,26,11,37,48,25,13,38,51,29,20,49,9,58,7,5,12,17,29,46,15,1,16,17,33,50,23,13,36,49,25,14,39,53,32,25,57,22,19,41,0,41,41,22,3,25,28,53,21,14,35,49,24,13,37,50,27,17,44,1,45,46,31,17,48,5,53,58,51,49,40,29,9,38,47,25,12,37,49,26,15,41,56,37,33,10,43,53,36,29,5,34,39,13,52,5,57,2,59,1};
    //int fib_series_temp[3] = {0,1,1};

    for(int i=0;i<vec.size();i++) //int 一個一個讀進來
    {
        int vec_120 = vec[i]%120;
        int vec_60 = fib_series_60[vec_120];
        int vec_10 = fib_series_10[vec_60];
        result.push_back(vec_10);
    }

    return vectorIntToString(result);
}
