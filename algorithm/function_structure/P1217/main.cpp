#include <bits/stdc++.h>
using namespace std;
bool hui(int num);
bool zhi(int num);
int main()
{
    int a, b, n = 0;
    cin >> a >> b;
    int total[100000] = {0};
    for (int i = a; i <= b; ++i)
    {
        if(i==5) total[n++]=5;
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
            continue;
        if (hui(i))
            total[n++] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        if (zhi(total[i]))
            cout << total[i] << endl;
    }
    system("pause");
    return 0;
}
bool hui(int num)
{
    unsigned i = num;
    unsigned m = 0;
    while (i > 0)
    {
        m = m * 10 + i % 10;
        i /= 10;
    }
    return m == num;
}
bool zhi(int num)
{
    bool p = true;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            p = false;
    }
    return p;
}