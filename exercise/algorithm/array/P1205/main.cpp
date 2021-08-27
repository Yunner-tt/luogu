#include <bits/stdc++.h>
using namespace std;

bool fun1(int n, char a[11][11], char b[11][11]);
bool fun2(int n, char a[11][11], char b[11][11]);
bool fun3(int n, char a[11][11], char b[11][11]);
bool fun4(int n, char a[11][11], char b[11][11]);
bool fun5(int n, char a[11][11], char b[11][11]);
bool fun6(int n, char a[11][11], char b[11][11]);
int main()
{
    char befor[11][11], after[11][11];
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> befor[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> after[i][j];
        }
    }
    if (fun1(n, befor, after))
    {
        cout << "1" << endl;
    }
    else if (fun2(n, befor, after))
    {
        cout << "2" << endl;
    }
    else if (fun3(n, befor, after))
    {
        cout << "3" << endl;
    }
    else if (fun4(n, befor, after))
    {
        cout << "4" << endl;
    }
    else if (fun5(n, befor, after))
    {
        cout << "5" << endl;
    }
    else if (fun6(n, befor, after))
    {
        cout << "6" << endl;
    }
    else
        cout << "7" << endl;
    system("pause");
    return 0;
}

bool fun1(int n, char a[11][11], char b[11][11])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != b[j][n - i + 1])
            {
                return false;
            }
        }
    }
    return true;
}
bool fun2(int n, char a[11][11], char b[11][11])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != b[n - i + 1][n - j + 1])
            {
                return false;
            }
        }
    }
    return true;
}
bool fun3(int n, char a[11][11], char b[11][11])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != b[n - j + 1][i])
            {
                return false;
            }
        }
    }
    return true;
}
bool fun4(int n, char a[11][11], char b[11][11])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != b[i][n-j+1])
            {
                return false;
            }
        }
    }
    return true;
}
bool fun5(int n, char a[11][11], char b[11][11])
{
    for (int i = 1; i <= n ; ++i)
    {
        for (int j = 1; j <= n/2; ++j)
        {
            int temp = a[i][j];
            a[i][j] = a[i][n-j+1];
            a[i][n-j+1] = temp;
        }
    }
    if (fun1(n, a, b) || fun2(n, a, b) || fun3(n, a, b))
        return true;
    return false;
}
bool fun6(int n, char a[11][11], char b[11][11])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
/*旋转180°不就是用两次90°吗，啊我人傻了*/