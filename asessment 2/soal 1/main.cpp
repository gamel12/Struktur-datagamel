#include "bst.h"
Node *root;
void createTree() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* nodeBaru = new Node();
    nodeBaru->namaMember = nama;
    nodeBaru->beratBadan = berat;
    nodeBaru->tierMember = tier;
    nodeBaru->left = nodeBaru->right = NULL;
    return nodeBaru;
}

Node* insertRecursive(Node* curr, Node* nodeBaru) {
    if (curr == NULL) return nodeBaru;
    if (nodeBaru->beratBadan < curr->beratBadan)
        curr->left = insertRecursive(curr->left, nodeBaru);
    else if (nodeBaru->beratBadan > curr->beratBadan)
        curr->right = insertRecursive(curr->right, nodeBaru);
    return curr;
}

void insertNode(string nama, float berat, string tier) {
    Node* nodeBaru = newNode(nama, berat, tier);
    root = insertRecursive(root, nodeBaru);
}

void inOrder(Node* curr) {
    if (curr != NULL) {
        inOrder(curr->left);
        cout << curr->beratBadan << " - ";
        inOrder(curr->right);
    }
}

void mostLeft() {
    if (isEmpty()) return;
    Node* curr = root;
    while (curr->left != NULL) curr = curr->left;
    cout << "Node MostLeft : " << curr->beratBadan << endl;
}

void mostRight() {
    if (isEmpty()) return;
    Node* curr = root;
    while (curr->right != NULL) curr = curr->right;
    cout << "Node MostRight : " << curr->beratBadan << endl;
}

void searchByBeratBadan(Node* curr, Node* parent, float berat) {
    if (curr == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }
    if (curr->beratBadan == berat) {
        cout << "Data ditemukan didalam BST!" << endl;
        cout << "--- Data Node Yang Dicari ---" << endl;
        cout << "Nama Member : " << curr->namaMember << endl;
        cout << "Berat Badan : " << curr->beratBadan << endl;
        cout << "Tier Member : " << curr->tierMember << endl;
        cout << "-----------------------------" << endl;
        cout << "--- Data Parent ---" << endl;
        if (parent != NULL) {
            cout << "Nama Member : " << parent->namaMember << endl;
            cout << "Berat Badan : " << parent->beratBadan << endl;
            cout << "Tier Member : " << parent->tierMember << endl;
        } else {
            cout << "Tidak Memiliki Parent" << endl;
        }
        cout << "-----------------------------" << endl;
        if (parent != NULL) {
            Node* sibling = (parent->left == curr) ? parent->right : parent->left;
            if (sibling != NULL) cout << "Nama Sibling : " << sibling->namaMember << endl;
            else cout << "Tidak Memiliki Sibling" << endl;
        } else {
             cout << "Tidak Memiliki Sibling" << endl;
        }
        cout << "-----------------------------" << endl;
        cout << "--- Data Child Kiri ---" << endl;
        if (curr->left != NULL) {
            cout << "Nama Member : " << curr->left->namaMember << endl;
            cout << "Berat Badan : " << curr->left->beratBadan << endl;
            cout << "Tier Member : " << curr->left->tierMember << endl;
        } else {
            cout << "Tidak Memiliki Child Kiri" << endl;
        }
        cout << "-----------------------------" << endl;
        cout << "--- Data Child Kanan ---" << endl;
        if (curr->right != NULL) {
            cout << "Nama Member : " << curr->right->namaMember << endl;
            cout << "Berat Badan : " << curr->right->beratBadan << endl;
            cout << "Tier Member : " << curr->right->tierMember << endl;
        } else {
            cout << "Tidak Memiliki Child Kanan" << endl;
        }
        cout << "-----------------------------" << endl;
    } 
    else if (berat < curr->beratBadan) searchByBeratBadan(curr->left, curr, berat);
    else searchByBeratBadan(curr->right, curr, berat);
}

int main() {
    createTree();
    insertNode("Rizkina Azizah", 60, "Basic");
    insertNode("Hakan Ismail", 50, "Bronze");
    insertNode("Olivia Saevali", 65, "Silver");
    insertNode("Felix Pedrosa", 47, "Gold");
    insertNode("Gamel Al Ghifari", 56, "Platinum");
    insertNode("Hanif Al Faiz", 70, "Basic");
    insertNode("Mutiara Fauziah", 52, "Bronze");
    insertNode("Davi Ilyas", 68, "Silver");
    insertNode("Abdad Mubarok", 81, "Gold");

    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << endl << endl;

    mostLeft();
    mostRight();
    cout << endl;

    searchByBeratBadan(root, NULL, 70);

    return 0;
}