#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, p = 0,ss=0;
    cin >> a >> b >> c;
    int result[81] = {0};
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int s = 1; s <= c; s++)
            {
                result[i + j + s]++;
            }
        }
    }
    for (int i = 3; i <= a + b + c; i++)
    {
        if (result[i] > p){
            p = result[i];
            ss=i;
        }
    }
    cout << ss << endl;
    system("pause");
    return 0;
}