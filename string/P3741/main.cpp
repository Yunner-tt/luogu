#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len, num = 0;
    string content;
    cin >> len;
    int confirm[len] = {0};
    cin >> content;
    len = 0;
    for (int i = 0; i < content.size() - 1; ++i)
    {
        if (content[i + 1] == content[i])
        {
            confirm[i] = 1;
            confirm[i + 1] = 1;
        }
    }
    while (content.find("VK") != content.npos)
    {
        len += content.find("VK");
        content = content.substr(content.find("VK") + 2);
        num++;
        confirm[len++] = 0;
        confirm[len++] = 0;
    }
    for (int i = 0; i < sizeof(confirm) - 1; ++i)
    {
        if (content[i + 1] == 1 && content[i] == 1)
        {
            cout << ++num << endl;
            system("pause");
            return 0;
        }
    }
    cout << num << endl;
    system("pause");
    return 0;
}
