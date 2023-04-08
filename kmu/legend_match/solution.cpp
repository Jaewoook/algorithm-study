#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T, n, m, diff;
    unsigned long long sum;
    pair<int, int> diff_value;
    vector<unsigned int> ab;
    priority_queue<pair<int, int>> diff_q;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        sum = 0;
        ab = vector<unsigned int>(n);
        for (int i = 0; i < n; i++) {
            cin >> ab[i];
        }
        if (n % 2 != 0) {
            ab.push_back(0);
        }
        sort(ab.begin(), ab.end(), greater<unsigned int>());
        for (int round = 0; round * 2 < n; round++) {
            diff = ab[round * 2] - ab[round * 2 + 1];
            diff_q.push(make_pair(diff, round));
        }

        while (!diff_q.empty()) {
            diff_value = diff_q.top();
            diff_q.pop();

            if (m > 0) {
                sum += ab[diff_value.second * 2];
                --m;
            } else {
                sum += ab[diff_value.second * 2 + 1];
            }
        }

        cout << sum << "\n";
    }
    return 0;
}

// sample input
// 3
// 8 2
// 1 9 3 6 2 9 1 8
// 12 4
// 15 13 5 8 15 5 5 16 18 3 2 8
// 11 4
// 4 18 6 19 18 12 19 1 2 17 10

// sample output
// 21
// 62
// 69
