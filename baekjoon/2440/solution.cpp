#include <iostream>

int main() {
    int num = 0;
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        for (int j = num - i; j > 0; j--) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
