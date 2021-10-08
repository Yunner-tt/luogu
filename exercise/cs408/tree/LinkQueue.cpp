#include <bits/stdc++.h>
using namespace std;

#include"LinkQueue.h"

//���г�ʼ��
void InitQueue(LinkQueue &Q)
{
  Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
  //��ʼ��ʱ��front ��rear ��ָ��ͷ�ڵ�
  Q.front->next = NULL;
}
//��ӣ�rearʼ��ָ������Ԫ�أ�
bool EnQueue(LinkQueue &Q, BiTNode *x)
{
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  if (s == NULL)
    return false;
  s->data = *x;
  s->next = NULL;
  Q.rear->next = s;
  Q.rear = s;
  return true;
}
//���ӣ�frontʼ��ָ������Ԫ��ǰһ��Ԫ�أ�
bool DeQueue(LinkQueue &Q, BiTNode *x)
{
  //�ӿգ��߲���
  if (Q.front == Q.rear)
    return false;
  LinkNode *p = Q.front;
  Q.front = p->next;
  *x = Q.front->data;
  free(p);
  return true;
}
//�п�
bool isEmpty(LinkQueue Q){
  return Q.front == Q.rear ? true : false;
}