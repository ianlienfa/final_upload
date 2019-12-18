#include "shygame.h"

ShyGame::ShyGame()
{

}

void ShyGame::count(int &pos, int *people, int m, int n)
{
    while(m != 0)
    {
        pos = (pos+1) % n;
        if(people[pos-1] != 0)
        {
            m--;
        }
    }
    people[pos-1] = 0;
}

string ShyGame::solve(string s)
{
    int m;
    int pos;
    int *people;
    string ans;
    //m 為移動次數, n為總人數
    vector<int> save_ans;
    vector<int> v_i = stringtoVectorInt(s);
    m = v_i[0];
    for(int k = 1; k < v_i.size(); k++)      //每做一次不同圈(n)，從輸入的string轉成的vector中取得從第1到最後一個
    {
        pos = 0;        //設定pos從頭開始
        int n = v_i.at(k);
        people = new int[n];        //設定人數也不同
        for(int i = 0; i < n; i++)
            people[i] = 1;
        qDebug() << n << endl;
        for(int i = 0; i < n-1; i++)    //每繞一次，總共只要繞n-1次就會有答案
        {
            count(pos, people, m, v_i.at(k));       //讓一個人跑走
            for(int j = 0; j < n; j++)
                qDebug() << people[j];
            qDebug() << endl;
        }
        for(int i = 0; i < n; i++)
            if(people[i] == 1)
                save_ans.push_back(i+1);    //要加1因為不是題目從0開始
        delete[] people;    //陣列重新產生
    }
    //輸出答案
    ans = vectorIntToString(save_ans);
    return ans;

}
