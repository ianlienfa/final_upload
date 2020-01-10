#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include "floor.h"
#include "easycity2_25.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    EasyCity2 easy;
//    string s= easy.solve("72 lar hiIUqnR klyGtLpFM -45.4067 16.8709 -33.303 182.566 8");
    return a.exec();
}
