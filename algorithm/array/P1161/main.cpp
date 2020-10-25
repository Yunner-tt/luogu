#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::cout.setf(ios::fixed);
    static bool lamp[2000001]={0};
    int n,t, result = 0;
    double a;
    cout.setf(ios::fixed);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> t;
        for (double j = 1; j <= t; j++)
        {
            cout<<a<<"*"<<j<<"="<<a*j<<endl;
            int temp = a*j;
            if (lamp[temp])
                lamp[temp] = 0;
            else
                lamp[temp] = 1;
        }
    }
    for (int i = 1; i < 2000001; ++i)
    {
        if (lamp[i])
            result = i;
    }
}