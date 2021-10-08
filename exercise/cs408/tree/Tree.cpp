#include <bits/stdc++.h>
#include "Tree.h"
#include"LinkQueue.h"
using namespace std;

//��ʼ��
void InitTree(BiTree root)
{
  root = (BiTree)malloc(sizeof(BiTNode));
  root->data = {1};
  root->lchild = NULL;
  root->rchild = NULL;
}
//�����½��
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
    ; //�������
  return LF;
}
//���򴴽�������
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
//���ʺ���
void visit(BiTree T)
{
  printf("%c", T->data.value);
}
//�������
void InOrderTraverse(BiTree T)
{
  if (T)
  {
    InOrderTraverse(T->lchild);
    visit(T);
    InOrderTraverse(T->rchild);
  }
}
//�������
void PreOrderTraverse(BiTree T)
{
  if (T)
  {
    visit(T);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
  }
}
//�������
void PostOrderTraverse(BiTree T)
{
  if (T)
  {
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    visit(T);
  }
}
//��α���
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