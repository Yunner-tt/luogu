#ifndef _Map_h_
#define _Map_h_

#define VERTEX_NUM 5
#define EDGE_NUM 7

#define MAX_COST 65535

typedef char VERTEX_DATA_TYPE;

typedef struct EdgeNode
{
    int toAdjVex;                               // 该边结点对应顶点结点的数组下标
    float weight;                               // 顶点节点到该节点的权值
    struct EdgeNode *next;                      // 指向下一个与顶点节点相邻的边节点
} EdgeNode;
typedef struct VertexNodedsd
{
    VERTEX_DATA_TYPE info;                      // 顶点节点存储的信息
    EdgeNode* firstEdge;                        // 顶点节点指向的第一个边结点
} VertexNode;
typedef struct
{
    VertexNode adjList[VERTEX_NUM];             // 最大的顶点节点数量
    int vertextNum;                             // 当前存在的顶点结点数量
    int edgeNum;                                // 边结点的数量
} AdjListGraph;


AdjListGraph* createAdjListGraph();             // 生成一个图
void dfsRecursion(AdjListGraph* G, int startVertexIndex, bool visit[]);

#endif