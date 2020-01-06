#include <iostream>

int main() {
    int max = 0, n = 0, idx = 0;
    for (int i = 0; i < 9; i++) {
        std::cin >> n;
        if (max < n) {
            max = n;
            idx = i;
        }
    }
    std::cout << max << "\n" << idx + 1 << "\n";
    return 0;
}
