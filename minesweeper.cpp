#include "minesweeper.h"

Minesweeper::Minesweeper()
{

}

string Minesweeper::solve(string s)
{
    int** land;     //讀進來的時候把地圖內容換成int方式表示
    const int dir_n[8]= {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dir_m[8]= {0, 1, 1, 1, 0, -1, -1, -1};
    int m = stoi(s.substr(0, 1));
    int n = stoi(s.substr(1, 1));
    //抓前面兩個分別是m, n
    //不確定抓得對不對，等等來檢查

    //string 轉成 int land，如果是星星就是-1，如果是空的就是0
    string land_str = s.substr(2);  //現在裡面只存地圖用的string了
    land = new int*[m];
    int pos_ = 0;
    for(int i = 0; i < m; i++)
    {
        *(land+i) = new int[n];     //順便開二維陣列
        for(int j = 0; j < n; j++)
        {
            land[i][j] = ((land_str.substr(pos_, 1).compare("*")))?-1:0;    //如果看到星星就是-1，不是就是0
            pos_++;
        }
    }

    //int land 跑每個位置，如果是-1跳過，每個位置轉0~7，如果發現-1，該位置在ans加加，跑完之後結束
    int u, v; //探頭出去測試時的座標
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            if(land[i][j] == -1)
                continue;
            int dir = 0, count = 0;     //dir存轉的方向、count存每個格子的數字，在每次做完一輪轉動後重置
            while(dir < 8)  //轉0~7
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
        }
    //全部做完之後得到的是一個其中有-1:炸彈，0~8:炸彈旁邊 的一個int二維陣列
    string ans;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            ans += (land[i][j] == -1)?"*":to_string(land[i][j]);    //答案印出的方式是炸彈（-1)印星星，不是炸彈印數字
        }


}
