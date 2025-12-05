#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "=== Binary Search Tree Traversal ===" << endl;
    cout << endl;
    
    address root = Nil;
    
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);
    
    cout << "InOrder Traversal (Left - Root - Right):" << endl;
    printInOrder(root);
    cout << endl << endl;
    
    cout << "PreOrder Traversal (Root - Left - Right):" << endl;
    printPreOrder(root);
    cout << endl << endl;
    
    cout << "PostOrder Traversal (Left - Right - Root):" << endl;
    printPostOrder(root);
    cout << endl;
    
    return 0;
}
