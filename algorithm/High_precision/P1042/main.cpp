#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0, b = 0, p = 0;
    char *content = new char[62501];
    char tmp;
    while (tmp = getchar())
    {
        if (tmp == 'E')
            break;
        if (tmp == '\n' || tmp == ' ')
            ;
        else if (tmp == 'W' || tmp == 'L')
            content[p++] = tmp;
    }
    ++p;
    for (int i = 0; i < p; ++i)
    {
        if (content[i] == 'W')
            ++a;
        else if(content[i] == 'L')
            ++b;
        if (((a >= 11 || b >= 11) && abs(a - b) >= 2) || i == p - 1)
        {
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }
    cout<<endl;
    for (int i = 0; i < p; ++i)
    {
        if (content[i] == 'W')
            ++a;
        else if(content[i] == 'L')
            ++b;
        if (((a >= 21 || b >= 21) && abs(a - b) >= 2) || i == p - 1)
        {
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }
    system("pause");
    return 0;
}