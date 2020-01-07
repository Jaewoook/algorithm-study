#include <iostream>

int main() {
    int a = 0, b = 0;
    while (1) {
        std::cin >> a >> b;
        if (a != 0 && b != 0) {
            std::cout << a + b << "\n";
        } else {
            break;
        }
    }
    return 0;
}
