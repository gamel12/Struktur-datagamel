#ifndef graph_h
#define graph_h

#include <iostream>
#include <string>

using namespace std;

struct Edge;

struct Node {
    char namaKota;
    bool isVisited;
    bool isIgnored; // Untuk simulasi lockdown
    Edge* firstEdge;
    Node* nextNode;
};

struct Edge {
    Node* destNode;
    Edge* nextEdge;
};

struct Graph {
    Node* firstNode;
};

void createGraph(Graph &G);
Node* alokasiNode(char nama);
void insertNode(Graph &G, char nama);
Node* findNode(Graph G, char nama);
void addEdge(Graph &G, char asal, char tujuan); // Undirected
void traversalDFS(Node* startNode, int &count);
void resetVisited(Graph &G);
void analisisKotaKritis(Graph &G);
void printGraph(Graph G);

#endif