#ifndef ESCAPE_H
#define ESCAPE_H
#include "myother.h"
#define MAX 1100
#include <queue>
#include <memory.h>
using namespace std;

class Escape : public MyOther
{
public:
    Escape();
    virtual string solve(string s);
    vector<int> stringtoVectorInt(string,int&);
    vector<char> stringtoVectorChar(string);
    void bfs_F();
    int bfs_J(int x, int y);

private:
    static const int N = 1000+10;
    static const int inf = 0x3f3f3f3f;
    int n, m;
    char mp[N][N];
    int F[N][N];
    int J[N][N];
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    struct node
    {
        int x, y;
    };
};

#endif // ESCAPE_H
