#include <iostream>

int main() {
    int num = 0, far = 0, tmp = 0, count = 0;
    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        far = -1;
        tmp = i;
        while (tmp > 0) {
            if (tmp / 10 == 0) {
                count++;
            } else {
                if (tmp == i) {
                    far = (tmp / 10) % 10 - tmp % 10;
                } else if (far != (tmp / 10) % 10 - tmp % 10) {
                    tmp = 0;
                }
            }
            tmp /= 10;
        }
    }
    std::cout << count << "\n";

    return 0;
}
