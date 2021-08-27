#include <bits/stdc++.h>
using namespace std;
bool mark[100001];
int prime[20001];

int init(int max)
{
    memset(mark, true, sizeof(mark));
    int num = 0;
    for (int i = 2; i <= max; ++i)
    {
        if (mark[i])
            prime[++num] = i;
        for (int j = 1; (j <= num) && (i * prime[j] <= max); ++j)
        {
            mark[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
    return num;
}
bool cg(int num){
    if(num<2) return false;
    for(int i=2;i<=sqrt(num);++i){
        if(num%i==0) return 0;
    }
    return true;
}
int main()
{
    int content[101], a, n;
    bool p;
    n = init(100001);
    cin >> a;
    for (int i = 0; i < a; ++i)
    {
        cin >> content[i];
    }
    for (int i = 0; i < a; ++i)
    {
        p = true;
        for (int j = 0; j < n; ++j)
        {
            if (content[i] == prime[j])
            {
                p = false;
                break;
            }
        }
        if (!p)
            cout << content[i] << " ";
    }
    system("pause");
    return 0;
}
/*三种求素数的方法，欧拉法打表，开根法直接求*/