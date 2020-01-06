#include <iostream>

int main() {
    int row = 0;
    std::cin >> row;

    for (int i = 1; i <= row; i++) {
        for (int j = 0; j < row; j++) {
            std::cout << (row - i <= j ? "*" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}
