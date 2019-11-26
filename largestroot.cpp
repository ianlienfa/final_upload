#include "largestroot.h"

LargestRoot::LargestRoot()
{

}

string LargestRoot::solve(string s)
{
    vector<double> v = stringtoVectordouble(s);   //0~14
    double subtree[15];
    for(int i = 0; i <= 14; i++)
        subtree[i] = v[i];
    subtree[3] = (subtree[7] + subtree[8])/2 + v[3];
    subtree[4] = (subtree[9] + subtree[10])/2 + v[4];
    subtree[5] = (subtree[11] + subtree[12])/2 + v[5];
    subtree[6] = (subtree[13] + subtree[14])/2 + v[6];
    subtree[1] = (subtree[3] + subtree[4])/2 + v[1];
    subtree[2] = (subtree[5] + subtree[6])/2 + v[2];
    subtree[0] = (subtree[1] + subtree[2])/2 + v[0];
    double max = subtree[0];
    int subtree_max = 0;
    for(int i = 0; i <= 14; i++)
        if(max < subtree[i])
        {
            max = subtree[i];
            subtree_max = i;
        }
    ostringstream streamobj;
    streamobj << fixed;
    streamobj << setprecision(3);
    streamobj << subtree[subtree_max];
    string ans = "";
    ans += to_string(subtree_max+1);
    ans += ":";
    ans += streamobj.str();
    return ans;
}

//string MyTree::solve(string s)
//{
//    vector<int> v = stringtoVectorInt(s);   //0~14
//    double subtree[15];
//    for(int i = 0; i <= 14; i++)
//        subtree[i] = v[i];
//    subtree[3] = (subtree[7] + subtree[8])/2 + v[3];
//    subtree[4] = (subtree[9] + subtree[10])/2 + v[4];
//    subtree[5] = (subtree[11] + subtree[12])/2 + v[5];
//    subtree[6] = (subtree[13] + subtree[14])/2 + v[6];
//    subtree[1] = (subtree[3] + subtree[4])/2 + v[1];
//    subtree[2] = (subtree[5] + subtree[6])/2 + v[2];
//    subtree[0] = (subtree[1] + subtree[2])/2 + v[0];
//    double max = subtree[0];
//    int subtree_max = 0;
//    for(int i = 0; i <= 14; i++)
//        if(max < subtree[i])
//        {
//            max = subtree[i];
//            subtree_max = i;
//        }
//    ostringstream streamobj;
//    streamobj << fixed;
//    streamobj << setprecision(3);
//    streamobj << subtree[subtree_max];
//    string ans = "";
//    ans += to_string(subtree_max+1);
//    ans += ":";
//    ans += streamobj.str();
//    return ans;
//}
