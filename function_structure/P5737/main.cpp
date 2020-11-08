#include <bits/stdc++.h>
using namespace std;
bool fun(int year);
int main()
{
    int result[500] = {0}, p = 0, first = 0, end = 0;
    cin >> first >> end;
    for (int i = first; i <= end; ++i)
    {
        if (fun(i))
            result[++p] = i;
    }
    cout << p << endl;
    for (int i = 1; i <= p; ++i)
    {
        if (fun(result[i]))
            cout << result[i] << " ";
    }
    system("pause");
    return 0;
}
bool fun(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}