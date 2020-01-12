#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int T = 0, x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int xd = x1 - x2;
        xd *= xd;
        int yd = y1 - y2;
        yd *= yd;
        long double d = sqrt(xd + yd);
        if (d == 0 && r1 == r2) {
            cout << -1 << "\n";
        } else if (abs(r1 - r2) < d && r1 + r2 > d) {
            cout << 2 << "\n";
        } else if (r1 + r2 == d || abs(r1 - r2) == d) {
            cout << 1 << "\n";
        } else if (r1 + r2 < d) {
            cout << 0 << "\n";
        } else if (abs(r1 - r2) > d) {
            cout << 0 << "\n";
        } else if (d == 0 && r1 != r2) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }

    }


    return 0;
}
