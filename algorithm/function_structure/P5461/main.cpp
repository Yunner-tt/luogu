#include <bits/stdc++.h>
using namespace std;
void fun(int **content, int m, int n, int x, int y);
int main()
{
    int n;
    cin >> n;
    n = pow(2, n);
    int content[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            content[i][j] = 1;
        }
    }
    fun((int **)content, n, n, 0, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << content[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
void fun(int **content, int m, int n, int x, int y)
{
    for (int i = x; i < n / 2 + x; ++i)
    {
        for (int j = y; j < n / 2 + y; ++j)
        {
            *((int *)content + i + m * j) = 0;
        }
    }
    if (n == 2)
    {
    }
    else
    {
        fun(content, m, n / 2, x + n / 2, y);
        fun(content, m, n / 2, x, y + n / 2);
        fun(content, m, n / 2, x + n / 2, y + n / 2);
    }
}
/*似乎有很简单的办法，明天再看、、杨辉三角!!!!*/