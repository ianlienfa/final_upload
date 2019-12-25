#include "maze_21.h"

Maze::Maze()
{

}


//enum dir{N, NE, E, SE, S, SW, W, NW};
//int move_x[8] = {0 , 1 , 1, 1, 0, -1, -1, -1};
//int move_y[8] = {-1, -1, 0, 1, 1,  1,  0, -1};


enum dir{E, S, W, N};
int move_x[4] = {1, 0, -1,  0};
int move_y[4] = {0, 1,  0, -1};



//Direction means the instruction telling the mouse where to go
class Maze::Direction
{
public:

     dir dd;
     int x_dir;
     int y_dir;
     //direction必須包含來的方向以及x, y座標
     Direction(int y_, int x_, dir d_)
     {
        dd = d_;
        x_dir = x_;
        y_dir = y_;
     }
     dir getdir()
     {
         return dd;
     }
//	 void input_to_maze()
//	 {
//		 x_dir += 1;
//		 y_dir += 1;
//	 }

};

class Maze::PPos
{
public:
    int x;
    int y;
    PPos()
    {

    }
    PPos(int y_, int x_)
    {
        x = x_;
        y = y_;
    }
    void setyx(int y_, int x_)
    {
        x = x_;
        y = y_;
    }
    bool operator==(PPos p)
    {
        if (x == p.x && y == p.y)
            return true;
        else
            return false;
    }
};

class Maze::Mousee
{

public:
      int** old_maze;
      int** maze;         //傳入detect用的二維陣列 //存有答案
      int** maze_print;   //call 完 wallbreak 之後可以印的答案就會在這裡了
      vector<Direction> directions;
      int ini_x, ini_y;
      int start_x, start_y, end_x, end_y;

      //constructor tends to create another 2D array called "maze" to help trace the situation
      Mousee()
      {

      }
      void setupmousee(int m, int n, int** mtrxptr, int start_x, int start_y, int end_x, int end_y)
      {
          old_maze = mtrxptr;    //save the maze read in, for me to change the start and end later
          ini_x = n; ini_y = m;  //keep track of the initial size
          maze = new int*[m+2];
          for(int i = 0; i < m+2; i++)
            *(maze+i) = new int[n+2];
          //建立新二維陣列，比原本的要大一圈，讓我比較好計算
          for(int i = 0; i < m+2; i++)
          {
              for(int j = 0; j < n+2; j++)
                maze[i][j] = WALL;
          }
          for(int i = 1; i < m+1; i++)
          {
              for(int j = 1; j < n+1; j++)
                maze[i][j] = (mtrxptr[i-1][j-1] == 0)?YES:WALL;
          }
          this->start_x = start_x;
          this->start_y = start_y;
          this->end_x = end_x;
          this->end_y = end_y;

      }
      void clearmaze()  //將幫助生成答案的比較肥的maze重置
      {
          for(int i = 0; i < ini_y+2; i++)
          {
              for(int j = 0; j < ini_x+2; j++)
                maze[i][j] = WALL;
          }
          for(int i = 1; i < ini_y+1; i++)
          {
              for(int j = 1; j < ini_x+1; j++)
                maze[i][j] = (old_maze[i-1][j-1] == 0)?YES:WALL;
          }
      }
      bool isfine(int y, int x, dir d)   //這個function傳入想走的方向跟現在座標，幫我判定能不能走
      {
              if(maze[y+ymov(d)][x+xmov(d)] == 0)
                return true;
              else
                return false;
      }

    vector<Direction> go()
    {

        //在此處重設
        PPos now(3, 1), end(7, 9);
        int startx = start_x;
        int starty = start_y;
        int endx = end_x;
        int endy = end_y;
        if(maze[starty+1][startx+1] == 2 || maze[endy+1][endx+1] == 2)
        {
           qDebug() << "Cannot start or end at places with wall built on.";
        }
        else
        {now.setyx(starty+1, startx+1); end.setyx(endy+1, endx+1);}
        //PPos now(3, 1), end(7, 9);
        //分別為出入口座標，以多加了外面一圈的maze座標呈現
        do
        {
            for (int i = 0; i < 4; i++)
            {

                if (isfine(now.y, now.x, (dir)i))
                {
                    maze[now.y][now.x] = ANS;
                    //放現在的位置要去的方向進入stack
                    Direction this_move(now.y, now.x, (dir)i);
                    directions.push_back(this_move);
                    //更新現在位置
                    now.x += xmov((dir)i);
                    now.y += ymov((dir)i);
//					ShowMessage(now.x);
//					ShowMessage(now.y);
                    i = -1;
                    if (now == end)
                    {
                        maze[now.y][now.x] = ANS;
                        return directions;
                    }
                }
            }

            //如果四面八方都沒路
            //把這個位置打叉叉
            maze[now.y][now.x] = NO;
            //回到前一個位置
            now.x = directions.back().x_dir;
            now.y = directions.back().y_dir;
            //把stack pop掉
            directions.pop_back();
//            ShowMessage(now.x);
//			ShowMessage(now.y);
            //在最後如果迷宮無解應該會看到x或y的值在0(外牆裡面)

        } while (!directions.empty());
        return directions;
        //會看到空的vector

    }

    int  xmov(dir d)
    {
     return move_x[d];
    }
    int  ymov(dir d)
    {
     return move_y[d];
    }

