#ifndef _Tree_h_
#define _Tree_h_

//数据域
typedef struct {
    char value;
}ElemType;
//二叉树节点
typedef struct BiTNode
{
  ElemType data;
  BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
//层次遍历辅助队列
typedef struct LinkNode{
  BiTNode data;
  LinkNode* next;
}LinkNode;
typedef struct LinkQueue{
  LinkNode *front, *rear;
}LinkQueue;
/*方法声明*/

void InitTree(BiTree root);//初始化二叉树
bool InsertNode(BiTree T, ElemType val, bool LF);//插入新结点
void CreateBiTree(BiTree &T);//先序插入(ABC##DE#G##F###)
void visit(BiTree T);//访问函数
void InOrderTraverse(BiTree T);//中序遍历
void PreOrderTraverse(BiTree T);//先序遍历
void PostOrderTraverse(BiTree T);//后序遍历
void levelOrder(BiTree T);//层次遍历
/*队列操作集合*/

void InitQueue(LinkQueue &Q);
bool EnQueue(LinkQueue &Q, BiTNode *x);
bool DeQueue(LinkQueue &Q, BiTNode *x);
bool isEmpty(LinkQueue Q);

#endif