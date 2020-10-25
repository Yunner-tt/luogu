#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool p = false;
    int a = 101, b = 101, c = 101;
    cout<<"Please enter data:";
    while ((a < 0 || a > 100) || (b < 0 || b > 100) || (c < 0 || c > 100))
    {
        if(p) cout<<"The data you entered is wrong, please re-enter:";
        cin >> a >> b >> c;
        p = true;
    }
    if (a + b > c && a + c > b && b + c > a)
    {
        if(a==b==c){
            cout<<"is Equilateral Triangle"<<endl;
        }
        else if(a==b||b==c||a==c)
        {
            cout<<"is Isosceles Triangle"<<endl;
        }
        else
        {
            cout<<"is Normal Triangle"<<endl;
        }
    }
    else
    {
        cout<<"isn`t Triangle"<<endl;
    }
    system("pause");
    return 0;
}