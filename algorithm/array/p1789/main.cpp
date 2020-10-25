#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k, fire_x, fire_y, fluorite_x, fluorite_y, result = 0;
    int map[101][101] = {0};
    cin >> n >> m >> k;
    while (m != 0)
    {
        cin >> fire_x >> fire_y;
        map[fire_x][fire_y] = 1;
        map[fire_x - 1][fire_y] = 1;
        map[fire_x - 2][fire_y] = 1;
        map[fire_x + 1][fire_y] = 1;
        map[fire_x + 2][fire_y] = 1;
        map[fire_x][fire_y - 1] = 1;
        map[fire_x][fire_y - 2] = 1;
        map[fire_x][fire_y + 1] = 1;
        map[fire_x][fire_y + 2] = 1;
        map[fire_x - 1][fire_y - 1] = 1;
        map[fire_x + 1][fire_y - 1] = 1;
        map[fire_x - 1][fire_y + 1] = 1;
        map[fire_x + 1][fire_y + 1] = 1;
        --m;
    }
    while (k != 0)
    {
        cin >> fluorite_x >> fluorite_y;
        for (int i = fluorite_x - 2; i <= fluorite_x + 2; ++i)
        {
            for (int j = fluorite_y - 2; j <= fluorite_y + 2; ++j)
            {
                map[i][j] = 1;
            }
        }
        --k;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (map[i][j] == 0)
                ++result;
        }
    }
    cout << result << endl;
    system("pause");
    return 0;
}
/*看了看题解基本也都是这样的暴力解题，有些会灵活一点，因为火把是2*2矩阵全亮，萤石是3*3矩阵全亮，这两个类似可以一起通过循环先都置为已亮，然后判断火把剩下一圈外四个的就行了*/