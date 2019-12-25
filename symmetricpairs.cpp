#include "symmetricpairs.h"

SymmetricPairs::SymmetricPairs()
{

}

string SymmetricPairs::solve(string s)
{
    string ans;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    //database.setDatabaseName("Course6");
    database.setUserName("root");
    database.setPassword("12345678");
    database.setPort(3306);
    bool ok = database.open();
    if(ok){
        qDebug() << "Succeessful Connection.";

    }
    else{
        qDebug() << "Error88787: Cannot connect!!!";
    }

    vector<string> s_in = stringToVectorString(s);
    vector<string> s_out;

    return ans;
}
