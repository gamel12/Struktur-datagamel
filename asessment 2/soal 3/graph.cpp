#include <iostream>
#include <string>

using namespace std;

struct Edge {
    struct Node* destination;
    Edge* nextEdge;
};

struct Node {
    char name;
    bool isLockdown;
    bool visited;
    Edge* firstEdge;
    Node* nextNode;
};

struct Graph {
    Node* head;
    int nodeCount;

    Graph() {
        head = nullptr;
        nodeCount = 0;
    }

    void addNode(char name) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->isLockdown = false;
        newNode->visited = false;
        newNode->firstEdge = nullptr;
        newNode->nextNode = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->nextNode != nullptr) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
        }
        nodeCount++;
    }

    Node* findNode(char name) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) return temp;
            temp = temp->nextNode;
        }
        return nullptr;
    }

    void insertEdge(Node* u, Node* v) {
        Edge* newEdge = new Edge;
        newEdge->destination = v;
        newEdge->nextEdge = u->firstEdge;
        u->firstEdge = newEdge;
    }

    void addEdge(char src, char dest) {
        Node* u = findNode(src);
        Node* v = findNode(dest);
        if (u != nullptr && v != nullptr) {
            insertEdge(u, v);
            insertEdge(v, u);
        }
    }

    void resetVisited() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->visited = false;
            temp = temp->nextNode;
        }
    }

    void dfs(Node* current, int &count) {
        current->visited = true;
        count++;
        Edge* e = current->firstEdge;
        while (e != nullptr) {
            if (!e->destination->visited && !e->destination->isLockdown) {
                dfs(e->destination, count);
            }
            e = e->nextEdge;
        }
    }

    void analyze() {
        cout << "Membangun Jaringan Distribusi Vaksin" << endl;
        Node* curr = head;
        while (curr != nullptr) {
            cout << "Node " << curr->name << " terhubung ke: ";
            Edge* e = curr->firstEdge;
            while (e != nullptr) {
                cout << e->destination->name << " ";
                e = e->nextEdge;
            }
            cout << endl;
            curr = curr->nextNode;
        }

        cout << "\nAnalisis Kota Kritis (Single Point of Failure)" << endl;
        
        Node* testNode = head;
        while (testNode != nullptr) {
            testNode->isLockdown = true;
            resetVisited();

            Node* startNode = nullptr;
            Node* temp = head;
            while(temp != nullptr) {
                if(temp != testNode) {
                    startNode = temp;
                    break;
                }
                temp = temp->nextNode;
            }

            int reachCount = 0;
            if (startNode != nullptr) {
                dfs(startNode, reachCount);
            }

            if (reachCount < nodeCount - 1) {
                cout << "[PERINGATAN] Kota " << testNode->name << " adalah KOTA KRITIS!" << endl;
                cout << "-> Jika " << testNode->name << " lockdown, distribusi terputus." << endl;
            } else {
                cout << "Kota " << testNode->name << " aman (redundansi oke)." << endl;
            }

            testNode->isLockdown = false;
            testNode = testNode->nextNode;
        }
    }
};

int main() {
    Graph g;
    g.addNode('A');
    g.addNode('B');
    g.addNode('C');
    g.addNode('D');
    g.addNode('E');

    g.addEdge('A', 'B');
    g.addEdge('B', 'E');
    g.addEdge('B', 'C');
    g.addEdge('C', 'D');

    g.analyze();

    return 0;
}