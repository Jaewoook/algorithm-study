#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, result = 0;
    vector<int> dp(101);

    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int d = -99; d < 100; d++) {
        fill(dp.begin(), dp.end(), 0);
        for (int i = 0; i < N; i++) {
            int k = arr[i] - d;
            if (0 < k && k < 101) {
                dp[arr[i]] = dp[k] + 1;
            } else {
                dp[arr[i]] = 1;
            }
            result = max(result, dp[arr[i]]);
        }
    }

    cout << result << "\n";

    return 0;
}
