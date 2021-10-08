#ifndef _Queue_h_
#define _Queue_h_

#include "Tree.h"
//层次遍历辅助队列
typedef struct LinkNode{
  BiTNode data;
  LinkNode* next;
}LinkNode;
typedef struct LinkQueue{
  LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q);
bool EnQueue(LinkQueue &Q, BiTNode *x);
bool DeQueue(LinkQueue &Q, BiTNode *x);
bool isEmpty(LinkQueue Q);

#endif