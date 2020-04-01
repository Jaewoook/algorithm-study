#include <iostream>
using namespace std;

int main() {
    int N = 0;

    cin >> N;
    int *dp = new int[N + 1];

    dp[0] = dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
        }
         if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
        }
    }

    cout << dp[N] << "\n";

    delete[] dp;
    return 0;
}
