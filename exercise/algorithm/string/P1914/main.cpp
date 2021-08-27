#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char result[50];
    cin >> n;
    cin >> result;
    for (int i = 0; i < strlen(result); ++i)
    {
        int tmp = result[i] + n;
        while (tmp > 'z')
        {
            tmp-='z';
            tmp+='a';
        }
        cout << char(tmp);
    }

    system("pause");
    return 0;
}