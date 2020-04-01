#include <iostream>
using namespace std;

int main() {
    int N = 0, i = 0, length = 0, stars = 1;
    cin >> N;

    length = N * 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < length; j++) {
            if (j < stars || length - j <= stars) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        stars++;
        cout << "\n";
    }

    stars -= 2;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < length; j++) {
            if (j < stars || length - j <= stars) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        stars--;
        cout << "\n";
    }

    return 0;
}
