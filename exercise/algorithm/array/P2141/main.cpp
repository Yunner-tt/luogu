#include<iostream>
using namespace std;
int main(){
    int num,result=0;
    int content[101]={0},copy[101]={0};
    cin >> num;
    for(int i = 1;i <= num; ++i){
        cin >> content[i];
        copy[i] = content[i];
    }
    for(int i=1;i <= num; ++i){
        for(int j=i+1; j <= num; ++j){
            int temp = content[i]+content[j];
            for(int n = 1;n <= num; ++n){
                if(copy[n]==temp){
                    copy[n]=0;
                    result++;
                }
            }
        }
    }
    cout<<result<<endl;
    return 0;
}