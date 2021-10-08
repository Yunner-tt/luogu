#include <bits/stdc++.h>
using namespace std;

#include"LinkQueue.h"

//队列初始化
void InitQueue(LinkQueue &Q)
{
  Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
  //初始化时，front 、rear 都指向头节点
  Q.front->next = NULL;
}
//入队（rear始终指向数据元素）
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
//出队（front始终指向数据元素前一个元素）
bool DeQueue(LinkQueue &Q, BiTNode *x)
{
  //队空，走不了
  if (Q.front == Q.rear)
    return false;
  LinkNode *p = Q.front;
  Q.front = p->next;
  *x = Q.front->data;
  free(p);
  return true;
}
//判空
bool isEmpty(LinkQueue Q){
  return Q.front == Q.rear ? true : false;
}