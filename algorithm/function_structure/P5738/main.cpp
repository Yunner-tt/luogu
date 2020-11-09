#include <bits/stdc++.h>
using namespace std;
int main(){
    int row,colum;
    cin>>row>>colum;
    double result=0;
    while(row--){
        int max=0,min=11,tmp=0;
        double sum=0;
        for(int i=0;i<colum;++i){
            cin>>tmp;
            if(tmp>max) max=tmp;
            if(tmp<min) min=tmp;
            sum+=tmp;
        }
        sum=(sum-max-min)/(colum-2);
        if(result<sum) result=sum;
    }
    cout<<fixed<<setprecision(2)<<result<<endl;
    system("pause");
    return 0;
}
/* double/int为double型 getline(cin,s)得另外判断跳出*/