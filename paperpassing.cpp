#include "paperpassing.h"

PaperPassing::PaperPassing()
{

}

string PaperPassing::solve(string s)
{
    //挖哈哈哈
    //third bla
    //nononono!
    vector<int> read_in_num = stringtoVectorInt(s);
    int iterator = 0;       //iterator helps point to the numbers in the vector
    int N = read_in_num[iterator];    //gets the first number of the vector, to know how large the pass array should be
    int *pass_p = new int[N+1];    //pass array saves the person the index person will pass the paper to.
                            //ex: 1-> 2, then pass[1] = 2;
    
    int index = 0; int num = 0;
    for(int i = 0; i < N; i++)
    {
        index = read_in_num[++iterator];
        num = read_in_num[++iterator];
        pass_p[index] = num;
    }

    int *times = new int[N+1];
    int count; int now;      //"count" counts the times paper was passed, "now" shows the position paper locates at
    bool *sign = new bool[N+1];
    for(int i = 1; i <= N; i++)
    {
       for(int i = 1; i <= N; i++)
           sign[i] = false;
       count = 0;
       now = i;
       do
       {
           sign[now] = true;
           count++;
           now = pass_p[now];
       }while(sign[now] != true);
       times[i] = count;
    }

    int max = times[1];
    int maxperson = 1;
    qDebug() << times[1] << times[2] << times[3];
    for(int i = 1; i <= N; i++)
    {
        if(max < times[i])
        {
            max = times[i];
            maxperson = i;
        }
    }
    vector<int> ans_i;
    ans_i.push_back(maxperson);
    string ans = vectorIntToString(ans_i);
    return ans;

}
