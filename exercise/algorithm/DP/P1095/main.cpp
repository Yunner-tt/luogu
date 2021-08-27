#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mana, aim, s, do_s, distance = 0;
    cin >> mana >> aim >> s;
    for (do_s = 1; do_s <= s; ++do_s)
    {
        if (mana >= 10)
        {
            distance += 60;
            mana -= 10;
        }
        else
        {
            if (s - do_s > 2)
            {
                if (aim - distance <= 51)
                    distance += 17;
                else
                    mana += 4;
            }
            else
            {
                if (s - do_s > 1) //s-do_s为后面还剩多少次
                {
                    if (aim - distance <= 34)
                        distance += 17;
                    else
                    {
                        if (mana > 1)
                            mana += 4;
                        else
                            distance += 17;
                    }
                }
                else if (s - do_s > 0)
                {
                    if (aim - distance <= 17)
                        distance += 17;
                    else
                    {
                        if (mana > 5)
                            mana += 4;
                        else
                            distance += 17;
                    }
                }
                else
                {
                    distance += 17;
                }
            }
        }
        if (distance >= aim)
            break;
    }
    if (distance >= aim)
    {
        cout << "Yes" << endl;
        cout << do_s << endl;
    }
    else
    {
        cout << "No" << endl;
        cout << distance << endl;
    }
    system("pause");
    return 0;
}
