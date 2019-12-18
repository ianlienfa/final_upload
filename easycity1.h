#ifndef EASYCITY1_H
#define EASYCITY1_H
#include <mydatabase.h>
#include <QSqlDatabase>
#include <QSqlQuery>

class easycity1 : public MyDatabase
{
public:
    easycity1();
    virtual string solve(string s);
};

#endif // EASYCITY1_H
