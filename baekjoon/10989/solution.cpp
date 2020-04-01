#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 0, n = 0, arr[10001];
    fill_n(arr, 10001, 0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> n;

        arr[n]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << "\n";
        }
    }

    return 0;
}
