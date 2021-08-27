#include <bits/stdc++.h>
using namespace std;
int main(){
    string name;
    int n,a,b,c,result=0;
    cin>>n;
    while(n--){
        string sname;
        int sa,sb,sc;
        cin>>sname>>sa>>sb>>sc;
        int tmp=sa+sb+sc;
        if(result<tmp) {
            a=sa;b=sb;c=sc;
            result=tmp;
            name=sname;
        }
    }
    cout<<name<<" "<<a<<" "<<b<<" "<<c<<endl;
    system("pause");
    return 0;
}
/*这道题很简单，没有要注意的地方*/