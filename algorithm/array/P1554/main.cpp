#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    int p[10]={0};
    cin>>a>>b;
    for(int i = a;i<=b;++i){
        int temp = i;
        while(temp!=0){
            p[temp%10]++;
            temp/=10;
        }
    }
    for(int i= 0;i<10;++i){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}