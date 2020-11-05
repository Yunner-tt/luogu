#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum[26] = {0};
    char tmp;
    for (int i = 0; i < 4; ++i)
    {
        while ((tmp = getchar()) != EOF)
        {
            if (tmp > 64 && tmp < 91)
                sum[tmp - 'A']++;
        }
    }
    for (int i = *max_element(sum, sum + 26); i > 0; --i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (sum[j] >= i)
                cout << "*";
            else
                cout << " ";
            if (j != 25)
                cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 26; ++i)
    {
        cout << char(i + 65);
        if (i != 25)
            cout << " ";
    }
    system("pause");
    return 0;
}