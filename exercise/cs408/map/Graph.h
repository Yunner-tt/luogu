#ifndef _Map_h_
#define _Map_h_

#define VERTEX_NUM 5
#define EDGE_NUM 7

#define MAX_COST 65535

typedef char VERTEX_DATA_TYPE;

typedef struct EdgeNode
{
    int toAdjVex;                               // �ñ߽���Ӧ������������±�
    float weight;                               // ����ڵ㵽�ýڵ��Ȩֵ
    struct EdgeNode *next;                      // ָ����һ���붥��ڵ����ڵı߽ڵ�
} EdgeNode;
typedef struct VertexNodedsd
{
    VERTEX_DATA_TYPE info;                      // ����ڵ�洢����Ϣ
    EdgeNode* firstEdge;                        // ����ڵ�ָ��ĵ�һ���߽��
} VertexNode;
typedef struct
{
    VertexNode adjList[VERTEX_NUM];             // ���Ķ���ڵ�����
    int vertextNum;                             // ��ǰ���ڵĶ���������
    int edgeNum;                                // �߽�������
} AdjListGraph;


AdjListGraph* createAdjListGraph();             // ����һ��ͼ
void dfsRecursion(AdjListGraph* G, int startVertexIndex, bool visit[]);

#endif