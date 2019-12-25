#ifndef PEOPLE_H
#define PEOPLE_H
#include <QString>
using namespace std;
#include <string>
#include <vector>
class People
{
public:
    People();
    vector<int> wait_to_leave;
    int arrive_people[27];
    vector<int> destination;
};

#endif // PEOPLE_H
