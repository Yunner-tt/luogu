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
        ss = "";p = 0;
        for (int i = 0; i < 3; ++i)
        {
            var[i] = 0;
            var_string[i] = "";
        }
        cout << "請輸入:";
        getline(cin, ss);
        stringstream ssteam(ss);
        while (ssteam >> var[p]) ++p;
        if (p != 3){
            cout<<"輸出不足或者輸出不是數字"<<endl;
            continue;
        }

        for (int i = 0; i < 3; ++i)
        {
            ssteam.clear();
            ssteam.str(std::string());
            ssteam << var[i];
            var_string[i] = ssteam.str();
        }
        if (ss[0] != ' ' && fun(ss, var_string[0], var_string[1]) && fun(ss, var_string[1], var_string[2]))
        {
            if ((var[0] <= 0 || var[0] > 100) || (var[1] <= 0 || var[1] > 100) || (var[2] <= 0 || var[2] > 100))
            {
                cout<<"输入数字超出预定范围"<<endl;
                continue;
            }
            else
            {
                if (var[0] + var[1] > var[2] && var[0] + var[2] > var[1] && var[1] + var[2] > var[0])
                {
                    if (var[0] == var[1] && var[1] == var[2] && var[0] == var[2])
                    {
                        cout << "等边三角形" << endl;
                    }
                    else if (var[0] == var[1] || var[1] == var[2] || var[0] == var[2])
                    {
                        cout << "等腰三角形" << endl;
                    }
                    else
                    {
                        cout << "普通三角形" << endl;
                    }
                }
                else
                {
                    cout << "不构成三角形" << endl;
                }
            }
        }
        else
        {
            cout<<"輸入格式不對，(請不要首行空格)"<<endl;
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