#include <iostream>

int main() {
    int x = 0, col = 0, row = 0;
    std::cin >> x;

    for (int i = 1; x > 0; i++) {
        if (x - i <= 0) {
            row = i;
        }
        x -= i;
    }
    col = row + x;

    int m = 0, s = 0;

    if (row % 2 == 0) {
        m = row - col + 1;
        s = col;
    } else {
        m = col;
        s = row - col + 1;
    }

    std::cout << s << "/" << m << "\n";
    return 0;
}
