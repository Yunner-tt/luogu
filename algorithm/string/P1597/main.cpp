#include <bits/stdc++.h>
using namespace std;
int main()
{
    string content;
    int a = 0, b = 0, c = 0;
    getline(cin, content);
    while (content.find(";") != content.npos)
    {
        string tmp = content.substr(0, 5);
        content = content.substr(5);
        if (tmp[3] > 47 && tmp[3] < 58)
        {
            if (tmp[0] == 97)
                a = tmp[3] - 48;
            if (tmp[0] == 98)
                b = tmp[3] - 48;
            if (tmp[0] == 99)
                c = tmp[3] - 48;
        }
        else
        {
            if (tmp[0] == 97)
            {
                if (tmp[3] == 98)
                    a = b;
                if (tmp[3] == 99)
                    a = c;
            }
            if (tmp[0] == 98)
            {
                if (tmp[3] == 97)
                    b = a;
                if (tmp[3] == 99)
                    b = c;
            }
            if (tmp[0] == 99)
            {
                if (tmp[3] == 97)
                    c = a;
                if (tmp[3] == 98)
                    c = b;
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
    system("pause");
    return 0;
}
/*数字都这么赋值了，字母你不会开个数组当123吗，气抖冷*/