#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, result = 0, a = 0, p = 0;

    cin >> T;
    while (T--) {
        cin >> p >> a;
        result += a - p * (a / p);
    }

    cout << result << "\n";

    return 0;
}
