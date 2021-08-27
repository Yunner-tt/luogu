#include <stdio.h>
#include <stdlib.h>

#include "sql.h"
int main()
{
	int *s;
	Sqlist La = {s,0,20};
	InitList_Sq(La);
	ListInsert_Sq(La, 1, 1);
	ListInsert_Sq(La, 2, 2);
	ListInsert_Sq(La, 3, 5);
	ListInsert_Sq(La, 4, 7);
	ListInsert_Sq(La, 5, 10);
	ListTraverse_Sq(La, visit_display_Sq);
	printf("\n");
  system("pause");
  return 0;
}