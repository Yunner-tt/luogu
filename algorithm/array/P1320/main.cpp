#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool mark = false;
    int p=1;
    char content[40000],tmp[201];
    cin>>tmp;
    strcat(content,tmp);
    int n = strlen(content);
    for(int i=1;i<n;++i){
        cin>>tmp;
        strcat(content,tmp);
    }
    cout<<n<<" ";
    if(content[0]=='1') cout<<0<<" ";
    for(int i=0;i<n*n;++i){
        if(content[i]==content[i+1]){
            p++;
        }else {
            cout<<p<<" ";
            p=1;

        }
    }
    system("pause");
    return 0;
}