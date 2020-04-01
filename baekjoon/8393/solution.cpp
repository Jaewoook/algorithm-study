#include <iostream>

int main() {
    int max = 0, sum = 0;
    std::cin >> max;

    for (int i = 1; i <= max; i++) {
        sum += i;
    }
    std::cout << sum;
    return 0;
}
