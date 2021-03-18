
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> n >> m;
    int content[n + 1][n + 1]; //第一个是行，第二个是列
    int result[n + 1][n + 1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            content[i][j] = n * (i - 1) + j;
            result[i][j] = n * (i - 1) + j;
        }
    }
    while (m--)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        if(r!=0){
            if (z==0)                                                                                                                                                                                                                                                                                              
            {
                for (int i = x - r; i <= x + r; ++i)
                {
                    for (int j = y - r; j <= y + r; ++j)
                    {
                        result[x+j-y][x+y-i] = content[i][j];
                    }
                }
            }
            else
            {
                for (int i = x - r; i <= x + r; ++i)
                {
                    for (int j = y - r; j <= y + r; ++j)
                    {
                        result[x+y-j][y+i-x] = content[i][j];
                    }
                }
            }
        }
        for (int i = x - r; i <= x + r; ++i)
        {
            for (int j = y - r; j <= y + r; ++j)
            {
                content[i][j] = result[i][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
/*这道转置是整体中含部分的转置，与全部转置的想法有所不同
对于顺时针:
转置后的y与转置前的x有关，y=xo+yo-x;
转置后的x与转置前的y有关，x=xo-yo+y;
对于逆时针:
转置后的y与转置前的x有关，y=yo-xo+x;
转置后的x与转置前的y有关，x=xo+yo-y;
需要注意注意注意!!!!!!!!!!
*/
