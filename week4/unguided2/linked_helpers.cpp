#include "linked_helpers.hpp"

namespace linked {

void init(List &l) { l.head = nullptr; }

Node* make_node(int v) { return new Node(v); }

void add_front(List &l, Node* n) {
    if (!n) return;
    n->next = l.head;
    l.head = n;
}

bool remove_front(List &l, Node* &out) {
    if (!l.head) return false;
    out = l.head;
    l.head = l.head->next;
    out->next = nullptr;
    return true;
}

bool remove_back(List &l, Node* &out) {
    if (!l.head) return false;
    if (!l.head->next) {
        out = l.head;
        l.head = nullptr;
        out->next = nullptr;
        return true;
    }
    Node* p = l.head;
    while (p->next && p->next->next) p = p->next;
    out = p->next;
    p->next = nullptr;
    out->next = nullptr;
    return true;
}

bool remove_after(List &l, Node* prev, Node* &out) {
    if (!prev || !prev->next) return false;
    out = prev->next;
    prev->next = out->next;
    out->next = nullptr;
    return true;
}

void print(const List &l) {
    Node* p = l.head;
    while (p) {
        std::cout << p->value;
        if (p->next) std::cout << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int count(const List &l) {
    int c = 0;
    Node* p = l.head;
    while (p) { ++c; p = p->next; }
    return c;
}

void clear(List &l) {
    Node* p = l.head;
    while (p) {
        Node* next = p->next;
        delete p;
        p = next;
    }
    l.head = nullptr;
}

} // namespace linked
