#include <iostream>
using namespace std;

int main() {
    bool prime[10001] = { false, };
    int N = 0, M = 0, min = -1, sum = 0;

    fill_n(&prime[2], 10001, true);

    for (int i = 2; i < 10001; i++) {
        if (prime[i] == true) {
            for (int j = i * i; j < 10001; j += i) {
                prime[j] = false;
            }
        }
    }

    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        if (prime[i] == true) {
            sum += i;
            min = min == -1 ? i : min;
        }
    }

    if (min == -1) {
        cout << -1 << "\n";
    } else {
        cout << sum << "\n" << min << "\n";
    }

    return 0;
}
