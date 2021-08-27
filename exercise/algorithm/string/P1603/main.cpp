#include <bits/stdc++.h>
using namespace std;
int main()
{
    string num[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    string conetnt;
    int len = 0, result[21];
    getline(cin, conetnt);
    stringstream sstream(conetnt);
    while (sstream)
    {
        string tmp;
        sstream >> tmp;
        for (int i = 0; i < 21; ++i)
        {
            if (tmp == num[i])
                result[len++] = i;
        }
        if (tmp == "a" || tmp == "another" || tmp == "first")
            result[len++] = 1;
        if (tmp == "both" || tmp == "second")
            result[len++] = 2;
        if (tmp == "third")
            result[len++] = 3;
    }
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (result[i] > result[j])
                swap(result[i], result[j]);
        }
    }
    int mark = 0;
    for (int i = 0; i < len; ++i)
    {
        result[i] = (result[i] * result[i]) % 100;
        if (result[i] != 0)
        {
            if (mark == 0)
            {
                cout << result[i];
                mark++;
            }
            else
                cout << setw(2) << setfill('0') << result[i];
        }
    }
    if(len==0) cout<<0;
    system("pause");
    return 0;
}
/*话不多说，下次请你打表，你个磨磨唧唧男*/
