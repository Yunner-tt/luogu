#include<bits/stdc++.h>
using namespace std;

#define MaxSize 30
#define ElemType int
//˳�������
typedef struct
{
   ElemType data[MaxSize];
   int length;
}SqList;
//˳���������
void InitList(SqList &L);                           //��ʼ��
bool Empty(SqList L);                               //�п�
bool ListInsert(SqList &L, int i, ElemType e);           //����
bool ListDelete(SqList &L, int i, ElemType &e);          //ɾ��
ElemType GetElem(SqList L, int i);                       //��λ����
int LocateElem(SqList L, ElemType e);                    //��ֵ����
bool LocateChangeElem(SqList &L, ElemType e, ElemType em);    //��ֵ�޸�(eΪ����ֵ��emΪ�޸�ֵ)
bool getChangeElem(SqList &L, int i, ElemType em);       //��λ�޸�(iΪ�޸�λ,emΪ�޸�ֵ)
void PrintSqList(SqList L);                         //��ӡ����
void testModule();                                  //����ģ��
//˳�������ʵ��
//��ʼ��
void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;//������Ԫ�صĳ�ʼֵĬ������Ϊ0
        //��һ����ʵ����ʡ�ԣ�����ʡ��֮���п����ܵ��ڴ���"������"��Ӱ��
    }
    L.length = 0;

}

//�п�
bool Empty(SqList L) {
    return (L.length == 0);
}

//����
bool ListInsert(SqList &L, int i, ElemType e) {
    //�жϲ����λ���Ƿ�Ϸ���
    if (i < 1 || i > L.length + 1)
        return false;
    //�жϱ��Ƿ������
    if (L.length >= MaxSize)
        return false;

    //�����Ԫ�غ���
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//ɾ��
bool ListDelete(SqList &L, int i, ElemType &e) {
    //�ж�i��λ���Ƿ�Ϸ�
    if (i < 0 || i > L.length) {
        return false;
    }
    //ȡ����Ҫ��ɾ������
    e = L.data[i - 1];
    //����������ǰ��
    for (int j = i; j <= L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    //���Ա��ȼ�һ
    L.length--;
    return true;
}

//����
//��λ����
ElemType GetElem(SqList L, int i) {
    //�ж��Ƿ�Խ��
    if (i < 0 || i > L.length)
        return -1;
    return L.data[i - 1];
}

//��ֵ����
int LocateElem(SqList L, int e) {
    //ѭ��������
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1; //����λ��
    }
    return -1;
}

//��
//�Ȳ��Һ��ֵ
//�ɴ˷�Ϊ���ַ�ʽ���Ȱ�λ���Һ��ֵ�����Ȱ�ֵ���Һ��ֵ
//�Ȱ�ֵ���Һ��ֵ
bool LocateChangeElem(SqList &L, ElemType e, ElemType em) {
    //��ֵ���ҵõ�λ��
    int bitOrder = LocateElem(L, e);
    //��ֵ
    if (bitOrder != -1) {
        L.data[bitOrder] = em;
        return true;
    } else {
        return false;
    }
}

//�Ȱ�λ����Һ��ֵ
bool getChangeElem(SqList &L, int i, ElemType em) {
    //ע�������Ǹ�ֵ�漰�޸�ԭ���ݣ�������Ҫ�����ô��ݵķ�ʽ
    //����λ��,�����ж�i�Ƿ�Ϸ�
    if (i < 0 || i >= L.length)return false;

    //������������ʵ�ֵķ�ʽ������ֱ������i����
    L.data[i] = em;
    return true;

}

//��ӡ����˳���(ֻ�������Int�Ĵ�ӡ)
void PrintSqList(SqList L) {
    //ѭ����ӡ
    printf("��ʼ��ӡ˳���[");
    for (int i = 0; i < L.length; i++) {
        printf(" %d,", L.data[i]);
    }
    printf("]��ӡ������\n");
}
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
//��������
/**����ģ��**/
typedef struct LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkList;

//��������
bool InitList(LinkList &L);     //��ʼ��
bool Empty(LinkList L);         //�̿�
bool ListInsert(LinkList &L, int i, ElemType e);//��λ����
bool InsertNextNode(LNode *p, ElemType e);//ָ���ڵ�ĺ�����
bool InsertPriorNode(LNode *p, ElemType e);//ָ���ڵ��ǰ�����������������ɺ�壬�ٽ���������ʵ��ǰ��
bool ListDelete(LinkList &L, int i, ElemType &e);//��ָ��λ��ɾ���ڵ㲢������ֵ
bool DeleteNode(LNode *p);//ɾ��ָ���ڵ�
/**����ģ��**/


/**ʵ��ģ��**/
//���Ի�(����ͷ�ڵ�)
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));//����һ��ͷ�ڵ�
    if (L == NULL)
        return false;//ͷ�ڵ����ʧ�ܣ��������ڴ治��
    L->next = NULL;//ͷ�ڵ�֮����ʱû�нڵ㣬ͷ�ڵ�Ҳ���������
    return true;
}

//�п�
bool Empty(LinkList L) {
//    if(L->next==NULL)
//        return true;
//    else
//        return false;
    return (L->next == NULL);
}

