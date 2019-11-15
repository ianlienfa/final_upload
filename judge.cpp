#include "judge.h"
#include <QDebug>
Judge::Judge()
{

}
string Judge::getData(int question)
{
    timer.start();

    srand( time(NULL) );
    string input_data;
    vector<string> input_data_all_0,input_data_all_1;
    int random = 0;



    if(question == 0)
    {
        in.open("/Users/fangsuli/Documents/ian_AOOP/project_3/4c.txt"); //若相對位置，要將0.txt與1.exe擺在同個directory!!!
        while(getline(in,input_data))
        {
            input_data_all_0.push_back(input_data);
        }

        do
        {
            random = rand()%input_data_all_0.size();

        } while (random%2!=0);

        ans = input_data_all_0 [random+1]; //correct answer for this question
        in.close();//Remember to close file!!!否則不能開下一個檔案
        return input_data_all_0[random];

    }
    if(question == 1)
    {
        in.open("/Users/fangsuli/Documents/ian_AOOP/project_3/1.txt"); //txt檔每一個line最後不能有space!!!，否則string to int會出錯
        //if(!in){qDebug() << "dddd";}
        while(getline(in,input_data))
        {
            input_data_all_1.push_back(input_data);
           // qDebug() << QString::fromStdString(input_data);
        }

        do
        {
            random = rand()%input_data_all_1.size();
        } while (random%2!=0);
        //qDebug() << random;
        ans = input_data_all_1 [random+1];
        //qDebug() << input_data_all_1[random];
        //qDebug() << QString::fromStdString(input_data_all_1[random]);
        return input_data_all_1[random];

    }
}
bool Judge::submitData(string answer)
{
    costtime = timer.nsecsElapsed();
    if (answer == ans)
        return 1;
    else
        return 0;
}

