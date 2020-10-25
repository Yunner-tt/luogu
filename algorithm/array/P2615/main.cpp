#include<iostream>
using namespace std;
int main(){
    int n,befor_x,befor_y;
    int result[40][40]={0};
    cin >> n;
    befor_x=1;
    befor_y=n/2+1;
    result[befor_x][befor_y]=1;
    for(int i=2;i<=n*n;i++){
        if(befor_x==1&&befor_y!=n){
            befor_x = n;
            befor_y++;
        }
        else if(befor_x!=1&&befor_y==n){
            befor_x--;
            befor_y = 1;
        }
        else if(befor_x==1&&befor_y==n){
            befor_x++;
        }
        else{
            if(result[befor_x-1][befor_y+1]==0){
                befor_x--;
                befor_y++;
            }
            else{
                befor_x++;
            }
        }
        result[befor_x][befor_y] = i;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}