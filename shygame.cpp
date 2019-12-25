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

void moveToAndDelete(int &iter, int* people, int m, int n)
{

    //go to the right place
    while(people[iter] == 0)
        iter = (iter + 1)%m;

    //start at the right place
    int count = 0;
    if(people[iter] != 0)
    {
        count++;
    }
    while(count != n)
    {
        iter = (iter + 1)%m;
        if(people[iter] != 0)
        {
            count++;
        }
    }
//    qDebug() << "count:" << count;
//    qDebug() << "iter:" << iter;
    people[iter] = 0;
}

string ShyGame::solve(string s)
{
    int m;
    string ans;
    //m 為移動次數, n為總人數
    vector<int> save_ans;
    vector<int> v_i = stringtoVectorInt(s);
    m = v_i[0];

    for(int k = 1; k < v_i.size(); k++)      //每做一次不同圈(n)，從輸入的string轉成的vector中取得從第1到最後一個
    {

          int n = v_i[k];
//          if(n > m*5)
//          {
//              int mul = n/m - 2;
//              n = n - mul*m;
//          }
          //initialize the people array
          int *people = new int[m];
          for(int i = 0; i < m; i++)
              people[i] = i+1;
          //count from the first person
          int iter = 0;
          for(int i = 0; i < m-1; i++)
          {
              moveToAndDelete(iter, people, m, n);
              //---
//              QDebug deb = qDebug();
//              for(int k = 0; k < m; k++)
//                  deb << people[k];
//              deb << endl;
              //---
          }
          for(int i = 0; i < m; i++)
          {
              if(people[i] != 0)
                  save_ans.push_back(people[i]);
          }
          delete[] people;
    }














//        pos = 0;        //設定pos從頭開始
//        int n = v_i.at(k);
//        people = new int[n];        //設定人數也不同
//        for(int i = 0; i < n; i++)
//            people[i] = 1;
//        qDebug() << "n:" << n << endl;
//        for(int i = 0; i < n-1; i++)    //每繞一次，總共只要繞n-1次就會有答案
//        {
//            count(pos, people, m, v_i.at(k));       //讓一個人跑走
//            qDebug() << "people:" ;
//            string temp;
//            for(int j = 0; j < n; j++)
//                temp += (people[j] + '0');
//            qDebug() << QString::fromStdString(temp);
//            qDebug() << endl;
//        }
//        for(int i = 0; i < n; i++)
//            if(people[i] == 1)
//                save_ans.push_back(i+1);    //要加1因為不是題目從0開始
//        delete[] people;    //陣列重新產生

    //輸出答案
    ans = vectorIntToString(save_ans);
    return ans;

}
