#include <iostream>

int main() {
    int row = 0, a = 0, b = 0;
    std::cin >> row;

    for (int i = 1; i <= row; i++) {
        std::cin >> a >> b;
        std::cout << "Case #" << i << ": " << a + b << "\n";
    }
}
