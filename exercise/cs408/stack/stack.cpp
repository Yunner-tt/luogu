#include <bits/stdc++.h>
#include "stack.h"
using namespace std;

//初始化
void InitStack(SqStack &S)
{
  S.top = -1; //这种初始化的方式，栈顶指针始终指向栈顶元素
}

//入栈
bool Push(SqStack &S, int t)
{
  if (S.top == MaxSize - 1)
    return false; //栈满
  S.data[++S.top] = t;
  //    等价下面两个语句
  //    S.top+=1;//先将栈顶指针指向下一个位置
  //    S.data[S.top]=t;//再填充元素
  return true;
}

//出栈,并打印出栈顶元素
bool Pop(SqStack &S, int &x)
{
  //判断
  if (S.top == -1)
    return false; //栈空报错
  x = S.data[S.top--];
  //    等价于下面
  //    x=S.data[S.top];//先取元素
  //    S.top -=1;//再改指针
  return true;
}

//读取栈顶元素
bool GetTop(SqStack S, int &x)
{
  if (S.top == -1)
    return false;
  x = S.data[S.top];
  return true;
}

/*读取栈顶元素的第二种实现方式
利用返回值返回栈顶元素，若成功就返回栈顶元素，失败就返回-1；
缺点：如果栈顶元素就是-1，容易造成误判，正因它的缺点，如果考试考到了它，写这种方式应该是会被扣部分分数的*/
ElemType GetTop(SqStack S)
{
  if (S.top == -1)
    return -1;
  return S.data[S.top];
}

//打印整个栈
void PrintStack(SqStack S)
{
  printf("栈：[");
  while (S.top >= 0)
  { //注意判空的条件
    printf(" %d,", S.data[S.top]);
    S.top--;
  }
  printf("]\n");
}