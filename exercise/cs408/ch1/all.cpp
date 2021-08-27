#include<bits/stdc++.h>
using namespace std;

#define MaxSize 30
#define ElemType int
//顺序表声明
typedef struct
{
   ElemType data[MaxSize];
   int length;
}SqList;
//顺序表函数声明
void InitList(SqList &L);                           //初始化
bool Empty(SqList L);                               //判空
bool ListInsert(SqList &L, int i, ElemType e);           //插入
bool ListDelete(SqList &L, int i, ElemType &e);          //删除
ElemType GetElem(SqList L, int i);                       //按位查找
int LocateElem(SqList L, ElemType e);                    //按值查找
bool LocateChangeElem(SqList &L, ElemType e, ElemType em);    //按值修改(e为查找值，em为修改值)
bool getChangeElem(SqList &L, int i, ElemType em);       //按位修改(i为修改位,em为修改值)
void PrintSqList(SqList L);                         //打印函数
void testModule();                                  //测试模块
//顺序表函数的实现
//初始化
void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;//将所有元素的初始值默认设置为0
        //这一步其实可以省略，但是省略之后，有可能受到内存中"脏数据"的影响
    }
    L.length = 0;

}

//判空
bool Empty(SqList L) {
    return (L.length == 0);
}

//插入
bool ListInsert(SqList &L, int i, ElemType e) {
    //判断插入的位置是否合法，
    if (i < 1 || i > L.length + 1)
        return false;
    //判断表是否存满了
    if (L.length >= MaxSize)
        return false;

    //后面的元素后移
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//删除
bool ListDelete(SqList &L, int i, ElemType &e) {
    //判断i的位置是否合法
    if (i < 0 || i > L.length) {
        return false;
    }
    //取出将要被删除的数
    e = L.data[i - 1];
    //将其后的数据前移
    for (int j = i; j <= L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    //线性表长度减一
    L.length--;
    return true;
}

//查找
//按位查找
ElemType GetElem(SqList L, int i) {
    //判断是否越界
    if (i < 0 || i > L.length)
        return -1;
    return L.data[i - 1];
}

//按值查找
int LocateElem(SqList L, int e) {
    //循环出查找
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1; //返回位序
    }
    return -1;
}

//改
//先查找后改值
//由此分为两种方式，先按位查找后改值；或先按值查找后改值
//先按值查找后改值
bool LocateChangeElem(SqList &L, ElemType e, ElemType em) {
    //按值查找得到位序
    int bitOrder = LocateElem(L, e);
    //改值
    if (bitOrder != -1) {
        L.data[bitOrder] = em;
        return true;
    } else {
        return false;
    }
}

//先按位序查找后改值
bool getChangeElem(SqList &L, int i, ElemType em) {
    //注意由于是改值涉及修改原数据，所以需要用引用传递的方式
    //给的位序,首先判断i是否合法
    if (i < 0 || i >= L.length)return false;

    //由于是用数组实现的方式，可以直接利用i查找
    L.data[i] = em;
    return true;

}

//打印整个顺序表(只针对整形Int的打印)
void PrintSqList(SqList L) {
    //循环打印
    printf("开始打印顺序表：[");
    for (int i = 0; i < L.length; i++) {
        printf(" %d,", L.data[i]);
    }
    printf("]打印结束！\n");
}
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
//单链表定义
/**定义模块**/
typedef struct LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkList;

//函数定义
bool InitList(LinkList &L);     //初始化
bool Empty(LinkList L);         //盘空
bool ListInsert(LinkList &L, int i, ElemType e);//按位插入
bool InsertNextNode(LNode *p, ElemType e);//指定节点的后插操作
bool InsertPriorNode(LNode *p, ElemType e);//指定节点的前插操作————先完成后插，再交换数据以实现前插
bool ListDelete(LinkList &L, int i, ElemType &e);//按指定位序删除节点并返回其值
bool DeleteNode(LNode *p);//删除指定节点
/**定义模块**/


/**实现模块**/
//初试化(带有头节点)
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));//分配一个头节点
    if (L == NULL)
        return false;//头节点分配失败，可能是内存不足
    L->next = NULL;//头节点之后暂时没有节点，头节点也不存放数据
    return true;
}

//判空
bool Empty(LinkList L) {
//    if(L->next==NULL)
//        return true;
//    else
//        return false;
    return (L->next == NULL);
}

//按位插入
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)return false;//判断位序i是否合法
    LNode *p;//指针指向当前扫面到的节点
    int j = 0;//记录p指向的节点的位序
    p = L;//L指向头节点，从头开始
    while (p != NULL && j < i - 1) {
        //循环扫描
        p = p->next;
        j++;
    }
    if (p == NULL) //i值超过来表长，不合法
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    //下面的顺序不可交换
    s->next = p->next;
    p->next = s;
    return true;
}

