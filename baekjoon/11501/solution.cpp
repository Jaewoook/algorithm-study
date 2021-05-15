#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, max, *a;
    long long result = 0;
    cin >> t;
    while (t--) {
        result = 0;
        max = 0;
        cin >> n;
        a = new int[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (max < a[i]) {
                max = a[i];
            } else {
                result += max - a[i];
            }
        }
        cout << result << "\n";
        delete[] a;
    }
    return 0;
}
