#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include "floor.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
