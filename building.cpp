#include "building.h"
#include <QDebug>
#include <QString>
Building::Building()
{
    floor[0] = new Floor(new Add1());
    floor[1] = new Floor(new Prime());
    floor[2] = new Floor(new closest_path());
    floor[3] = new Floor(new Minesweeper());
    floor[4] = new Floor(new PaperPassing());
    floor[5] = new Floor(new longest_path());
    //floor[6] = new Floor(new longest_path());
    floor[7] = new Floor(new fib());
}
void Building::run(int index)
{
    string s = judge.getData(index);
    data.testdata1 = s;
    //string s2 = add1.solve(s);
    qDebug()<<QString::fromStdString(s);
    string s2 = floor[index] -> p -> solve(s);
    //qDebug()<<index<<QString::fromStdString(s2);
    //qDebug()<<"ENDTEST";
    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();
}
