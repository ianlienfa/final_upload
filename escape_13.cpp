#include "escape_13.h"

Escape::Escape()
{

}
vector<int> Escape::stringtoVectorInt(string s,int &position)
{
    qDebug() << "Escape, string:" << QString::fromStdString(s);
    vector<int> vec;

    string::size_type pos=0,prev=0;
    int count = 0;
    while((pos=s.find_first_of(' ',pos))!=string::npos) //txt輸入最後不能有空格!!!!!!!
    {
        vec.push_back(stoi(s.substr(prev,pos-prev)));
        prev = ++pos;
        count = count + 1;
        if(count == 2)
            break;
    }
    position = pos;

    return vec;
}
vector<char> Escape::stringtoVectorChar(string s)
{
    vector<char> vec;

    string::size_type pos=0,prev=0;
    while((pos=s.find_first_of(' ',pos))!=string::npos) //txt輸入最後不能有空格!!!!!!!
    {
        string temp = s.substr(prev,pos-prev);
        for(int i=0;i<pos-prev;i++)
            vec.push_back(temp[i]);
        prev = ++pos;
    }
    string last = s.substr(prev);
    for(int i=0;i<m;i++)
        vec.push_back(last[i]);
    return vec;
}
string Escape::solve(string s)
{
    int pos;


    int i, j, j1, j2;
    vector<int> vec_int = stringtoVectorInt(s,pos);
    n = vec_int[0];
    m = vec_int[1];
    //qDebug() << n << m;
    string land_str = s.substr(pos);
    qDebug() << QString::fromStdString(land_str);
    vector<char> vec_char = stringtoVectorChar(land_str);
    int index = 0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            mp[i][j] = vec_char[index];
            index = index + 1;
            if(mp[i][j] == 'J')
            {
                j1 = i; j2 = j;
            }
        }
    }
    bfs_F();
    int ss = bfs_J(j1, j2);
    if(ss == -1)
        //printf("IMPOSSIBLE\n");
        //qDebug() << "IMPOSSIBELE";
        return "N";
    else{
        //qDebug() << ss;
        //printf("%d\n", ss);
        string temp;
        stringstream sss(temp);
        sss << ss;
        return sss.str();
    }
    return 0;

}
void Escape::bfs_F()//预处理，求出每一个位置被烧到所需要花的时间
{
    int i, j;
       queue<node>q;
       node a, ne;
       memset(F, -1, sizeof(F));
       for(i = 0; i < n; i++){
           for(j = 0; j < m; j++){
               if(mp[i][j] == 'F'){
                   a.x = i; a.y = j;
                   q.push(a);
                   F[i][j] = 0;
               }
           }
       }
       while(!q.empty())
       {
           a = q.front();
           q.pop();
           for(i = 0; i < 4; i++){
               ne.x = a.x + d[i][0];
               ne.y = a.y + d[i][1];
               if(ne.x < 0 || ne.x >= n || ne.y < 0 || ne.y >= m || F[ne.x][ne.y] != -1 || mp[ne.x][ne.y] == '#')
                   continue;
               F[ne.x][ne.y] = F[a.x][a.y] + 1;
               q.push(ne);
           }
       }
}

int Escape::bfs_J(int x, int y)//逃跑路线，每走一个位置，不仅要看是否符合一般条件，还要用到上一步求出的时间
{
    int i, j;
        memset(J, 0, sizeof(J));
        queue<node> q;
        node a, ne;
        a.x = x; a.y = y;
        q.push(a);
        while(!q.empty())
        {
            a = q.front();
            q.pop();
            if(a.x == 0 || a.y == 0 || a.x == n-1 || a.y == m-1)
                return J[a.x][a.y] + 1;
            for(i = 0; i < 4; i++){
                //cout << 1 << endl;
                ne.x = a.x + d[i][0];
                ne.y = a.y + d[i][1];
                if(ne.x < 0 || ne.x >= n || ne.y < 0 || ne.y >= m ||(J[a.x][a.y] + 1 >= F[ne.x][ne.y] && F[ne.x][ne.y]!= -1)|| mp[ne.x][ne.y] == '#' || J[ne.x][ne.y] != 0)
                    continue;
                J[ne.x][ne.y] = J[a.x][a.y] + 1;
                //cout << "J[" << ne.x << "][" << ne.y << "] = " << J[ne.x][ne.y] <<endl;
                q.push(ne);
            }
        }
        return -1;
}
