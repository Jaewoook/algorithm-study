#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long A, B, C, result = 1;
    cin >> A >> B >> C;

    while (B > 0) {
        if ((B & 1) == 1) {
            result = (result * A) % C;
        }

        A = (A * A) % C;

        B >>= 1;
    }

    cout << result << "\n";

    return 0;
}
