#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, P, cur, step;
    cin >> T;
    while (T--) {
        cin >> N >> P;
        cur = step = 0;
        while (cur < N) {
            cur += 2;
            if (cur == P) {
                cur--;
            }
            step++;
        }

        cout << step << "\n";
    }
    return 0;
}
