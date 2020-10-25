#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sq[21][21][21] = {0};
    int a,b,c,n,result=0;
    int x1, x2, y1, y2,z1,z2;
    cin>>a>>b>>c;
    cin >> n;
    while(n>0){
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int x=x1;x<=x2;++x){
            for(int y=y1;y<=y2;++y){
                for(int z=z1;z<=z2;++z){
                    sq[x][y][z]=1;
                }
            }
        }
        --n;
    }
    for(int x=1;x<=a;++x){
        for(int y=1;y<=b;++y){
            for(int z=1;z<=c;++z){
                if(sq[x][y][z]==0){
                    result++;
                }
            }
        }
    }

    cout<<result<<endl;
        system("pause");
    return 0;
}