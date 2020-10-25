#include <bits/stdc++.h>
using namespace std;
int main()
{
    int process[200];
    int n = 0,p=1;
    cin >> n;
    for(;n!=1;++p){
        process[p]=n;
        if(n%2==0){
            n/=2;
        }
        else{
            n=n*3+1;
        }
    }
    process[p]=1;
    for(;p>0;--p){
        cout<<process[p]<<" ";
    }
    system("pause");
    return 0;
}
/*按照题目要求写*/