#include "shygame_4.h"


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

//string ShyGame::solve(string s)
//{
//    int m;
//    string ans;
//    //m 為移動次數, n為總人數
//    vector<int> save_ans;
//    vector<int> v_i = stringtoVectorInt(s);
//    m = v_i[0];

//    for(int k = 1; k < v_i.size(); k++)      //每做一次不同圈(n)，從輸入的string轉成的vector中取得從第1到最後一個
//    {

//          int n = v_i[k];
// //          if(n > m*5)
// //          {
// //              int mul = n/m - 2;
// //              n = n - mul*m;
// //          }
//          //initialize the people array
//          int *people = new int[m];
//          for(int i = 0; i < m; i++)
//              people[i] = i+1;
//          //count from the first person
//          int iter = 0;
//          for(int i = 0; i < m-1; i++)
//          {
//              moveToAndDelete(iter, people, m, n);
//              //---
// //              QDebug deb = qDebug();
// //              for(int k = 0; k < m; k++)
// //                  deb << people[k];
// //              deb << endl;
//              //---
//          }
//          for(int i = 0; i < m; i++)
//          {
//              if(people[i] != 0)
//                  save_ans.push_back(people[i]);
//          }
//          delete[] people;
//    }


class Node
{
public:
    int num;
    Node* next;
    Node(){}
    Node(int x){num = x;}
};

class Circular
{
public:
    Node* first;
    Node* end;
    Node* iter;
    Node* front;
    int cycle_accu = 0;
    int total_people;
//    ~Circular()
//    {
//        Node* iter = first;
//        Node* next;
//        while(iter != end)
//        {
//            next = iter->next;
//            delete iter;
//            iter = next;
//        }
//        delete iter;
//    }
//    Circular()
//    {
//        first = new Node();
//        first->num = 0;
//        first->next = first;
//        end = first;
//    }
//    void addNoPointBack(int x)
//    {
//        try
//        {Node* p = new Node(x);
//        end->next = p;
//        end = p;
//        }catch(...){qDebug() << "unable to declare new Node." << endl;}
//    }
//    void add(int x)
//    {
//        Node* p = new Node(x);
//        end->next = p;
//        end = p;
//        end->next = first;
//    }
//    void largeAdd(int x)
//    {
//        total_people = x;
//        //add 1~x into circular list
//        for(int i = 1; i <= x; i++)
//        {
//            addNoPointBack(i);
//        }
//        end->next = first;
//    }
//    void del(Node* before)
//    {
//        before->next = before->next->next;
//        delete before->next;
//    }
//    void reset()
//    {
//        Node* it = first->next;
//        for(int i = 1; i <= total_people; i++)
//        {
//            if(it != first)
//                it->num = i;
//            it = it->next;
//        }
//    }
//    Node* count(int x)
//    {
//        //count_accu is to track how much cycle have been counted
//        count_accu = 0;
//        int c_times;
//        front = first;
//        iter = first->next;
//        while(count_accu < total_people)
//        {
//            //c_times is to track how much people are left to be counted.
//            c_times = (x%(total_people-count_accu) == 0)?total_people-count_accu:x%(total_people-count_accu);
//            qDebug() << x << ":" << "count" << c_times <<"times";
//            while(c_times > 0)
//            {

//                if(c_times == 1 && iter->num != 0)
//                {
//                    //if this is the last time counting, don't move to the next
//                    c_times--;
//                }
//                else if(iter->num != 0)
//                {
//                    //if that place isn't 0, count, and move iter to the next Node
//                    c_times--;
//                    iter = iter->next;
//                }
//                else
//                {
//                    //if that place is 0, do not count, just move iter to the next Node
//                    iter = iter->next;
//                }

//            }
//            if(count_accu != total_people-1)
//                iter->num = 0;
//            count_accu++;
//        }
//        reset();
//        return iter;
//    }

    Circular()
    {
        first = new Node(1);
        end = first;
    }
    void largeAdd(int x)
    {
        total_people = x;
        //add 1~x into circular list
        for(int i = 2; i <= x; i++)
        {
            addNoPointBack(i);
        }
        end->next = first;
    }
    void addNoPointBack(int x)
    {
        try
        {Node* p = new Node(x);
        end->next = p;
        end = p;
        }catch(...){qDebug() << "unable to declare new Node." << endl;}
    }
    void del(Node* before)
    {
        if(before->next == first)
        {
            Node* p = before->next;
            before->next = before->next->next;
            delete p;
            first = before->next;
        }
        else if(before->next == end)
        {
            Node* p = before->next;
            before->next = before->next->next;
            delete p;
            end = before;
        }
        else
        {
            Node* p = before->next;
            before->next = before->next->next;
            delete p;
        }
    }
    Node* count(int x)
    {
        //cycle_accu is to track how much cycle have been counted, if there's total five people inside,
        //it means that you have to fail 4 people
        int c_times;
        front = end;
        iter = first;
//        while(count_accu < total_people)
//        {
//            //c_times is to track how much people are left to be counted.
//            c_times = (x%(total_people-count_accu) == 0)?total_people-count_accu:x%(total_people-count_accu);
//            qDebug() << x << ":" << "count" << c_times <<"times";
//            while(c_times > 0)
//            {

//                if(c_times == 1 && iter->num != 0)
//                {
//                    //if this is the last time counting, don't move to the next
//                    c_times--;
//                }
//                else if(iter->num != 0)
//                {
//                    //if that place isn't 0, count, and move iter to the next Node
//                    c_times--;
//                    iter = iter->next;
//                }
//                else
//                {
//                    //if that place is 0, do not count, just move iter to the next Node
//                    iter = iter->next;
//                }

//            }
//            if(count_accu != total_people-1)cycle_accu
//                iter->num = 0;
//            count_accu++;
//        }
        for(cycle_accu = 0; cycle_accu < total_people-1; cycle_accu++)
        {
            c_times = (x%(total_people-cycle_accu) == 0)?total_people-cycle_accu:x%(total_people-cycle_accu);
            while(c_times > 1)
            {
                front = iter;
                iter = iter->next;
                c_times--;
            }
            del(front);
            c_times--;  //should end at 1
            iter = front->next;
        }
        return iter;
    }
};

string ShyGame::solve(string s)
{
    qDebug() << "shygame, string:" << QString::fromStdString(s);
    vector<int> vec = stringtoVectorInt(s), ans;
    Circular circular;
    for(int i = 1; i < vec.size(); i++)
    {
        circular.largeAdd(vec[0]);
        ans.push_back(circular.count(vec[i])->num);
    }
    return vectorIntToString(ans);
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
//    ans = vectorIntToString(save_ans);
//    return ans;

//}
