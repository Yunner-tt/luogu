#ifndef _Sqlist_H_
#define _Sqlist_H_

#define MaxSize 30
#define ElemType int
#define Bool bool
//顺序表声明
typedef struct
{
   ElemType data[MaxSize];
   int length;
}SqList;
//顺序表函数声明
void InitList(SqList &L);                           //初始化
Bool Empty(SqList L);                               //判空
Bool ListInsert(SqList &L, int i, ElemType e);           //插入
Bool ListDelete(SqList &L, int i, ElemType &e);          //删除
ElemType GetElem(SqList L, int i);                       //按位查找
ElemType LocateElem(SqList L, ElemType e);                    //按值查找
Bool LocateChangeElem(SqList &L, ElemType e, ElemType em);    //按值修改(e为查找值，em为修改值)
Bool getChangeElem(SqList &L, int i, ElemType em);       //按位修改(i为修改位,em为修改值)
void PrintSqList(SqList L);                         //打印函数

#endif