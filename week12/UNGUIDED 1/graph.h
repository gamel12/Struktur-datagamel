#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Fungsi dan Prosedur
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph x);
adrEdge AllocateEdge(adrNode n);
void InsertNode(Graph &G, infoGraph x);
void ConnectNode(Graph &G, infoGraph n1, infoGraph n2);
adrNode FindNode(Graph G, infoGraph x);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);
void ResetVisited(Graph &G);

#endif
