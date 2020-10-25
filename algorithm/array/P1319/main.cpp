#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tmp = 0;
    bool mark = true;
    int content[201][201];
    int ss[40000];
    while (cin >> ss[tmp++])
        if (getchar() == '\n')
            break;
    tmp = 1;
    for (int i = 1; i <= ss[0]; ++i)
    {
        for (int j = 1; j <= ss[0]; ++j)
        {
            if (ss[tmp] == 0)
            {
                mark = !mark;
                tmp++;
            }
            if (mark)
                content[i][j] = 0;
            else
                content[i][j] = 1;
            ss[tmp]--;
        }
    }
    for (int i = 1; i <= ss[0]; ++i)
    {
        for (int j = 1; j <= ss[0]; ++j)
        {
            cout<<content[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}