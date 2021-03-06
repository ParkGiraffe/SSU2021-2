#pragma once

typedef struct  graphNode
{
    int id;
    graphNode *link;
} NODE_GRAPH;

const int MAX_VERTEX = 256;

class GraphByList
{
protected:
    int totalVertex;                // 정점의 개수
    char vertices[MAX_VERTEX];      // 정점 정보
    NODE_GRAPH* adj[MAX_VERTEX];    // 헤드포인터를 배열로 저장 - 각 정점의 인접리스트
public:
    GraphByList(void);
    ~GraphByList();

    void reset(void);
    bool isEmpty();
    bool isFull();
    char getVertex(int i);

    void insertVertex(char val);
    void insertEdge(int v1, int v2);

    void printGraph();

    NODE_GRAPH *adjacent(int v);
};
