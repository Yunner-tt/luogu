#include <bits/stdc++.h>
using namespace std;

#include "Tree.h"

//初始化
void InitTree(BiTree root)
{
  root = (BiTree)malloc(sizeof(BiTNode));
  root->data = {1};
  root->lchild = NULL;
  root->rchild = NULL;
}

//插入新结点
bool InsertNode(BiTree T, ElemType val, bool LF)
{
  BiTree p = (BiTree)malloc(sizeof(BiTNode));
  if (p != NULL)
  {
    p->data = val;
    p->lchild = NULL;
    p->rchild = NULL;
    if (LF)
      T->rchild = p;
    else
      T->lchild = p;
  }
  else
    ; //错误代码
  return LF;
}

//先序创建二叉树
void CreateBiTree(BiTree &T)
{
  char ch;
  scanf("%c", &ch);
  if (ch == '#')
    T = NULL;
  else
  {
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data.value = ch;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
  }
}

//访问函数
void visit(BiTree T)
{
  printf("%c", T->data.value);
}

//中序遍历
void InOrderTraverse(BiTree T)
{
  if (T)
  {
    InOrderTraverse(T->lchild);
    visit(T);
    InOrderTraverse(T->rchild);
  }
}

//先序遍历
void PreOrderTraverse(BiTree T)
{
  if (T)
  {
    visit(T);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
  }
}

//后序遍历
void PostOrderTraverse(BiTree T)
{
  if (T)
  {
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    visit(T);
  }
}

//层次遍历
void levelOrder(BiTree T)
{
  LinkQueue Q;
  InitQueue(Q);
  EnQueue(Q,T);
  while(!isEmpty(Q)){
    BiTNode *temp = (BiTNode *)malloc(sizeof(BiTNode));
    DeQueue(Q,temp);
    visit(temp);
    if(temp->lchild) EnQueue(Q,temp->lchild);
    if(temp->rchild) EnQueue(Q,temp->rchild);
    free(temp);
  }
}

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
bool isEmpty(LinkQueue Q)
{
  return Q.front == Q.rear ? true : false;
}