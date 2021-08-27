#include<bits/stdc++.h>
using namespace std;
int main(){
    int result[101];
    int temp = 0,p = 1;
    do
    {
        cin>>temp;
        result[p]=temp;
        ++p;
    } while (temp !=0);
    p-=2;
    while (p>0)
    {
        cout<<result[p]<<" ";
        --p;
    }
    system("pause");
    return 0;
}
/*本题目主要就是栈的思想，先进栈沉底，后进栈先取出，可以使用stl中stack快速解决*/