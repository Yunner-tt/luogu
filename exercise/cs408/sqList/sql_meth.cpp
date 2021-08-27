#include <bits/stdc++.h>
using namespace std;

#include "sql_meth.h"
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