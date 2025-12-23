#include "graph.h"

void createGraph(Graph &G) {
    G.firstNode = NULL;
}

Node* alokasiNode(char nama) {
    Node* P = new Node;
    P->namaKota = nama;
    P->isVisited = false;
    P->isIgnored = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, char nama) {
    Node* P = alokasiNode(nama);
    if (G.firstNode == NULL) {
        G.firstNode = P;
    } else {
        Node* last = G.firstNode;
        while (last->nextNode != NULL) last = last->nextNode;
        last->nextNode = P;
    }
}

Node* findNode(Graph G, char nama) {
    Node* curr = G.firstNode;
    while (curr != NULL) {
        if (curr->namaKota == nama) return curr;
        curr = curr->nextNode;
    }
    return NULL;
}

void addEdge(Graph &G, char asal, char tujuan) {
    Node* u = findNode(G, asal);
    Node* v = findNode(G, tujuan);
    if (u != NULL && v != NULL) {
        // Edge u -> v
        Edge* e1 = new Edge;
        e1->destNode = v;
        e1->nextEdge = u->firstEdge;
        u->firstEdge = e1;
        // Edge v -> u (Undirected)
        Edge* e2 = new Edge;
        e2->destNode = u;
        e2->nextEdge = v->firstEdge;
        v->firstEdge = e2;
    }
}

void traversalDFS(Node* v, int &count) {
    v->isVisited = true;
    count++;
    Edge* e = v->firstEdge;
    while (e != NULL) {
        if (!e->destNode->isVisited && !e->destNode->isIgnored) {
            traversalDFS(e->destNode, count);
        }
        e = e->nextEdge;
    }
}

void resetVisited(Graph &G) {
    Node* curr = G.firstNode;
    while (curr != NULL) {
        curr->isVisited = false;
        curr = curr->nextNode;
    }
}

void printGraph(Graph G) {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    Node* curr = G.firstNode;
    while (curr != NULL) {
        cout << "Node " << curr->namaKota << " terhubung ke: ";
        Edge* e = curr->firstEdge;
        while (e != NULL) {
            cout << e->destNode->namaKota << " ";
            e = e->nextEdge;
        }
        cout << endl;
        curr = curr->nextNode;
    }
}

void analisisKotaKritis(Graph &G) {
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)" << endl;
    
    // Hitung total kota awal
    int totalKota = 0;
    Node* temp = G.firstNode;
    while (temp != NULL) { totalKota++; temp = temp->nextNode; }

    Node* target = G.firstNode;
    while (target != NULL) {
        target->isIgnored = true; // Simulasi Lockdown
        resetVisited(G);
        
        int reachCount = 0;
        // Cari start node yang bukan target
        Node* startNode = (target == G.firstNode) ? G.firstNode->nextNode : G.firstNode;
        
        if (startNode != NULL) {
            traversalDFS(startNode, reachCount);
        }

        // Jika kota yang terjangkau < total - 1, maka kritis
        if (reachCount < totalKota - 1) {
            cout << "[PERINGATAN] Kota " << target->namaKota << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << target->namaKota << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << target->namaKota << " aman (redundansi oke)." << endl;
        }

        target->isIgnored = false; // Akhiri simulasi lockdown
        target = target->nextNode;
    }
}

int main() {
    Graph G;
    createGraph(G);

    // Inisialisasi Node
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');

    // Inisialisasi Edge sesuai gambar output
    addEdge(G, 'A', 'B');
    addEdge(G, 'B', 'C');
    addEdge(G, 'B', 'E');
    addEdge(G, 'C', 'D');

    printGraph(G);
    analisisKotaKritis(G);

    return 0;
}