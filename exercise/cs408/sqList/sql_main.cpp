#include <bits/stdc++.h>
using namespace std;

#include "sql_meth.h"

int main()
{
  // Œﬁ–Ú≥ı ºÀ≥–Ú±Ì
  SqList list = {{2, 7, 0, 3, 4, 8, 8, 8, 3, 8, 5, 2, 1, 7, 0, 4, 5, 4, 6, 4, 6, 9, 5, 3, 0, 0, 5, 6, 1, 6}, 30};
  PrintSqList(list);
  inverse(list);
  PrintSqList(list);
  system("pause");
  return 0;
}