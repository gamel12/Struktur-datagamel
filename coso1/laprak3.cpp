#include <iostream>
int main() {
    int n;
    std::cout << "input: ";
    std::cin >> n;
    std::cout << "output:" << std::endl;
    for (int i = n; i >= 1; --i) {
        for (int s = 0; s < (n - i); ++s) {
            std::cout << "  "; 
        }
        for (int j = i; j >= 1; --j) {
            std::cout << j << " ";
        }
        std::cout << "* ";
        for (int j = 1; j <= i; ++j) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    for (int s = 0; s < n; ++s) {
        std::cout << "  ";
    }
    std::cout << "*" << std::endl;
    return 0;
}