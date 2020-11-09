#include <bits/stdc++.h>
using namespace std;
int main(){
    double content[6],p=0;
    for(int i=0;i<6;++i){
        cin>>content[i];
    }
    cout<<fixed<<setprecision(2)<<(double)(sqrt(pow(content[2]-content[0],2)+pow(content[3]-content[1],2)))+(sqrt(pow(content[4]-content[0],2)+pow(content[5]-content[1],2))+(sqrt(pow(content[4]-content[2],2)+pow(content[5]-content[3],2))))<<endl;
    system("pause");
    return 0;
}
