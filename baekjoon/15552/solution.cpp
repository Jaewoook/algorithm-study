#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);

    int T = 0, a = 0, b = 0;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }
    return 0;
}
