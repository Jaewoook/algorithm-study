#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    unsigned long long T = 0, a = 0, b = 0, n = 0;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> a >> b;

        b %= 4;
        b = b == 0 ? 4 : b;
        n = 1;
        for (int j = 0; j < b; j++) {
            n *= a;
            n %= 10;
        }
        cout << (n == 0 ? 10 : n) << "\n";
    }

    return 0;
}
