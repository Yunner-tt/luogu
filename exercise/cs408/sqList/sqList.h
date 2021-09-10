#ifndef _Sqlist_H_
#define _Sqlist_H_

#define MaxSize 30
#define ElemType int
#define Bool bool
//˳�������
typedef struct
{
   ElemType data[MaxSize];
   int length;
}SqList;
//˳���������
void InitList(SqList &L);                           //��ʼ��
Bool Empty(SqList L);                               //�п�
Bool ListInsert(SqList &L, int i, ElemType e);           //����
Bool ListDelete(SqList &L, int i, ElemType &e);          //ɾ��
ElemType GetElem(SqList L, int i);                       //��λ����
ElemType LocateElem(SqList L, ElemType e);                    //��ֵ����
Bool LocateChangeElem(SqList &L, ElemType e, ElemType em);    //��ֵ�޸�(eΪ����ֵ��emΪ�޸�ֵ)
Bool getChangeElem(SqList &L, int i, ElemType em);       //��λ�޸�(iΪ�޸�λ,emΪ�޸�ֵ)
void PrintSqList(SqList L);                         //��ӡ����

#endif