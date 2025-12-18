#include "graph.h"
#include <stack>
#include <queue>

// Membuat graph kosong
void CreateGraph(Graph &G) {
    G.first = NULL;
}

// Alokasi node baru
adrNode AllocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

// Alokasi edge baru
adrEdge AllocateEdge(adrNode n) {
    adrEdge E = new ElmEdge;
    E->node = n;
    E->next = NULL;
    return E;
}

// Mencari node berdasarkan info
adrNode FindNode(Graph G, infoGraph x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// Insert node ke graph
void InsertNode(Graph &G, infoGraph x) {
    adrNode P = AllocateNode(x);
    
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

// Menghubungkan dua node (undirected graph)
void ConnectNode(Graph &G, infoGraph n1, infoGraph n2) {
    adrNode node1 = FindNode(G, n1);
    adrNode node2 = FindNode(G, n2);
    
    if (node1 != NULL && node2 != NULL) {
        // Tambah edge dari node1 ke node2
        adrEdge E1 = AllocateEdge(node2);
        if (node1->firstEdge == NULL) {
            node1->firstEdge = E1;
        } else {
            adrEdge temp = node1->firstEdge;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = E1;
        }
        
        // Tambah edge dari node2 ke node1 (karena undirected)
        adrEdge E2 = AllocateEdge(node1);
        if (node2->firstEdge == NULL) {
            node2->firstEdge = E2;
        } else {
            adrEdge temp = node2->firstEdge;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = E2;
        }
    }
}

// Menampilkan struktur graph
void PrintInfoGraph(Graph G) {
    cout << "\n=== Struktur Graph ===" << endl;
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "(tidak ada koneksi)";
        } else {
            while (E != NULL) {
                cout << E->node->info;
                if (E->next != NULL) cout << ", ";
                E = E->next;
            }
        }
        cout << endl;
        P = P->next;
    }
    cout << "======================" << endl;
}

// Reset flag visited semua node
void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

// Depth First Search (DFS) menggunakan Stack
void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }
    
    ResetVisited(G);
    stack<adrNode> S;
    
    cout << "DFS Traversal: ";
    S.push(N);
    
    while (!S.empty()) {
        adrNode current = S.top();
        S.pop();
        
        if (!current->visited) {
            current->visited = true;
            cout << current->info << " ";
            
            // Push semua neighbor yang belum dikunjungi
            adrEdge E = current->firstEdge;
            while (E != NULL) {
                if (!E->node->visited) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }
    cout << endl;
}

// Breadth First Search (BFS) menggunakan Queue
void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }
    
    ResetVisited(G);
    queue<adrNode> Q;
    
    cout << "BFS Traversal: ";
    Q.push(N);
    N->visited = true;
    
    while (!Q.empty()) {
        adrNode current = Q.front();
        Q.pop();
        
        cout << current->info << " ";
        
        // Enqueue semua neighbor yang belum dikunjungi
        adrEdge E = current->firstEdge;
        while (E != NULL) {
            if (!E->node->visited) {
                E->node->visited = true;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
    cout << endl;
}
