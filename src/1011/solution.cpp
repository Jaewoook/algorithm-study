#include <iostream>
#include <cmath>
using namespace std;

// 1 : 1
// 2 : 2
// 3 : 3
// 4 : 3
// 5 : 4
// 6 : 4
// 7 : 5
// 8 : 5
// 9 : 5
// 10: 6
// 11: 6
// 12: 6
// 13: 7
// 14: 7
// 15: 7
// 16: 7
// 17: 8

int main() {
    unsigned int T = 0, x = 0, y = 0, n = 1, remaining = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        n = (int) sqrt(y - x);
        remaining = (y - x) - n * n;
        cout << n * 2 - 1 + ceil((double) remaining / n) << "\n";
    }
    return 0;
}
