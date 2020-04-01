#include <iostream>

int main() {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;

    std::cout << (a + b) % c << std::endl <<
            (a % c + b % c) % c << std::endl <<
            (a * b) % c << std::endl <<
            ((a % c) * (b % c)) % c << std::endl;
    return 0;
}