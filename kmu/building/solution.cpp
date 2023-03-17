#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, result, high;
    vector<int> b;

    cin >> T;
    while (T--) {
        cin >> N;

        result = high = 0;
        b = vector<int>(N);
        while (N--) {
            cin >> b[N];
        }

        for (auto i = b.begin(); i != b.end(); i++) {
            if (i == b.begin()) {
                result++;
                high = *i;
                continue;
            }
            if ((*i) > high) {
                result++;
                high = *i;
            }
        }

        cout << result << "\n";
    }
    return 0;
}

// 2
// 6
// 9 11 8 6 8 5
// 7
// 6 5 8 6 5 3 5
