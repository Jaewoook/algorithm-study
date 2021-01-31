#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int h[9] = {};
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> h[i];
        sum += h[i];
    }

    sort(h, h + 9);
    int i, j;
    for (i = 0; i < 9; i++) {
        sum -= h[i];
        for (j = 0; j < 9; j++) {
            if (i == j) continue;
            sum -= h[j];
            if (sum == 100) break;
            sum += h[j];
        }
        if (sum == 100) break;
        sum += h[i];
    }

    for (int k = 0; k < 9; k++) {
        if (k == i || k == j) continue;
        cout << h[k] << "\n";
    }

    return 0;
}
