#include <bits/stdc++.h>
using namespace std;
bool fun(string &ss, string a, string b);
int main()
{
    while (1)
    {
        int p = 0;
        string var_string[4];
        int var[3] = {0};
        string ss;
        bool mark = true;
        cout << "�����������εı߳�:";
        getline(cin, ss);
        stringstream ssteam(ss);
        while (ssteam >> var_string[p])
        {
            ++p;
            if (p == 4) break;
        }
        if (p != 3)
        {
            cout << "�������!" << endl;
            continue;
        }
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < var_string[i].length(); ++j)
            {
                if (var_string[i][j] < 48 || var_string[i][j] > 57)
                    mark = false;
            }
        }
        if (!mark)
        {
            cout << "�������!" << endl;
            continue;
        }
        for (int i = 0; i < 3; ++i)
        {
            ssteam.clear();
            ssteam.str(std::string());
            ssteam << var_string[i];
            ssteam >> var[i];
        }
        if (ss[0] != ' ' && fun(ss, var_string[0], var_string[1]) && fun(ss, var_string[1], var_string[2]))
        {
            if ((var[0] <= 0 || var[0] > 100) || (var[1] <= 0 || var[1] > 100) || (var[2] <= 0 || var[2] > 100))
            {
                cout << "���ݳ�����Χ!" << endl;
                continue;
            }
            else
            {
                if (var[0] + var[1] > var[2] && var[0] + var[2] > var[1] && var[1] + var[2] > var[0])
                {
                    if (var[0] == var[1] && var[1] == var[2] && var[0] == var[2])
                    {
                        cout << "���ɵȱ�������" << endl;
                    }
                    else if (var[0] == var[1] || var[1] == var[2] || var[0] == var[2])
                    {
                        cout << "���ɵ���������" << endl;
                    }
                    else
                    {
                        cout << "������ͨ������" << endl;
                    }
                }
                else
                {
                    cout << "������������" << endl;
                }
            }
        }
        else
        {
            cout << "�������!" << endl;
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