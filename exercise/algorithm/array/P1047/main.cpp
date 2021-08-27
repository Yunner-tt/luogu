#include <bits/stdc++.h>
using namespace std;
int main()
{
    int shu[10001] = {0};
    int l, m, x, y,result=0;
    cin >> l >> m;
    while (m > 0)
    {
        cin >> x >> y;
        for (; x <= y; ++x)
        {
            shu[x]=1;
        }
        --m;
    }
    for(int i=0;i<=l;++i){
        if(shu[i]==0){
            result++;
        }
    }
    cout<<result<<endl;
    system("pause");
    return 0;
}