#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

#define Nil NULL

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void printInOrder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

#endif
