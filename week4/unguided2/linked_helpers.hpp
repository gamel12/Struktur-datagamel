#ifndef LINKED_HELPERS_HPP
#define LINKED_HELPERS_HPP

#include <iostream>

namespace linked {
    struct Node { int value; Node* next; Node(int v): value(v), next(nullptr) {} };
    struct List { Node* head; List(): head(nullptr) {} };

    void init(List &l);
    Node* make_node(int v);
    void add_front(List &l, Node* n);
    bool remove_front(List &l, Node* &out);
    bool remove_back(List &l, Node* &out);
    bool remove_after(List &l, Node* prev, Node* &out);
    void print(const List &l);
    int count(const List &l);
    void clear(List &l);
}

#endif
