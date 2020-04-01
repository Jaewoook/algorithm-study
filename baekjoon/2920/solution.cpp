#include <iostream>

int main() {
    int n = 0, m = 0, far = 0, order = 0;

    for (int i = 0; i < 8; i++) {
        std::cin >> m;
        if (n > 0 && far == 0) {
            far = n - m;
            order = far < 0 ? -1 : -2;
        } else if (n > 0 && far != 0) {
            order = far + m != n ? -3 : order;
        }
        n = m;
    }

    std::cout << (order == -1 ? "ascending" : order == -2 ? "descending" : "mixed");
    return 0;
}
