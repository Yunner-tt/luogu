#include<bits/stdc++.h>
using namespace std;
int result[13]={1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int n;
int main()
{
	cin>>n;
	cout<<result[n-1];
	return 0;
}