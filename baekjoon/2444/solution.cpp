#include <iostream>
using namespace std;

int main() {
    int N = 0, i = 0, length = 0, stars = 1;
    cin >> N;

    length = 1 + 2 * (N - 1);

    for (; i < N; i++) {
        for (int j = 0; j < length; j++) {
            if ((length - stars) / 2 > j) {
                cout << " ";
            } else if (!(length - (length - stars) / 2 <= j)) {
                cout << "*";
            }
        }
        stars += 2;
        cout << "\n";
    }

    stars -= 4;
    for (i = 1; i < N; i++) {
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

    return 0;
}
