#ifndef Sqlist_H
#define Sqlist_H

#define MaxSize 30
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} *LinkStack;

//��������
bool InitStack(LinkStack &LS);//��ʼ��
bool Push(LinkStack &LS, int t);//��ջ �ο�ͷ�巨����������
bool Pop(LinkStack &LS, int &x);//��ջ,����ӡ��ջ��Ԫ��
bool GetTop(LinkStack LS, int &x);//��ȡջ��Ԫ�أ�ջ


void InitStack(SqStack &S);//��ʼ��

bool Push(SqStack &S, ElemType t);//��ջ

bool Pop(SqStack &S, ElemType &x);//��ջ,����ӡ��ջ��Ԫ��

bool GetTop(SqStack S, ElemType &x);//��ȡջ��Ԫ��

ElemType GetTop(SqStack S);//��ȡջ��Ԫ�صĵڶ���ʵ�ַ�ʽ

void PrintStack(SqStack S);//��ӡ�������ջ��

#endif