    void wallbreak()
    {
        maze_print = new int* [ini_y];
        for(int i = 0; i < ini_y; i++)
           *(maze_print+i) = new int[ini_x];

       for(int i = 0; i < ini_y; i++)
       {
           for(int j = 0; j < ini_x; j++)
           {
               maze_print[i][j] = maze[i+1][j+1];
           }
       }
    }
};


string Maze::solve(string s)
{
    qDebug()<<"maze";

    int m, n;
    int **mtrxptr;
    int startx, starty, endx, endy;
    string s2;

    //first get the substring of two part, s_front, s_back
    string s_front, s_back;
    std::size_t front = 0, mid, temp;
    mid = s.find_first_of(' ');
    mid = s.find_first_of(' ', mid+1);
    s_front = s.substr(0, mid);
    s_back = s.substr(mid+1);
//    qDebug() << QString::fromStdString(s_front);
//    qDebug() << QString::fromStdString(s_back);
    vector<int> m_n = stringtoVectorInt(s_front);
    n = m_n.at(0);
    m = m_n.at(1);

    mtrxptr = new int* [m];
            for(int i = 0; i < m; i++)
               *(mtrxptr+i) = new int[n];
    for(int i = 0; i < s_back.length(); i++)
    {
        if(s_back[i] != ' ')
            s2 += s_back[i];
    }

    //qDebug() << "s2:" << QString::fromStdString(s2);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(s2[n*i+j] == 'S')
            {
                startx = j;
                starty = i;
                mtrxptr[i][j] = 0;
            }
            else if(s2[n*i+j] == 'E')
            {
                endx = j;
                endy = i;
                mtrxptr[i][j] = 0;
            }
            else
                mtrxptr[i][j] = s2[n*i+j] - '0';
        }
    }

//    qDebug() << "---------------mtrxptr-----------------";
//    for (int i=0; i<m; i++)
//    {
//        QDebug deb = qDebug();
//            for (int j=0; j<n; j++)
//                    deb << mtrxptr[i][j];
//            deb << endl;
//    }


    Mousee mousee;
    string print;
    mousee.setupmousee(m, n, mtrxptr, startx, starty, endx, endy);

//    qDebug() << "----------maze-----------";
//    for (int i=0; i<m; i++)
//    {
//        QDebug deb = qDebug();
//            for (int j=0; j<n; j++)
//                    deb << mousee.maze[i][j];
//            deb << endl;
//    }
//     qDebug() << "----------maze-----------";
    mousee.go();
    mousee.wallbreak(); //將答案存入maze_print

//    qDebug() << "----------maze_print-----------";

//    for (int i=0; i<m; i++)
//    {
//        QDebug deb = qDebug();
//            for (int j=0; j<n; j++)
//                    deb << mousee.maze_print[i][j];
//            deb << endl;
//    }

//    qDebug() << "----------maze_print-----------";

    string ans;

    for(int i = 0; i < m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(startx == j && starty == i)
            {
                ans += 'S';
            }
            else if(endx == j && endy == i)
            {
                ans += 'E';
            }
            else if(mousee.maze_print[i][j] == 3)
            {
                ans += 1 + '0';
            }
            else if(mousee.maze_print[i][j] == 1)
            {
                ans += 0 + '0';
            }
            else {
                ans += mousee.maze_print[i][j] + '0';
            }
            if(!(i == m-1 && j == n-1))
                ans += ' ';
        }
    }
//    //---------------------------deBug
//    string s_ans;
//    string sss = "2 2 2 2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 2 2 2 0 0 0 0 2 2 0 0 2 2 0 0 0 0 0 0 0 0 2 2 0 0 0 0 0 0 0 0 2 2 2 0 0 0 0 0 0 0 2 2 0 2 0 0 0 0 0 2 2 2 0 0 2 0 2 0 0 0 2 2 0 0 0 0 2 0 2 0 2 2 0 0 0 2 0 0 2 0 2 2 0 0 0 2 0 0 0 2 2 2 0 0 0 0 0 0 2 0 2 2 0 0 2 0 1 E 2 0 2 2 0 1 1 1 1 2 0 0 2 2 1 1 1 1 1 1 1 1 2 2 1 1 1 2 0 2 1 1 2 2 1 1 1 1 1 1 1 2 2 2 1 1 1 1 2 0 0 0 2 2 1 1 1 1 0 1 1 1 2 2 1 1 1 1 1 1 2 S 2 2 2 2 2 2 2 2 2 2 2";
//    for(int i = 0; i < sss.length(); i++)
//    {
//        if(sss[i] != ' ')
//            s_ans += sss[i];
//    }
//    int** matrix_ans;
//    matrix_ans = new int* [m];
//            for(int i = 0; i < m; i++)
//               *(matrix_ans+i) = new int[n];

//    for(int i = 0; i < m; i++)
//    {
//        for(int j = 0; j < n; j++)
//        {
//            if(s_ans[n*i+j] == 'S')
//            {
//                startx = j;
//                starty = i;
//                matrix_ans[i][j] = 0;
//            }
//            else if(s_ans[n*i+j] == 'E')
//            {
//                endx = j;
//                endy = i;
//                matrix_ans[i][j] = 0;
//            }
//            else
//                matrix_ans[i][j] = s_ans[n*i+j] - '0';
//        }
//    }
//    qDebug() << "----------ans-----------";
//    for (int i=0; i<m; i++)
//    {
//        QDebug debb = qDebug();
//            for (int j=0; j<n; j++)
//                    debb << matrix_ans[i][j];
//            debb << endl;
//    }
//     qDebug() << "----------ans-----------";

    qDebug() << QString::fromStdString(ans);
    return ans;
}

