#include "building.h"
#include <QDebug>
#include <QString>
Building::Building()
{

}
void Building::run()
{
//    string s = judge.getData(0);
//    data.testdata1 = s;
//    string s2 = add1.solve(s);
//    data.submit1 = s2;
//    bool correct = judge.submitData(s2);
//    data.correct1 = correct;
//    data.spendtime1 = judge.getSpendTime();

    string s = judge.getData(0);
    data.testdata1 = s;
    string s2 = paperpassing.solve(s);
    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();

    //Advanced
//    s = judge.getData(1);

//    data.testdata2 = s;
//    s2 = prime.solve(s);
//    data.submit2 = s2;
//    correct = judge.submitData(s2);
//    data.correct2 = correct;
//    data.spendtime2 = judge.getSpendTime();

    //string s = judge.getData(0);
    //string k(1,s[1]);
    //string k = "HHH";
    //MyMath test;
    //vector<int> vec;
    //test.stringtoVectorInt("1 2 3 4 5 6 7 8 9 0")
    qDebug() << QString::fromStdString(s);


}
