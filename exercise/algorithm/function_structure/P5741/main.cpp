#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string name[n];
    int score[n][3];
    for (int i = 0; i < n; ++i)
    {
        cin >> name[i] >> score[i][0] >> score[i][1] >> score[i][2];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (abs(score[i][0] - score[j][0]) <= 5 && abs(score[i][1] - score[j][1]) <= 5 && abs(score[i][2] - score[j][2]) <= 5 && abs(score[i][0] + score[i][1] + score[i][2] - (score[j][0] + score[j][1] + score[j][2])) <= 10)
            {
                cout << name[i] << " " << name[j] << endl;
            }
        }
    }
    system("pause");
    return 0;
}
