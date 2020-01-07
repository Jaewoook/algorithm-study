#include <iostream>
#include <string>

int main() {
    int n = 0, a = 0, b = 0;
    std::string input;
    std::getline(std::cin, input);
    n = std::stoi(input);

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, input);
        a = input.at(0) - 48;
        b = input.at(2) - 48;
        std::cout << a + b << "\n";
    }

    return 0;
}
