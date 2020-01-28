#include <iostream>
using namespace std;

int main() {
    int N = 0, stars = 0, length = 0;
    cin >> N;
    stars = length = 1 + 2 * (N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = length - 1; j >= 0; j--) {
            if ((length - (length - stars) / 2 <= j)) {
                cout << " ";
            } else if (!((length - stars) / 2 > j)) {
                cout << "*";
            }
        }
        stars -= 2;
        cout << "\n";
    }

    stars += 4;
    for (int i = 1; i < N; i++) {
        for (int j = length - 1; j >= 0; j--) {
            if ((length - (length - stars) / 2 <= j)) {
                cout << " ";
            } else if (!((length - stars) / 2 > j)) {
                cout << "*";
            }
        }
        stars += 2;
        cout << "\n";
    }
    return 0;
}
