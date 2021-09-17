#include<bits/stdc++.h>
using namespace std;
/**
 * 结构体最初的方式
 * 创建一个新变量的方式：struct Student aa;
 */
struct Student
{ 
  int aa;
  int bb;
};
/**
 * 结构体内可以创建自己的指针
 */
struct Student1
{ 
  int aa;
  int bb;
  //①允许在结构体中创建之前创建的结构体 ②以及自己的指针
  struct Student cc;
  struct Student1* cc;
};
/**
 * 可以在声明结构体时就创建一些变量
 * 类似于：
 * struct Student2 s_a;
 * struct Student2 s_b;
 * struct Student2 all[5];
 */
struct Student2
{ 
  int aa;
  int bb;
}s_a,s_b,all[5];
/**
 * 结构体赋初值的方法(四种)
 * 第一种: 顺序定义
 * struct Student2 s_a = {1,2}; //默认参数顺序，所以aa=1;bb=2;
 * struct Student2 all = {{1,2},{3,4},{5,6},{7,8},{9,10}};
 * 
 * 第二种：先定义逐个赋值
 * struct Student2 s_a;
 * s_a.aa = 1;
 * s_a.bb = 2;
 * 
 * 第三种：c风格进阶(这样就可以不按顺序赋初值)
 * struct Student2 s_a = {
 *     .aa = 1,
 *     .bb = 2,
 * }
 * 
 * 第四种：c++风格进阶(这样就可以不按顺序赋初值)
 * struct Student2 s_a = {
 *     aa: 1,
 *     bb: 2,
 * }
 */
/*---------------------------------------------------------------------------------------*/
/**
 * typedef关键字(这里还有很多用处，简单了解一下会使用就行)
 */

/*
  重命名Student为S
  所以可以用S aa代替常规struct Student aa;
*/
typedef struct Student
{ 
} S;
typedef struct aa
{
  
}*abc;


//自动实现了指针传递，然后你直接调用a就是调用原来地址的值
void fun1(int &a,int &b){
  a=10;
  b=20;
}
void fun2(int *a,int *b){
  *a=10;
  *b=20;
}
// void fun3(int &a,int &b){
//   a=10;
//   b=20;
// }
int main(){
  int a = 5, b = 6;
  int *c = (int *)malloc(sizeof(int));
  int *d = (int *)malloc(sizeof(int));
  *c = 2;
  *d = 3;
  fun1(a,b);
  fun2(c,d);
  printf("A:%d,B:%d\n",a,b);
  printf("A:%d,B:%d\n",*c,*d);
  system("pause");
  return 0;
}