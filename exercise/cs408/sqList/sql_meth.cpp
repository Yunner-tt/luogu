#include <bits/stdc++.h>
using namespace std;

#include "sql_meth.h"
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