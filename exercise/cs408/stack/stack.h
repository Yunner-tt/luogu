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

//函数声明
bool InitStack(LinkStack &LS);//初始化
bool Push(LinkStack &LS, int t);//入栈 参考头插法建立单链表
bool Pop(LinkStack &LS, int &x);//出栈,并打印出栈顶元素
bool GetTop(LinkStack LS, int &x);//读取栈顶元素，栈


void InitStack(SqStack &S);//初始化

bool Push(SqStack &S, ElemType t);//入栈

bool Pop(SqStack &S, ElemType &x);//出栈,并打印出栈顶元素

bool GetTop(SqStack S, ElemType &x);//读取栈顶元素

ElemType GetTop(SqStack S);//读取栈顶元素的第二种实现方式

void PrintStack(SqStack S);//打印输出整个栈区

#endif