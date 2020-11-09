#include <bits/stdc++.h>
using namespace std;

void su(int n);
int main()
{
    bool check = false;
    int p = 2;
    short min = 23, max = 1;
    short su[30];
    short frequency[24] = {0};
    char content[101];
    su[1] = 2;
    for (int i = 3; i <= 100; ++i)
    {
        bool mark = true;
        for (int j = 2; j < i; ++j)
        {
            if (i % j == 0)
                mark = false;
        }
        if (mark)
            su[p++] = i;
    }
    cin >> content;
    for (int i = 0; i < strlen(content); ++i)
    {
        frequency[content[i] - 'a']++;
    }
    for (int i = 0; i < 24; ++i)
    {
        if (frequency[i] < min && frequency[i] != 0)
            min = frequency[i];
        if (frequency[i] > max)
            max = frequency[i];
    }
    for (int i = 1; i < p; ++i)
    {
        if ((max - min) == su[i])
            check = true;
    }
    if (check)
    {
        cout << "Lucky Word" << endl;
        cout << max - min << endl;
    }
    else
    {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    system("pause");
    return 0;
}
void su(int n)
{
    bool p[n];
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == 0)
            for (int j = i * i; j <= n; j += i)
            {
                p[j] = 1;
            }
    }
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == 0)
            cout << i << ' ';
    }
}