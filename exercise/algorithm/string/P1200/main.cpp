#include <bits/stdc++.h>
using namespace std;
int main()
{
    char content[6]={0};
    int team = 1, ufo = 1;
    cin >> content;
    for (int i = 0; i < strlen(content); ++i)
    {
        team *= (content[i] - 'A'+1);
    }
    cin >> content;
    for (int i = 0; i < strlen(content); ++i)
    {
        ufo *= (content[i] - 'A'+1);
    }
    if((team%47)==(ufo%47)) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
    system("pause");
    return 0;
}
