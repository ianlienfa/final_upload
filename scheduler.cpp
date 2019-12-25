#include "scheduler.h"
#include <QDebug>

void Scheduler::setSchedule(People p, Data data)    //there's number of people on each floor and their destination saving inside People
{
    int iter = 0;
    while(iter != p.wait_to_leave.size())   //let iterator run through all floor
    {
        while(p.wait_to_leave[iter] > 0)
        {
           nowFloor.push_back(iter+1);  //generate the schedule based on the floor level people are on
           nowFloor.push_back(p.destination[iter]);     //generate the schedule based on the destination floor level people hope to go

           //start from an empty elevator
           //not intil emptying people on the first level that the elevator moves to the second, etc.
           if(p.wait_to_leave[iter] >= 10)
           {
               number.push_back(10); //in
               p.wait_to_leave[iter] -= 10;
               number.push_back(10); //out
           }
           else
           {
               number.push_back(p.wait_to_leave[iter]); //in
               number.push_back(p.wait_to_leave[iter]); //out
               p.wait_to_leave[iter] = 0;
           }
           //number.push_back(0); //arrived at the destination, empty the elevator
           IO.push_back(1);     //people in
           IO.push_back(0);     //people out
        }
        iter++;
    }

    toFile(nowFloor, IO, number);   //copy the data to file

    for(int i = 0; i < nowFloor.size()-1; i++)
    {
        int difference;
        if(nowFloor[i+1] - nowFloor[i] > 0)
            difference = nowFloor[i+1] - nowFloor[i];
        else {
            difference = nowFloor[i] - nowFloor[i+1];
        }
        //qDebug() << "data.distance[" << i << "]:" << data.distance[i] << "  nowFloor[" << i+1 << "]:" << nowFloor[i+1] << "  nowFloor[" << i << "]:" << nowFloor[i] ;
    }
//    for(int i = 0; i < data.distance.size(); i++)
//    {
//        qDebug() << "distance accumulated:" << i << ":" << data.distance[i];
//    }

}
int Scheduler::getNowFloor(int index)
{
    if(index >= nowFloor.size())
    {
        qDebug() << "out of index.";
        terminate = 0;
    }

    int real_floor = nowFloor[index];
    return real_floor;
}

int Scheduler::getDoorIO(int index)
{
    if(index >= nowFloor.size())
    {
        qDebug() << "out of index.";
        return NULL;
    }
    return IO[index];
}

int Scheduler::getElevatorPeople(int index)
{
    if(index >= nowFloor.size())
    {
        qDebug() << "out of index.";
        return NULL;
    }
    return number[index];
}
void Scheduler::toFile(vector<int> nowFloor, vector<bool> IO, vector<int> number)
{
    ofstream outfile;
    outfile.open("C:\\Users\\USER\\Desktop\\AOOPNCTU\\Lab\\Final Project\\Lab11\\Schedule.txt");
    outfile.clear();
    for(int i = 0; i < nowFloor.size(); i++)
    {
        outfile << nowFloor.at(i) << "," << IO.at(i) << "," <<  number.at(i) << endl;
    }
    outfile.close();
}

