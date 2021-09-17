#include<bits/stdc++.h>
using namespace std;

#include"Tree.h"

int main(){
  BiTree T;
  CreateBiTree(T);
  PreOrderTraverse(T);
  printf("\n");
  InOrderTraverse(T);
  printf("\n");
  levelOrder(T);
  printf("\n");
  system("pause");
  return 0;
}