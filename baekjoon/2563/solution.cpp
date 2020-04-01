#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, x = 0, y = 0, space = 0;
    bool map[101][101] = {};

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;

        for (int j = x; j < x + 10; j++) {
            fill_n(map[j] + y, 10, true);
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j]) {
                space++;
            }
        }
    }

    cout << space << "\n";

    return 0;
}
