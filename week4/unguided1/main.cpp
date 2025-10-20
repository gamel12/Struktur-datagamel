#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    SinglyList L;
    int n;
    if (!(std::cin >> n)) return 0;
    for (int i = 0; i < n; ++i) {
        int v; std::cin >> v;
        L.push_front(v);
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    L.display();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    std::cout << "execution time : " << diff.count() << " s" << std::endl;
    return 0;
}
