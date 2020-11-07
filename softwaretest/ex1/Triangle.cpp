#include <bits/stdc++.h>
using namespace std;
bool fun(string &ss, string a, string b);
int main()
{
    int p = 0;
    string var_string[3];
    int var[3] = {0};
    string ss;
    while (1)
    {
        ss = "";
        p = 0;
        for (int i = 0; i < 3; ++i)
        {
            var[i] = 0;
            var_string[i] = "";
        }
        cout << "Please enter data:";
        getline(cin, ss);
        stringstream ssteam(ss);
        while (ssteam >> var[p])
            ++p;
        if (p != 3) //提醒输入不全(这里是两种情况，输入不全，或者输入非数字，看看等下还能改吗)
            continue;
        for (int i = 0; i < 3; ++i)
        {
            ssteam.clear();
            ssteam.str("");
            ssteam << var[i];
            var_string[i] = ssteam.str();
        }
        if (ss[0] != ' ' && fun(ss, var_string[0], var_string[1]) && fun(ss, var_string[1], var_string[2]))
        {
            if ((var[0] < 0 || var[0] > 100) || (var[1] < 0 || var[1] > 100) || (var[2] < 0 || var[2] > 100))
            {
                //提醒数的大小不对
                continue;
            }
            else
            {
                if (var[0] + var[1] > var[2] && var[0] + var[2] > var[1] && var[1] + var[2] > var[0])
                {
                    if (var[0] == var[1] == var[2])
                    {
                        cout << "is Equilateral Triangle" << endl;
                    }
                    else if (var[0] == var[1] || var[1] == var[2] || var[0] == var[2])
                    {
                        cout << "is Isosceles Triangle" << endl;
                    }
                    else
                    {
                        cout << "is Normal Triangle" << endl;
                    }
                }
                else
                {
                    cout << "isn`t Triangle" << endl;
                }
            }
        }
        else
        {
            //这里也是输入缺少
            continue;
        }
    }
    system("pause");
    return 0;
}

bool fun(string &ss, string a, string b)
{
    bool p = false;
    ss = ss.substr((ss.find(a) + a.length() + 1));
    if (ss.find(b) == 0)
        p = true;
    return p;
}