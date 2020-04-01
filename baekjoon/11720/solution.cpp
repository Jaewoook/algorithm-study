#include <iostream>
#include <string>

int main() {
    int n = 0, sum = 0;
    std::string input;
    std::getline(std::cin, input);

    n = std::stoi(input);

    std::getline(std::cin, input);
    for (int i = 0; i < n; i++) {
        sum += input.at(i) - 48;
    }
    std::cout << sum;

    return 0;
}
