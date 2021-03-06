#include "judge.h"
#include <QDebug>
Judge::Judge()
{

}
void Judge::string_tidy_up(string &s)
{
//    if (s.at(s.length()-1) == ' ' ||s.at(s.length()-1) == '\r' || s.at(s.length()-1) == '\n')
//        s.erase(s.length()-1, 1);
    string::size_type pos = 0;
    while(pos != string::npos)
    {
        pos = s.find_first_of("\r\n", pos);
        if(pos != string::npos)
            s.erase(pos, 1);
    }
    while (s.at(s.length()-1) == ' ')
    {
        s.erase(s.length()-1, 1);
    }

}
string Judge::getData(int question)
{
    timer.start();
    string file_name[9] = {"0.txt","1.txt","2c.txt","3c.txt","4c.txt","longest.txt","shygame.txt","myfibfib.txt", "maxroot.txt"};

    return geteveryData(file_name[question]);
}
string Judge::geteveryData(string name)
{
    srand( time(NULL) );
    string input_data;
    vector<string> input_data_all;
    int random = 0;

    string file = "/Users/fangsuli/Documents/ian_AOOP/AOOP_final_0/";
    string file_name  = file + name;
    in.open(file_name);

    while(getline(in,input_data)) //Read Every Line From txt file
    {
        input_data_all.push_back(input_data);
    }

    do//Take random line from txt file
    {
        random = rand()%input_data_all.size();
    } while (random%2!=0);

    ans = input_data_all [random+1];
    //ans = input_data_all [1];
    //qDebug() << QString::fromStdString(ans);
    string_tidy_up(ans);


    input = input_data_all [random];
    //input = input_data_all [1];

    string_tidy_up(input);//txt檔每一個line最後不能有space!!!，否則string to int會出錯
    //qDebug() << "ans:" << QString::fromStdString(input) << endl;
    in.close();
    return input;
}
bool Judge::submitData(string answer)
{
    costtime = timer.nsecsElapsed();
    if (answer == ans)
        return 1;
    else
        return 0;
}

