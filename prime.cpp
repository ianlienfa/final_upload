#include "prime.h"

Prime::Prime()
{

}
string Prime::solve(string s) //For low calculation complexity,look-up table might be useful. 建立質數查找表。只要除以這些質數判斷即可
{
    qDebug()<<"prime";

    vector<int> vec = stringtoVectorInt(s),vec_prime;
    int break_flag;
    for(int i=0;i<vec.size();i++)//對於每一個vec[i]
    {
        break_flag=0;
        for(int j=vec[i];j>1;j--) //找到小於vec[i]的最大質數
        {
            if(j==2|j==3)
                vec_prime.push_back(j);
            else if(((j%2)!=0)&&((j%3)!=0))//j is not a multiple of 2 or 3,might be a prime
            {
                for(int k=5; k<=round(sqrt(j));k++)
                {
                    //qDebug() << k;
                    int flag=0;
                    if(j%k==0)
                        break;
                    if(k==round(sqrt(j)))
                        flag=1;
                    if(flag==1)
                    {
                        vec_prime.push_back(j);
                        break_flag=1;
                        break;
                    }
                }
                if(break_flag)
                    break;
            }
            if(break_flag)
                break;
        }
    }

    string add = vectorIntToString(vec_prime);
    return add;
}
