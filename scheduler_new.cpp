#include "scheduler_new.h"
#include <QDebug>

//void Scheduler::setSchedule(People p, Data data)    //there's number of people on each floor and their destination saving inside People
//{

//    int iter = 0;
//    while(iter != p.wait_to_leave.size())   //let iterator run through all floor
//    {
//        while(p.wait_to_leave[iter] > 0)
//        {
//           nowFloor.push_back(iter+1);  //generate the schedule based on the floor level people are on
//           nowFloor.push_back(p.destination[iter]);     //generate the schedule based on the destination floor level people hope to go

//           //start from an empty elevator
//           //not intil emptying people on the first level that the elevator moves to the second, etc.
//           if(p.wait_to_leave[iter] >= 10)
//           {
//               number.push_back(10); //in
//               p.wait_to_leave[iter] -= 10;
//               number.push_back(10); //out
//           }
//           else
//           {
//               number.push_back(p.wait_to_leave[iter]); //in
//               number.push_back(p.wait_to_leave[iter]); //out
//               p.wait_to_leave[iter] = 0;
//           }
//           //number.push_back(0); //arrived at the destination, empty the elevator
//           IO.push_back(1);     //people in
//           IO.push_back(0);     //people out
//        }
//        iter++;
//    }

//    toFile(nowFloor, IO, number);   //copy the data to file

//    for(int i = 0; i < nowFloor.size()-1; i++)
//    {
//        int difference;
//        if(nowFloor[i+1] - nowFloor[i] > 0)
//            difference = nowFloor[i+1] - nowFloor[i];
//        else {
//            difference = nowFloor[i] - nowFloor[i+1];
//        }
//        //qDebug() << "data.distance[" << i << "]:" << data.distance[i] << "  nowFloor[" << i+1 << "]:" << nowFloor[i+1] << "  nowFloor[" << i << "]:" << nowFloor[i] ;
//    }
////    for(int i = 0; i < data.distance.size(); i++)
////    {
////        qDebug() << "distance accumulated:" << i << ":" << data.distance[i];
////    }

//}