//指定节点的后插操作
bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;//判断指定节点是否存在
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL)return false;//分配内存失败
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//指定节点的前插操作
//先完成后插，再交换数据以实现前插
bool InsertPriorNode(LNode *p, ElemType e) {
    if (p == NULL)return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL)return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//按指定位序删除节点并返回其值
bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1)return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//删除指定节点
bool DeleteNode(LNode *p) {
    return false;
}

//打印整个链表(只针对整型数据)
void PrintLinkList(LinkList L) {
    //循环打印整个链表
    LNode *p = L->next;//扫描指针
    int j = 0;
    if (p == NULL){
        printf("这是一个空表\n");
        return ;
    }
    printf("单链表：[");
    while (p != NULL) {
        printf(" %d,", p->data);
        p = p->next;
    }
    printf("]遍历结束");

}

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/

/**实现模块**/

typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

//函数声明
void InitStack(SqStack &S);//初始化
bool Push(SqStack &S, int t);//入栈
bool Pop(SqStack &S, int &x);//出栈,并打印出栈顶元素
bool GetTop(SqStack S, int &x);//读取栈顶元素
int GetTopOther(SqStack S);//读取栈顶元素的第二种实现方式
/**定义模块**/

/**实现模块**/

//初始化
void InitStack(SqStack &S) {
    S.top = -1;//这种初始化的方式，栈顶指针始终指向栈顶元素
}

//入栈
bool Push(SqStack &S, int t) {
    if (S.top == MaxSize - 1)return false;//栈满
    S.data[++S.top] = t;
//    等价下面两个语句
//    S.top+=1;//先将栈顶指针指向下一个位置
//    S.data[S.top]=t;//再填充元素
    return true;
}

//出栈,并打印出栈顶元素
bool Pop(SqStack &S, int &x) {
    //判断
    if (S.top == -1)return false;//栈空报错
    x = S.data[S.top--];
//    等价于下面
//    x=S.data[S.top];//先取元素
//    S.top -=1;//再改指针
    return true;
}

//读取栈顶元素
bool GetTop(SqStack S, int &x) {
    if (S.top == -1)return false;
    x = S.data[S.top];
    return true;
}

//读取栈顶元素的第二种实现方式
//利用返回值返回栈顶元素，若成功就返回栈顶元素，失败就返回-1；
//缺点：如果栈顶元素就是-1，容易造成误判，正因它的缺点，如果考试考到了它，写这种方式应该是会被扣部分分数的
int GetTopOther(SqStack S) {
    if (S.top == -1)return -1;
    return S.data[S.top];
}

//打印整个栈
void PrintStack(SqStack S) {
    printf("从栈顶元素开始，栈如下：[");
    while (S.top >= 0) {//注意判空的条件
        printf(" %d,", S.data[S.top]);
        S.top--;
    }
    printf("]栈打印完毕\n");
}
/**实现模块**/

//顺序表转置
void inverse(SqList& L){
    int low = 0, height = L.length-1;
    while(low < height){
        int temp = L.data[low];
        L.data[low] = L.data[height];
        L.data[height] = temp;
        low++;height--;
    }
}
//部分转置
void inverse(SqList& L, int from, int to){
    int low = from-1, height = to-1;
    while(low < height){
        int temp = L.data[low];
        L.data[low] = L.data[height];
        L.data[height] = temp;
        low++;height--;
    }
}
//删除无序顺序表中元素在指定范围的项
void delet_1(SqList& L, int from, int to){
    int acc = 0;
    for(int i=0;i<L.length;++i){
        if(L.data[i]>=from&&L.data[i]<=to) acc++;
        else if(acc != 0) L.data[i-acc] = L.data[i];
    }
    L.length = L.length - acc;
}



int main(){
    
    // 无序初始顺序表
    SqList list = {{2,7,0,3,4,8,8,8,3,8,5,2,1,7,0,4,5,4,6,4,6,9,5,3,0,0,5,6,1,6},30};
    // 无序初始单链表
    LinkList Llist;InitList(Llist);InsertNextNode(Llist,5);InsertNextNode(Llist,3);InsertNextNode(Llist,4);InsertNextNode(Llist,2);InsertNextNode(Llist,1);
    // 转置 √
    // PrintSqList(list);
    // inverse(list);
    // PrintSqList(list);
    // 交换部分位置 √
    PrintSqList(list);
    inverse(list,1,15);
    inverse(list,16,30);
    inverse(list,1,30);
    PrintSqList(list);
    // 删除指定范围数据项 √
    // PrintSqList(list);
    // delet_1(list,8,8);
    // PrintSqList(list);


    system("pause");
    return 0;
}