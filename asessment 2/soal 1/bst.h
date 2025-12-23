#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left, *right;
};

extern Node *root;

void createTree();
bool isEmpty();
Node* newNode(string nama, float berat, string tier);
Node* insertRecursive(Node* curr, Node* nodeBaru);
void insertNode(string nama, float berat, string tier);
void inOrder(Node* curr);
void mostLeft();
void mostRight();
void searchByBeratBadan(Node* curr, Node* parent, float berat);