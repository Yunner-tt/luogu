#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,p,result=300;
    int content[3002];
    cin>>n>>p;
    for(int i=1;i<=n;++i){
        cin>>content[i];
    }
    for(int i=1;i<n-p;++i){
        int temp = 0;
        for(int j=0;j<p;++j){
            temp+=content[i+j];
        }
        if(temp<result) result=temp;
    }
    cout<<result<<endl;
    system("pause");
    return 0;
}
/*脱展P1147*/
/*运用前缀和数组可以降低减少时间，例如这道题，能从O(m*n)到O(m-n)*/