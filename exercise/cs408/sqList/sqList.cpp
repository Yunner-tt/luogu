#include <bits/stdc++.h>
using namespace std;

#include "sqList.h"
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
Bool Empty(SqList L) {
    return (L.length == 0);
}

//����
Bool ListInsert(SqList &L, int i, ElemType e) {
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
Bool ListDelete(SqList &L, int i, ElemType &e) {
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
ElemType LocateElem(SqList L, int e) {
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
Bool LocateChangeElem(SqList &L, ElemType e, ElemType em) {
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
Bool getChangeElem(SqList &L, int i, ElemType em) {
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