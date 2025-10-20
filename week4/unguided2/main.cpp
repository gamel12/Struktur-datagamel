#include <iostream>
#include "linked_helpers.hpp"

int main() {
    linked::List L;
    linked::init(L);

    int data[] = {9,12,8,0,2};
    for (int v : data) linked::add_front(L, linked::make_node(v));

    linked::print(L);

    linked::Node* tmp = nullptr;
    linked::remove_front(L, tmp);
    delete tmp;
    linked::print(L);

    linked::remove_back(L, tmp);
    delete tmp;
    linked::print(L);

    if (L.head && L.head->next) {
        linked::remove_after(L, L.head, tmp);
        delete tmp;
    }
    linked::print(L);

    std::cout << "Jumlah node : " << linked::count(L) << std::endl;

    linked::clear(L);
    std::cout << "- List Berhasil Terhapus -" << std::endl;
    std::cout << "Jumlah node : " << linked::count(L) << std::endl;

    return 0;
}
