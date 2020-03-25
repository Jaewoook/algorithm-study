#include <iostream>
using namespace std;

int main() {
    int R = 0, i = 1;
    cin >> R;

    for (; i <= R; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    i -= 2;
    for (; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
