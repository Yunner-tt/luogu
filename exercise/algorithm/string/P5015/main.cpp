#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0;
    char tmp;
    while ((tmp = getchar())!='\n')
    {
        if (tmp == 32) continue;
        else a++;
    }
    cout << a << endl;
    system("pause");
    return 0;
}