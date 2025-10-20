#include "linked_list.hpp"

SinglyList::SinglyList() : head(nullptr) {}

SinglyList::~SinglyList() {
    Node* p = head;
    while (p) {
        Node* n = p->next;
        delete p;
        p = n;
    }
}

void SinglyList::push_front(value_type v) {
    Node* n = new Node(v);
    n->next = head;
    head = n;
}

void SinglyList::display() const {
    Node* p = head;
    while (p) {
        std::cout << p->value;
        if (p->next) std::cout << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
