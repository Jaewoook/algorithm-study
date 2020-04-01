#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    bool prime[10001] = { false, };
    int T = 0, n = 0, distance = 0, prime1 = 0, prime2 = 0;
    cin >> T;

    fill_n(prime + 2, 9999, true);
    for (int i = 2; i <= 10001; i++) {
        if (i * i > 10000) {
            break;
        }
        if (prime[i] == true) {
            for (int j = i * i; j <= 10001; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 0; i < T; i++) {
        cin >> n;

        distance = 10000;
        prime1 = 0;
        prime2 = 0;
        for (int j = n - 1; j >= 2; j--) {
            if (prime[j] && prime[n - j]) {
                if (j - (n - j) < distance && j - (n - j) >= 0) {
                    distance = j - (n - j);
                    prime1 = n - j;
                    prime2 = j;
                    if (distance <= 0) {
                        break;
                    }
                } else if (j - (n - j) < 0) {
                    break;
                }
            }
        }
        cout << prime1 << " " << prime2 << "\n";
    }

    return 0;
}
