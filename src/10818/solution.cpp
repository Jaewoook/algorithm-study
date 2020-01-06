#include <iostream>

int main() {
    int count = 0, n = 0, min = 1000000, max = -1000000;
    std::cin >> count;
    for (int i = 0; i < count; i++) {
        std::cin >> n;
        min = n < min ? n : min;
        max = n > max ? n : max;
    }
    std::cout << min << " " << max;

    return 0;
}
