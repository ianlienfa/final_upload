#include "mariocoin.h"

MarioCoin::MarioCoin()
{

}

string MarioCoin::solve(string s)
{
    //string ss = "6 1 2 4 8 16 32 6 1 3 6 8 15 20";
    vector<int> in = stringtoVectorInt(s);
    string ans;
    int iterator = 0;
    vector<int> for_ans;
//    qDebug() << "iterator:" << iterator;

    while(iterator < in.size())
    {
        vector<int> coins;
        int num_count = in[iterator];
        for(int i = iterator+1; i <= iterator+num_count; i++)
            coins.push_back(in[i]);
        iterator += num_count;
        iterator++;

        //---------------------------------------

         //"times" counts times, and "coins" saves the value of the coins
         vector<int> times;
         long long last = in.back();
         for(int i = 0; i <= last*2; i++)
         {
             long long temp = i;
             int count = 0;
             for(int k = coins.size()-1; k >= 0; k--)
             {
                 if(temp / coins[k] != 0)
                 {
                     temp %= coins[k];
                     count++;
                 }
                 if(temp == 0)
                     break;
             }
             times.push_back(count);
         }
         int max = 0;
         for(int i = 0; i < times.size(); i++)
         {
             if(times[i] > max)
                 max = times[i];
         }
         for_ans.push_back(max);
         //qDebug() << "safe." << " iterator = " << iterator;

    }



//        int exchange_count = 1;
//        int minus = coins.back()-1;
//        qDebug() << "minus is" << minus;

//        //test
//        qDebug() << "iterator:" << iterator;
//        qDebug() << "in[iterator]:" << in[iterator];
//        qDebug() << "coins:";
//        for(int i = 0; i < coins.size(); i++)
//            qDebug() << coins[i];
//        qDebug() << endl;
//        qDebug() << endl << endl;

//        for(int i = coins.size()-2; i >= 0; i--)
//        {
//            if(minus > 0 && minus-coins[i] >= 0)
//            {
//                minus -= coins[i];
//                exchange_count++;
//                qDebug() << "minus less" << minus;
//            }
//        }
//        qDebug() << "exchange_count:" << exchange_count;
//        for_ans.push_back(exchange_count);
//        iterator += in[iterator]+1;
//    }
    ans = vectorIntToString(for_ans);
    return ans;
}
