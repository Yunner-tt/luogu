#include <bits/stdc++.h>
using namespace std;
int main()
{
    int day, month, year;
    cout << "依次输入月 日 年:";
    cin >> month >> day >> year;
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (day == 29)
            {
                day = 1;
                month++;
            }
            else
                day++;
        }
        else
        {
            if (day == 28)
            {
                day = 1;
                month++;
            }
            else
                day++;
        }
    }
    else if (month == 12)
    {
        if (day == 31)
        {
            day = 1;
            month = 1;
            if (year != 2050)
                year++;
            else
                cout << "超出最大年限!!!" << endl;
        }
        else
            day++;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day == 30)
        {
            day = 1;
            month++;
        }
        else
            day++;
    }
    else
    {
        if (day == 31)
        {
            day = 1;
            month++;
        }
        else
            day++;
    }
    cout<<year<<"/"<<month<<"/"<<day<<endl;
    system("pause");
    return 0;
}