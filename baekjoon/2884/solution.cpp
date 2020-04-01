#include <iostream>

int main() {
    int h = 0, m = 0, H = 0, M = 0;
    std::cin >> h >> m;

    H = h;
    if (m < 45) {
        M = 60 + m - 45;
        H = H == 0 ? 23 : h - 1;
    } else {
        M = m - 45;
    }
    std::cout << H << " " << M << std::endl;

    return 0;
}
