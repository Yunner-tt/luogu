#include <bits/stdc++.h>
#include "string.h"
using namespace std;

int main()
{
  String S, T;
  InitStr(S);
  InitStr(T);
  char str1[] = "kim";
  char str2[] = "kimYang";
  StrAssign(S, str1, 3);
  PrintString(S,"S");
  StrAssign(T, str2, 7);
  PrintString(T,"T");
  system("pause");
  return 0;
}