#include <bits/stdc++.h>
using namespace std;
int main()
{
    int content[25][25] = {0};
    int n, i = 1, x = 1, y = 0;
    cin >> n;
    while (i <= n * n)
    {
        while (y < n && !content[x][y + 1])
            content[x][++y] = i++;
        while (x < n && !content[x + 1][y])
            content[++x][y] = i++;
        while (y > 1 && !content[x][y - 1])
            content[x][--y] = i++;
        while (x > 1 && !content[x - 1][y])
            content[--x][y] = i++;
    }
    for (int s = 1; s <= n; s++)
    {
        for (int ss = 1; ss <= n; ss++)
        {
            cout.setf(ios::right); //设置对齐方式为left
            cout.width(4);         //设置宽度为7，不足用空格填充
            cout << content[s][ss];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}