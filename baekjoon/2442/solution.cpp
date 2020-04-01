#include <iostream>
using namespace std;

int main() {
    int N = 0, length = 0, stars = 1;
    cin >> N;

    length = 1 + 2 * (N - 1);

    for (int i = 0; i < N; i++) {
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
    return 0;
}
