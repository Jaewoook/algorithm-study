#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool isIn = false, isOut = false;
    int T = 0, n = 0, count = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, cx = 0, cy = 0, cr = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> n;

        count = 0;
        for (int j = 0; j < n; j++) {
            cin >> cx >> cy >> cr;

            isIn = pow(cx - x1, 2) + pow(cy - y1, 2) < pow(cr, 2) && pow(cx - x2, 2) + pow(cy - y2, 2) < pow(cr, 2);
            isOut = pow(cx - x1, 2) + pow(cy - y1, 2) > pow(cr, 2) && pow(cx - x2, 2) + pow(cy - y2, 2) > pow(cr, 2);
            if (!(isIn || isOut)) {
                count++;
            }

        }
        cout << count << "\n";
    }

    return 0;
}
