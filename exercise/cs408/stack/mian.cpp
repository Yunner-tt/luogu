#include<bits/stdc++.h>
#include
using namespace std;
#include"stack.h"

int main(){
  SqStack stack;
  InitStack(stack);
  Push(stack,1);Push(stack,2);Push(stack,3);Push(stack,4);Push(stack,5);Push(stack,6);
  printf("%d\n",GetTop(stack));
  PrintStack(stack);
  system("pause");
  return 0;
}