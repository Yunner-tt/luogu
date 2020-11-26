#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    int content[n + 1][n + 1]; //第一个是行，第二个是列
    int result[n + 1][n + 1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            content[i][j] = n * (i - 1) + j;
            result[i][j] = n * (i - 1) + j;
        }
    }
    while (m--)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        if (z==0)                                                                                                                                                                                                                                                                                              
        {
            for (int i = x - r; i <= x + r; ++i)
            {
                for (int j = y - r; j <= y + r; ++j)
                {
                    result[j-y+x][x+y-i] = content[i][j];
                }
            }
        }
        else
        {
            for (int i = x - r; i <= x + r; ++i)
            {
                for (int j = y - r; j <= y + r; ++j)
                {
                    result[x+y-j][i-y+x] = content[i][j];
                }
            }
        }
        for (int i = x - r; i <= x + r; ++i)
        {
            for (int j = y - r; j <= y + r; ++j)
            {
                content[i][j] = result[i][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
