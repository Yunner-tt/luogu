#include<bits/stdc++.h>
using namespace std;
/**
 * �ṹ������ķ�ʽ
 * ����һ���±����ķ�ʽ��struct Student aa;
 */
struct Student
{ 
  int aa;
  int bb;
};
/**
 * �ṹ���ڿ��Դ����Լ���ָ��
 */
struct Student1
{ 
  int aa;
  int bb;
  //�������ڽṹ���д���֮ǰ�����Ľṹ�� ���Լ��Լ���ָ��
  struct Student cc;
  struct Student1* cc;
};
/**
 * �����������ṹ��ʱ�ʹ���һЩ����
 * �����ڣ�
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
 * �ṹ�帳��ֵ�ķ���(����)
 * ��һ��: ˳����
 * struct Student2 s_a = {1,2}; //Ĭ�ϲ���˳������aa=1;bb=2;
 * struct Student2 all = {{1,2},{3,4},{5,6},{7,8},{9,10}};
 * 
 * �ڶ��֣��ȶ��������ֵ
 * struct Student2 s_a;
 * s_a.aa = 1;
 * s_a.bb = 2;
 * 
 * �����֣�c������(�����Ϳ��Բ���˳�򸳳�ֵ)
 * struct Student2 s_a = {
 *     .aa = 1,
 *     .bb = 2,
 * }
 * 
 * �����֣�c++������(�����Ϳ��Բ���˳�򸳳�ֵ)
 * struct Student2 s_a = {
 *     aa: 1,
 *     bb: 2,
 * }
 */
/*---------------------------------------------------------------------------------------*/
/**
 * typedef�ؼ���(���ﻹ�кܶ��ô������˽�һ�»�ʹ�þ���)
 */

/*
  ������StudentΪS
  ���Կ�����S aa���泣��struct Student aa;
*/
typedef struct Student
{ 
} S;
typedef struct aa
{
  
}*abc;


//�Զ�ʵ����ָ�봫�ݣ�Ȼ����ֱ�ӵ���a���ǵ���ԭ����ַ��ֵ
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