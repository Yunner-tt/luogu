#include <bits/stdc++.h>
using namespace std;
int main(){
    int boy=0,girl=0;
    char content[257]={0};
    cin>>content;
    for(int i=0;i<strlen(content)-2;++i){
        if(content[i]=='b'||content[i+1]=='o'||content[i+2]=='y') boy++;
        if(content[i]=='g'||content[i+1]=='i'||content[i+2]=='r'||content[i+3]=='l') girl++;
    }
    cout<<boy<<endl;
    cout<<girl<<endl;
    system("pause");
    return 0;
}
