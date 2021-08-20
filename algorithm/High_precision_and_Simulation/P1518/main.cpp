#include <bits/stdc++.h>
using namespace std;
char m[12][12];
int cx, cy, fx, fy, time_ = 0;
int turn_c = 0, turn_f = 0; //åŒ?:0,ä¸?:1,å?:2,è¥?:3
bool meet = false;
void move(int &x, int& y, int& turn)
{
    switch (turn)
    {
    case 0:
        if ((x - 1) == 0 || m[x - 1][y] == '*')
        {
            turn = (turn + 1) % 4;
        }
        else
        {
            x--;
        }
        break;
    case 1:
        if ((y + 1) == 11 || m[x][y + 1] == '*')
        {
            turn = (turn + 1) % 4;
        }
        else
        {
            y++;
        }
        break;
    case 2:
        if ((x + 1) == 11 || m[x + 1][y] == '*')
        {
            turn = (turn + 1) % 4;
        }
        else
        {
            x++;
        }
        break;
    default:
        if ((y - 1) == 0 || m[x][y - 1] == '*')
        {
            turn = (turn + 1) % 4;
        }
        else
        {
            y--;
        }
        break;
    }
}
int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            cin >> m[i][j];
            if (m[i][j] == 'C')
                cx = i, cy = j;
            if (m[i][j] == 'F')
                fx = i, fy = j;
        }
    }
    while (!meet)
    {
        time_++;
        move(cx,cy,turn_c);
        move(fx,fy,turn_f);
        if(cx==fx&&cy==fy) meet=true;
        if (time_ > 160000)
        {
            cout << "0" << endl;
                system("pause");
            return 0;
        }
    }
    cout<<time_<<endl;
    system("pause");
    return 0;
}