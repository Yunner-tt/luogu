#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    cout<<a<<endl;
    system("pause");
    return 0;
}