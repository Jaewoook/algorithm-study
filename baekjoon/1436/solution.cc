#include <iostream>
using namespace std;

bool check_number(unsigned int n) {
    int count = 0;
    while (n != 0) {
        if (n % 10 == 6) {
            count++;
        } else {
            count = 0;
        }

        if (count == 3) {
            return true;
        }
        n /= 10;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int N, result = 665;
    cin >> N;

    for (int i = 0; i < N; i++) {
        while (!check_number(result)) {
            result++;
        }
        result++;
    }
    cout << (result - 1) << "\n";
    return 0;
}
