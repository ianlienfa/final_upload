#include "primedistance_11.h"

PrimeDistance::PrimeDistance()
{

}


bool  PrimeDistance::prime(int in)
{
    if(in == 1)
        return false;
    for(int i = 2; i*i <= in; i++)
    {
        if(in%i == 0)
            return false;
    }
    return true;
}


string PrimeDistance::solve(string s)
{
   vector<int> in  = stringtoVectorInt(s);
   string ans;
   for(int i = 0; i < in.size(); i++)
   {
      int up = in[i], down = in[i];
      while(prime(up) == false)
      {
          up++;
      }
      //qDebug() << "up:" << up << endl;
      while(prime(down) == false)
      {
          down--;
      }
      //qDebug() << "down:" << down << endl;
      in[i] = (up-down);
   }
   ans = vectorIntToString(in);
   //qDebug() << QString::fromStdString(ans) << endl;
   return ans;
}
