#include <iostream>
using namespace std;

int main() {
    int X = 0, Y = 0, i = 2, min = 1;
    cin >> X >> Y;

    while (true) {
        if (X % i == 0 && Y % i == 0) {
            min *= i;
            X /= i;
            Y /= i;
            continue;
        }
        if (X < i && Y < i) {
            break;
        }
        i++;
    }

    cout << min << "\n" << min * X * Y << "\n";

    return 0;
}
