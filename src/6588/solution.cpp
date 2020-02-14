#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    bool prime[1000001] = { false, };
    int n = 0, prime1 = 0, prime2 = 0;

    fill_n(prime + 2, 999999, true);
    for (int i = 2; i <= 1000000; i++) {
        if (i * i > 1000000) {
            break;
        }
        if (prime[i] == true) {
            for (int j = i * i; j <= 1000000; j += i) {
                prime[j] = false;
            }
        }
    }

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        prime1 = 0;
        prime2 = 0;
        for (int i = 2; i <= n - 1; i++) {
            if (prime[i] && prime[n - i]) {
                prime1 = i;
                prime2 = n - i;
                break;
            }
        }

        if (prime1 == 0) {
            cout << "Goldbach's conjecture is wrong.\n";
        } else {
            cout << prime1 + prime2 << " = " << prime1 << " + " << prime2 << "\n";
        }
    }

    return 0;
}
