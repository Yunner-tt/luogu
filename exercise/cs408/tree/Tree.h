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

void InitTree(BiTree root); //初始化二叉树
bool InsertNode(BiTree T, ElemType val, bool LF); //插入新结点
void CreateBiTree(BiTree &T); //先序插入(ABC##DE#G##F###)
void visit(BiTree T); //访问函数
void InOrderTraverse(BiTree T); //中序遍历
void PreOrderTraverse(BiTree T); //先序遍历
void PostOrderTraverse(BiTree T); //后序遍历
void levelOrder(BiTree T); //层次遍历

#endif