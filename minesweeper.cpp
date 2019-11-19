#include "minesweeper.h"
#include <QDebug>
Minesweeper::Minesweeper()
{

}
vector<int> Minesweeper::stringtoVectorInt(string s,int &position)
{
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
string Minesweeper::solve(string s)
{
    int pos;//為了得到真正的地圖開始的位置
    vector<int> vec_input = stringtoVectorInt(s,pos);//讀進來的地圖長寬，用vec存
    int** land;     //讀進來的時候把地圖內容換成int方式表示
    const int dir_n[8]= {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dir_m[8]= {0, 1, 1, 1, 0, -1, -1, -1};
    int m = vec_input[0];
    int n = vec_input[1];
    //抓前面兩個分別是m, n
    //不確定抓得對不對，等等來檢查

    //string 轉成 int land，如果是星星就是-1，如果是空的就是0
    string land_str = s.substr(pos);  //現在裡面只存地圖用的string了
    //qDebug() << QString::fromStdString(land_str) << endl;
    land = new int*[m];
    int pos_ = 0;
    for(int i = 0; i < m; i++)
    {
        *(land+i) = new int[n];     //順便開二維陣列
        for(int j = 0; j < n; j++)
        {
            land[i][j] = ((land_str.substr(pos_, 1).compare("*")))?0:-1;    //如果看到星星就是-1，不是就是0
            pos_++;
            //qDebug() << land[i][j];
        }
        pos_++;
    }

    //int land 跑每個位置，如果是-1跳過，每個位置轉0~7，如果發現-1，該位置在ans加加，跑完之後結束
    int u, v; //探頭出去測試時的座標
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(land[i][j] == -1)
                continue;
            int count = 0;     //dir存轉的方向、count存每個格子的數字，在每次做完一輪轉動後重置
            for(int dir = 0; dir < 8; dir++)  //轉0~7
            {
                u = i + dir_m[dir];
                v = j + dir_n[dir];
                if(u < 0 || u >= m || v < 0 || v >= n)      //如果探頭出去在迷宮外面，換下一個轉
                    continue;
                else
                {
                    if(land[u][v] == -1)
                        count++;
                }
            }
            land[i][j] = count;
            qDebug() << count;
        }
    }
    //全部做完之後得到的是一個其中有-1:炸彈，0~8:炸彈旁邊 的一個int二維陣列
    string ans;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans += (land[i][j] == -1)?"*":to_string(land[i][j]);    //答案印出的方式是炸彈（-1)印星星，不是炸彈印數字
        }
        if(i<m-1)//最後一行不要加space
            ans = ans + " ";
    }
    return  ans;

}
