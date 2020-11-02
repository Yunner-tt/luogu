#include <bits/stdc++.h>
using namespace std;
string trans(string a);
int main()
{
    string content;
    cin >> content;
    if (content.find('.')!=content.npos)
    {
        string a = content.substr(0, content.find('.'));
        string b = content.substr(content.find('.') + 1);
        cout << trans(a) << "." << trans(b) << endl;
    }
    else if (content.find('/')!=content.npos)
    {
        string a = content.substr(0, content.find('/'));
        string b = content.substr(content.find('/') + 1);
        cout << trans(a) << "/" << trans(b) << endl;
    }
    else if (content.find('%')!=content.npos)
    {
        string a = content.substr(0, content.find('%'));
        cout << trans(a) << "%" << endl;
    }
    else
    {
        cout << trans(content) << endl;
    }
    system("pause");
    return 0;
}

string trans(string a)
{
    int len = a.length();
    int start = 0;
    int end = a.length();
    while (a[end - 1] == '0')
    {
        end--;
        len--;
    }
    while (a[start] == '0')
    {
        start++;
        len--;
    }
    if(start>end) {
        start=0;
        end=1;
    }
    a = a.substr(start, end);
    for (int i = 0; i < len / 2; ++i)
    {
        char tmp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = tmp;
    }
    return a;
}
