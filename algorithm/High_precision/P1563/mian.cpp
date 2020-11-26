#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m,p=0;
    cin >> n >> m;
    bool *towards = new bool[n];
    string *name = new string[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> towards[i] >> name[i];
    }
    for (int i = 0; i < m; ++i)
    {
        bool direction;
        int s;
        cin>>direction>>s;
        if(direction^towards[p]) {
            if(s+p<n) p+=s;
            else{
                p=p+s-n;
            }
        }else{
            if(p-s>=0) p-=s;
            else{
                p=p+n-s;
            }
        }
    }
    cout<<name[p]<<endl;
    system("pause");
    return 0;
}
/*巧妙运用异或运算，日后可改进方案，输出用printf，用使用结构体里面用char存储名字*/