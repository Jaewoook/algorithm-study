#include <iostream>

int main() {
    int T = 0, x = 0, n = 1, m = 0, tmp = 0;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> x;
        for (int j = 0; j < x; j++) {
            tmp = n;
            n = m;
            m += tmp;
        }
        std::cout << n << " " << m << "\n";
        n = 1;
        m = 0;
    }

    return 0;
}
