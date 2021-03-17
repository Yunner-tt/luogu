#include <bits/stdc++.h>
using namespace std;
int main()
{
    while (1)
    {
        int day, month, year;
        cout << "请输入日期:";
        cin >> month >> day >> year;
        while (!cin.good())
        {
            cout << "输入有误重新输入!!" << endl;
            cout << "请输入日期:";
            cin.clear();
            cin.sync();
        loop:
            cin >> month >> day >> year;
        }
        if (day < 1 || day > 28 || month < 1 || month > 12 || year > 2050 || year < 1900)
        {
            if (month == 2)
            {
                if ((year % 4 == 0 && year % 100 != 0 || year%400==0) && day < 30);
                else
                {
                    cout << "数值超过范围!!" << endl;
                    cout << "请输入日期:";
                    goto loop;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                if (day > 30)
                {
                    cout << "数值超过范围!!" << endl;
                    cout << "请输入日期:";
                    goto loop;
                }
            }
            else
            {
                if(day>31){
                    cout << "数值超过范围!!" << endl;
                    cout << "请输入日期:";
                    goto loop;
                }
            }
        }
        if (month == 2)
        {
            if (year % 4 == 0 && year % 100 != 0 || year%400==0)
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
                year++;
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
        cout << year << "/" << month << "/" << day << endl;
    }
    system("pause");
    return 0;

    //是的是的
}