#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
void printGraph()
{
  printf("-----------> c <----------\n");
  printf("|            |           |\n");
  printf("|            |           |\n");
  printf("|            V           |\n");
  printf("b <--------- a --------> d\n");
  printf("|            |            \n");
  printf("|            |            \n");
  printf("|            V            \n");
  printf("-----------> e\n");
}
void clearVisitFlag(bool visit[])
{
  for (int i = 0; i < VERTEX_NUM; i++)
  {
    visit[i] = false;
  }
}
int main()
{
  printGraph();
  AdjListGraph *graph0 = createAdjListGraph();
  bool visit[VERTEX_NUM];
  clearVisitFlag(visit);
  dfsRecursion(graph0,0,visit);
  system("pause");
  return 0;
}