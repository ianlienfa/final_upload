#include "shortest_summation_9.h"

Shortest_Summation_9::Shortest_Summation_9()
{

}
string Shortest_Summation_9::solve(string s_in)
{
    vector<int> vec = stringtoVectorInt(s_in);

    ios::sync_with_stdio(false);

    int n,k,index=0;
    std::stringstream buffer;

    while(index < vec.size())
    {
        n = vec[index];
        qDebug() << n;
        vector<Node> node;
        for(int i=0;i<2*n;i++)
        {
            Node temp;
            index = index + 1;
            temp.x = vec[index];
            index = index + 1;
            temp.y = vec[index];
            node.push_back(temp);
        }
        memset(dp,0,sizeof(dp));
        for(int s=1;s<(1<<n*2);s++)
        {
            dp[s]=INT_MAX;
            int i;
            for(i=0;i<n*2;i++)
                if(s&(1<<i))
                break;
            for(int j=i+1;j<n*2;j++)
                if(s&(1<<j))
                dp[s]=min(dp[s],dist(node,i,j)+dp[s^(1<<i)^(1<<j)]);
        }
        buffer << fixed<<setprecision(2) << dp[(1<<n*2)-1] << " ";
        index = index + 1;
    }
    qDebug() << QString::fromStdString(buffer.str());
    return (buffer.str()).substr(0,(buffer.str()).length()-1);
}

