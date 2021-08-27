#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    string result[51];
    char type;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (!(cin >> a))
        {
            cin.clear();
            cin >> type >> a;
        }
        cin >> b;
        switch (type)
        {
        case 'a':
            result[i] = (to_string(a) + '+' + to_string(b) + '=' + to_string(a + b));
            break;
        case 'b':
            result[i] = (to_string(a) + "-" + to_string(b) + '=' + to_string(a - b));
            break;
        case 'c':
            result[i] = (to_string(a) + "*" + to_string(b) + '=' + to_string(a * b));
            break;
        }
    }
    for(int i=1;i<=n;++i){
        cout<<result[i]<<endl;
        cout<<result[i].length()<<endl;
    }
    system("pause");
    return 0;
}