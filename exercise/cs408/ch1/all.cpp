#include<bits/stdc++.h>
using namespace std;

void fun(){
	static int a = 10;
		printf("%d ",a++);
}

void sum(){
	static int a = 100;
	printf("%d ",a++);
}

int main(){
	int i=10;
	while(i--){
		fun();
		sum();
	}
	system("pause");
	return 0;
}