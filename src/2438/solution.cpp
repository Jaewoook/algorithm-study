#include <iostream>

int main() {
    int row = 0;
    std::cin >> row;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
