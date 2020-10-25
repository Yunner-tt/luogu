#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int jin[21][21];
    for(int i=1;i<21;++i){
        jin[i][1]=1;
        jin[i][i]=1;
    }
    for(int i=3;i<21;++i){
        for(int j=2;j<i;++j){
            jin[i][j]=jin[i-1][j]+jin[i-1][j-1];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            cout<<jin[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}