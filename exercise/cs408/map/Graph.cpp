#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

/**
 * 生成一个图
*/
AdjListGraph *createAdjListGraph()
{
  //给顶点结点们创建堆空间
  AdjListGraph *aGraph = (AdjListGraph *)malloc(sizeof(AdjListGraph));
  aGraph->vertextNum = VERTEX_NUM;
  aGraph->edgeNum = EDGE_NUM;

  //给每个边结点创建堆大小
  EdgeNode *edgeNode0To1 = (EdgeNode *)malloc(sizeof(EdgeNode));
  EdgeNode *edgeNode0To3 = (EdgeNode *)malloc(sizeof(EdgeNode));
  EdgeNode *edgeNode0To4 = (EdgeNode *)malloc(sizeof(EdgeNode));
  EdgeNode *edgeNode1To2 = (EdgeNode *)malloc(sizeof(EdgeNode));
  EdgeNode *edgeNode1To4 = (EdgeNode *)malloc(sizeof(EdgeNode));
  EdgeNode *edgeNode2To0 = (EdgeNode *)malloc(sizeof(EdgeNode));
  EdgeNode *edgeNode3To2 = (EdgeNode *)malloc(sizeof(EdgeNode));

  //边结点初始化
  edgeNode0To1->toAdjVex = 1;
  edgeNode0To1->next = edgeNode0To3;
  edgeNode0To3->toAdjVex = 3;
  edgeNode0To3->next = edgeNode0To4;
  edgeNode0To4->toAdjVex = 4;
  edgeNode0To4->next = NULL;

  edgeNode1To2->toAdjVex = 2;
  edgeNode1To2->next = edgeNode1To4;
  edgeNode1To4->toAdjVex = 4;
  edgeNode1To4->next = NULL;

  edgeNode2To0->toAdjVex = 0;
  edgeNode2To0->next = NULL;

  edgeNode3To2->toAdjVex = 2;
  edgeNode3To2->next = NULL;
  
  //链接顶点结点和第一个边结点
  (aGraph->adjList[0]).firstEdge = edgeNode0To1;
  (aGraph->adjList[0]).info = 'a';
  (aGraph->adjList[1]).firstEdge = edgeNode1To2;
  (aGraph->adjList[1]).info = 'b';
  (aGraph->adjList[2]).firstEdge = edgeNode2To0;
  (aGraph->adjList[2]).info = 'c';
  (aGraph->adjList[3]).firstEdge = edgeNode3To2;
  (aGraph->adjList[3]).info = 'd';
  (aGraph->adjList[4]).firstEdge = NULL;
  (aGraph->adjList[4]).info = 'e';

  return aGraph;
}
/**
 * 深度有限搜索
*/
void dfsRecursion(AdjListGraph *G, int startVertexIndex, bool visit[])
{
  printf("%c ", G->adjList[startVertexIndex].info);
  visit[startVertexIndex] = true;
  EdgeNode *tempNode = G->adjList[startVertexIndex].firstEdge;
  while (tempNode != NULL)
  {
    if (!visit[tempNode->toAdjVex])
      dfsRecursion(G, tempNode->toAdjVex, visit);
    tempNode = tempNode->next;
  }
}
