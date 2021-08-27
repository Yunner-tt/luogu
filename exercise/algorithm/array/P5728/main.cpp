#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, result = 0;
    int chinese[1001], math[1001], english[1001];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> chinese[i] >> math[i] >> english[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (abs(chinese[i] - chinese[j]) <= 5 && abs(math[i] - math[j]) <= 5 && abs(english[i] - english[j]) <= 5 && abs((chinese[i] + math[i] + english[i]) - (chinese[j] + math[j] + english[j])) <= 10) result++;
        }
    }
    cout<<result<<endl;
    system("pause");
    return 0;
}