void Scheduler::setSchedule(People p, Data data)
{
    //開好需要的空間
        map<int, int> inside_elevator;
        int front = 0, back = 26;
        int elevator_people;
        int ok = 0;     //一層樓空掉就+1
        int iter;

        //從底部載人
        while(ok <= 27 && front <= 26 && back >= 0)
        {
    //        cout << "front: " << front << " back: " << back << endl;
            //找到現在front指的地方，他一定指向還可以載人的最低樓層
            while(p.wait_to_leave[front] == 0)
                front++;

            //小心兩個載過頭的可能性

    //        cout << "ok: " << ok << " front: " << front << endl;
            //去
            iter = front;
            elevator_people = 0;
            while(iter <= 26 && elevator_people < 10)
            {
                //如果他要跟我走同一方向我才載他
                if((p.destination[iter] >= p.destination[front] && p.destination[iter] > iter + 1) || elevator_people == 0)
                {
                    //如果elevator_people還不到10，能加多少進來就加多少
                    //計算elevator_people所剩空間
                    int elevator_less = 10 - elevator_people;
    //                cout << "ok: " << ok << "elevator_less" <<elevator_less << endl;
                    //這個if else就是在做--盡量把電梯放滿
                    if(p.wait_to_leave[iter] >= elevator_less)
                    {
                        elevator_people += elevator_less;
                        p.wait_to_leave[iter] -= elevator_less;
                        inside_elevator.insert(make_pair(p.destination[iter], elevator_less));
                        number.push_back(elevator_less); //in
                    }
                    else if(p.wait_to_leave[iter] == 0)
                    {
                        iter++;
                        continue;
                    }
                    else
                    {
                        elevator_people += p.wait_to_leave[iter];
                        inside_elevator.insert(make_pair(p.destination[iter], p.wait_to_leave[iter])) ;
                        number.push_back(p.wait_to_leave[iter]); //進來的人數
                        p.wait_to_leave[iter] = 0;
                        ok++;     //因為這層樓空了所以ok
                    }
    //                cout << "ok: " << ok << "elevator people: " <<elevator_people << endl;

                    nowFloor.push_back(iter+1);
                    IO.push_back(1);
    //                cout << "nowFloor :" <<nowFloor.back() << " " << IO.back() << " " << number.back() << "people" << endl;
                }
                iter++;
            }
            //上面載人時應該也要紀錄電梯內的人的量跟樓層
            //載到人了




            //剛載完一波人，更新一下現在狀況
            while(p.wait_to_leave[front] == 0)
                front++;

            //放人下車
            //因為map已經由小到大排了
            for(map<int, int>::iterator iter = inside_elevator.begin(); iter != inside_elevator.end(); iter++)
            {
                number.push_back(iter->second);
                IO.push_back(0);
                nowFloor.push_back(iter->first);
    //            cout << "nowFloor :" <<nowFloor.back() << " " << IO.back() << " " << number.back() << "people" << endl;
            }
            map<int, int>::reverse_iterator iter_map = inside_elevator.rbegin();

            back = (iter_map -> first) - 1 ; // 趁還沒被刪掉之前紀錄一下
            inside_elevator.clear();




            //back應該指向來到的最遠位置
            iter = back;
            elevator_people = 0;
    //        cout << "back :" << back << "number:" << p.wait_to_leave[back] << endl;
    //        cout << "front: " << front << " back: " << back << endl;


            while(iter >= 0 && elevator_people < 10)
            {
    //            cout << "front: " << front << " back: " << back  << " iter: " << iter << endl;


                //如果他要跟我走同一方向我才載他
                if(p.destination[iter] >= p.destination[back] && p.destination[iter] < iter + 1)
                {
                    //如果elevator_people還不到10，能加多少進來就加多少
                    //計算elevator_people所剩空間
                    int elevator_less = 10 - elevator_people;
                    //這個if else就是在做--盡量把電梯放滿
                    if(p.wait_to_leave[iter] >= elevator_less)
                    {
                        elevator_people += elevator_less;
                        p.wait_to_leave[iter] -= elevator_less;
                        inside_elevator.insert(make_pair(p.destination[iter], elevator_less));
                        number.push_back(elevator_less); //in
                    }
                    else if(p.wait_to_leave[iter] == 0)
                    {
                        iter--;
                        continue;
                    }
                    else
                    {
                        elevator_people += p.wait_to_leave[iter];
                        inside_elevator.insert(make_pair(p.destination[iter], p.wait_to_leave[iter])) ;
                        number.push_back(p.wait_to_leave[iter]); //進來的人數
                        p.wait_to_leave[iter] = 0;
                        ok++;     //因為這層樓空了所以ok
                    }
                    nowFloor.push_back(iter+1);
                    IO.push_back(1);
    //                cout << "nowFloor :" <<nowFloor.back() << " " << IO.back() << " " << number.back() << "people" << endl;

                    QDebug deb = qDebug();
                    for(int i = 0; i < p.wait_to_leave.size(); i++)
                        deb << " " << i << " ";
                    for(int i = 0; i < p.wait_to_leave.size(); i++)
                    {
                        deb << p.wait_to_leave[i] << " ";
                    }

                }
                iter--;
            }


            //回程的人也載完了
            for(map<int, int>::reverse_iterator r_iter = inside_elevator.rbegin(); r_iter != inside_elevator.rend(); r_iter++)
            {
                number.push_back(r_iter->second);
                IO.push_back(0);
                nowFloor.push_back(r_iter->first);
    //            cout << "nowFloor :" <<nowFloor.back() << " " << IO.back() << " " << number.back() << "people" << endl;
            }

            inside_elevator.clear();
    //        cout << "front: " << front << " back: " << back << endl;

//            qDebug() << "ok:" << ok << endl;
//            qDebug() << "front: " << front << " back: " << back << endl;
        }

    //    cout << "ok:" << ok << endl;
    //    cout << "front: " << front << " back: " << back << endl;


        toFile(nowFloor, IO, number);   //copy the data to file
        qDebug() << "end." ;
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
    outfile.open("C:\\Users\\ianli\\Desktop\\Schedule.txt");
    outfile.clear();
    for(int i = 0; i < nowFloor.size(); i++)
    {
        outfile << nowFloor.at(i) << "," << IO.at(i) << "," <<  number.at(i) << endl;
    }
    outfile.close();
}

