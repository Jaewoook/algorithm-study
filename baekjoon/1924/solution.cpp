#include <iostream>
#include <string>

int main() {
    int x = 0, y = 0;
    std::string day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::cin >> x >> y;

    for(int i = 1; i < x; i++) {
        y += month[i - 1];
    }
    std::cout << day[y % 7] << "\n";

    return 0;
}
