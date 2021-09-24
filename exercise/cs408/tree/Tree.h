#ifndef _Tree_h_
#define _Tree_h_

//������
typedef struct {
    char value;
}ElemType;
//�������ڵ�
typedef struct BiTNode
{
  ElemType data;
  BiTNode *lchild,*rchild;
}BiTNode, *BiTree;
//��α�����������
typedef struct LinkNode{
  BiTNode data;
  LinkNode* next;
}LinkNode;
typedef struct LinkQueue{
  LinkNode *front, *rear;
}LinkQueue;
/*��������*/

void InitTree(BiTree root);//��ʼ��������
bool InsertNode(BiTree T, ElemType val, bool LF);//�����½��
void CreateBiTree(BiTree &T);//�������(ABC##DE#G##F###)
void visit(BiTree T);//���ʺ���
void InOrderTraverse(BiTree T);//�������
void PreOrderTraverse(BiTree T);//�������
void PostOrderTraverse(BiTree T);//�������
void levelOrder(BiTree T);//��α���
/*���в�������*/

void InitQueue(LinkQueue &Q);
bool EnQueue(LinkQueue &Q, BiTNode *x);
bool DeQueue(LinkQueue &Q, BiTNode *x);
bool isEmpty(LinkQueue Q);

#endif