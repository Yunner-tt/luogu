#include <bits/stdc++.h>
#include "stack.h"
using namespace std;

//��ʼ��
void InitStack(SqStack &S)
{
  S.top = -1; //���ֳ�ʼ���ķ�ʽ��ջ��ָ��ʼ��ָ��ջ��Ԫ��
}

//��ջ
bool Push(SqStack &S, int t)
{
  if (S.top == MaxSize - 1)
    return false; //ջ��
  S.data[++S.top] = t;
  //    �ȼ������������
  //    S.top+=1;//�Ƚ�ջ��ָ��ָ����һ��λ��
  //    S.data[S.top]=t;//�����Ԫ��
  return true;
}

//��ջ,����ӡ��ջ��Ԫ��
bool Pop(SqStack &S, int &x)
{
  //�ж�
  if (S.top == -1)
    return false; //ջ�ձ���
  x = S.data[S.top--];
  //    �ȼ�������
  //    x=S.data[S.top];//��ȡԪ��
  //    S.top -=1;//�ٸ�ָ��
  return true;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack S, int &x)
{
  if (S.top == -1)
    return false;
  x = S.data[S.top];
  return true;
}

/*��ȡջ��Ԫ�صĵڶ���ʵ�ַ�ʽ
���÷���ֵ����ջ��Ԫ�أ����ɹ��ͷ���ջ��Ԫ�أ�ʧ�ܾͷ���-1��
ȱ�㣺���ջ��Ԫ�ؾ���-1������������У���������ȱ�㣬������Կ���������д���ַ�ʽӦ���ǻᱻ�۲��ַ�����*/
ElemType GetTop(SqStack S)
{
  if (S.top == -1)
    return -1;
  return S.data[S.top];
}

//��ӡ����ջ
void PrintStack(SqStack S)
{
  printf("ջ��[");
  while (S.top >= 0)
  { //ע���пյ�����
    printf(" %d,", S.data[S.top]);
    S.top--;
  }
  printf("]\n");
}