//��λ����
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)return false;//�ж�λ��i�Ƿ�Ϸ�
    LNode *p;//ָ��ָ��ǰɨ�浽�Ľڵ�
    int j = 0;//��¼pָ��Ľڵ��λ��
    p = L;//Lָ��ͷ�ڵ㣬��ͷ��ʼ
    while (p != NULL && j < i - 1) {
        //ѭ��ɨ��
        p = p->next;
        j++;
    }
    if (p == NULL) //iֵ�������������Ϸ�
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    //�����˳�򲻿ɽ���
    s->next = p->next;
    p->next = s;
    return true;
}

//ָ���ڵ�ĺ�����
bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;//�ж�ָ���ڵ��Ƿ����
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL)return false;//�����ڴ�ʧ��
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//ָ���ڵ��ǰ�����
//����ɺ�壬�ٽ���������ʵ��ǰ��
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

//��ָ��λ��ɾ���ڵ㲢������ֵ
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

//ɾ��ָ���ڵ�
bool DeleteNode(LNode *p) {
    return false;
}

//��ӡ��������(ֻ�����������)
void PrintLinkList(LinkList L) {
    //ѭ����ӡ��������
    LNode *p = L->next;//ɨ��ָ��
    int j = 0;
    if (p == NULL){
        printf("����һ���ձ�\n");
        return ;
    }
    printf("������[");
    while (p != NULL) {
        printf(" %d,", p->data);
        p = p->next;
    }
    printf("]��������");

}

/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/
/***************************************************************************************************/

/**ʵ��ģ��**/

typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

//��������
void InitStack(SqStack &S);//��ʼ��
bool Push(SqStack &S, int t);//��ջ
bool Pop(SqStack &S, int &x);//��ջ,����ӡ��ջ��Ԫ��
bool GetTop(SqStack S, int &x);//��ȡջ��Ԫ��
int GetTopOther(SqStack S);//��ȡջ��Ԫ�صĵڶ���ʵ�ַ�ʽ
/**����ģ��**/

/**ʵ��ģ��**/

//��ʼ��
void InitStack(SqStack &S) {
    S.top = -1;//���ֳ�ʼ���ķ�ʽ��ջ��ָ��ʼ��ָ��ջ��Ԫ��
}

//��ջ
bool Push(SqStack &S, int t) {
    if (S.top == MaxSize - 1)return false;//ջ��
    S.data[++S.top] = t;
//    �ȼ������������
//    S.top+=1;//�Ƚ�ջ��ָ��ָ����һ��λ��
//    S.data[S.top]=t;//�����Ԫ��
    return true;
}

//��ջ,����ӡ��ջ��Ԫ��
bool Pop(SqStack &S, int &x) {
    //�ж�
    if (S.top == -1)return false;//ջ�ձ���
    x = S.data[S.top--];
//    �ȼ�������
//    x=S.data[S.top];//��ȡԪ��
//    S.top -=1;//�ٸ�ָ��
    return true;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack S, int &x) {
    if (S.top == -1)return false;
    x = S.data[S.top];
    return true;
}

//��ȡջ��Ԫ�صĵڶ���ʵ�ַ�ʽ
//���÷���ֵ����ջ��Ԫ�أ����ɹ��ͷ���ջ��Ԫ�أ�ʧ�ܾͷ���-1��
//ȱ�㣺���ջ��Ԫ�ؾ���-1������������У���������ȱ�㣬������Կ���������д���ַ�ʽӦ���ǻᱻ�۲��ַ�����
int GetTopOther(SqStack S) {
    if (S.top == -1)return -1;
    return S.data[S.top];
}

//��ӡ����ջ
void PrintStack(SqStack S) {
    printf("��ջ��Ԫ�ؿ�ʼ��ջ���£�[");
    while (S.top >= 0) {//ע���пյ�����
        printf(" %d,", S.data[S.top]);
        S.top--;
    }
    printf("]ջ��ӡ���\n");
}
/**ʵ��ģ��**/

//˳���ת��
void inverse(SqList& L){
    int low = 0, height = L.length-1;
    while(low < height){
        int temp = L.data[low];
        L.data[low] = L.data[height];
        L.data[height] = temp;
        low++;height--;
    }
}
//����ת��
void inverse(SqList& L, int from, int to){
    int low = from-1, height = to-1;
    while(low < height){
        int temp = L.data[low];
        L.data[low] = L.data[height];
        L.data[height] = temp;
        low++;height--;
    }
}
//ɾ������˳�����Ԫ����ָ����Χ����
void delet_1(SqList& L, int from, int to){
    int acc = 0;
    for(int i=0;i<L.length;++i){
        if(L.data[i]>=from&&L.data[i]<=to) acc++;
        else if(acc != 0) L.data[i-acc] = L.data[i];
    }
    L.length = L.length - acc;
}



int main(){
    
    // �����ʼ˳���
    SqList list = {{2,7,0,3,4,8,8,8,3,8,5,2,1,7,0,4,5,4,6,4,6,9,5,3,0,0,5,6,1,6},30};
    // �����ʼ������
    LinkList Llist;InitList(Llist);InsertNextNode(Llist,5);InsertNextNode(Llist,3);InsertNextNode(Llist,4);InsertNextNode(Llist,2);InsertNextNode(Llist,1);
    // ת�� ��
    // PrintSqList(list);
    // inverse(list);
    // PrintSqList(list);
    // ��������λ�� ��
    PrintSqList(list);
    inverse(list,1,15);
    inverse(list,16,30);
    inverse(list,1,30);
    PrintSqList(list);
    // ɾ��ָ����Χ������ ��
    // PrintSqList(list);
    // delet_1(list,8,8);
    // PrintSqList(list);


    system("pause");
    return 0;
}