#include "scheduler.h"
#include <QDebug>
/*before you use:

please change the path under to the right place

*/
void Scheduler::setSchedule(People p, Data data)    //there's number of people on each floor and their destination saving inside People
{
    int iter = 0;
    while(iter != p.peoplenum.size())   //let iterator run through all floor
    {
        while(p.peoplenum[iter] > 0)
        {
           nowFloor.push_back(iter+1);  //generate the schedule based on the floor level people are on
           nowFloor.push_back(p.destination[iter]);     //generate the schedule based on the destination floor level people hope to go

           //start from an empty elevator
           //not intil emptying people on the first level that the elevator moves to the second, etc.
           if(p.peoplenum[iter] >= 10)
           {
               number.push_back(10);
               p.peoplenum[iter] -= 10;
           }
           else
           {
               number.push_back(p.peoplenum[iter]);
               p.peoplenum[iter] = 0;
           }
           number.push_back(0); //arrived at the destination, empty the elevator
           IO.push_back(1);     //people in
           IO.push_back(0);     //people out
        }
        iter++;
    }

    toFile(nowFloor, IO, number);   //copy the data to file
    data.elevatorpeople = number;

    data.distance.push_back(0);
    for(int i = 0; i < nowFloor.size()-1; i++)
    {
        int difference;
        if(nowFloor[i+1] - nowFloor[i] > 0)
            difference = nowFloor[i+1] - nowFloor[i];
        else {
            difference = nowFloor[i] - nowFloor[i+1];
        }
        data.distance.push_back(data.distance[i] + difference);
        //qDebug() << "data.distance[" << i << "]:" << data.distance[i] << "  nowFloor[" << i+1 << "]:" << nowFloor[i+1] << "  nowFloor[" << i << "]:" << nowFloor[i] ;
    }
//    for(int i = 0; i < data.distance.size(); i++)
//    {
//        qDebug() << "distance accumulated:" << i << ":" << data.distance[i];
//    }


}


int Scheduler::getNowFloor()
{
    int answer = nowFloor[index];
    index = index + 1;
    qDebug() <<"FLOOR"<< answer;
    return answer;
}


void Scheduler::toFile(vector<int> nowFloor, vector<bool> IO, vector<int> number)
{
    ofstream outfile;
    outfile.open("C:\\Users\\ianli\\Documents\\AOOP_final\\Schedule.txt");
    outfile.clear();
    for(int i = 0; i < nowFloor.size(); i++)
    {
        outfile << nowFloor.at(i) << "," << IO.at(i) << "," <<  number.at(i) << endl;
    }
    outfile.close();
}
