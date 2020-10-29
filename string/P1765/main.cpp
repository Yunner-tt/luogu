#include <bits/stdc++.h>
using namespace std;
int main()
{
    int count[27], result = 0;
    char tmp;
    for (int i = 0; i < 26; ++i)
    {
            count[i] = i % 3 + 1;
    }
    for(int i=24;i>18;--i) count[i]=count[i-1];
    count[18] = 4;
    count[25] = 4;
    while ((tmp = getchar()) != '\n')
    {
        cout << tmp << endl;
        if (tmp >= 'a' && tmp <= 'z')
            result = result + count[tmp - 'a'];
        else if(tmp==' ')
            result++;
    }
    cout << result << endl;
    system("pause");
    return 0;
}
