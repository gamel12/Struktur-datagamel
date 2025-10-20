#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

class SinglyList {
public:
    struct Node { int value; Node* next; Node(int v): value(v), next(nullptr) {} };
    using value_type = int;

    SinglyList();
    ~SinglyList();
    void push_front(value_type v);
    void display() const;
private:
    Node* head;
    // non-copyable
    SinglyList(const SinglyList&) = delete;
    SinglyList& operator=(const SinglyList&) = delete;
};

#endif
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

class SinglyList {
public:
    using value_type = int;
    SinglyList();
    ~SinglyList();
    void push_front(value_type v);
    void display() const;
private:
    struct Node { value_type val; Node* next; Node(value_type v): val(v), next(nullptr) {} };
    Node* head;
    SinglyList(const SinglyList&) = delete;
    SinglyList& operator=(const SinglyList&) = delete;
};

#endif
