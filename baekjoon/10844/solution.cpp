#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000000

int main() {
    int N = 0, sum = 0;

    cin >> N;
    int **dp = new int*[N + 1];
    for (int i = 1; i <= N; i++) {
        dp[i] = new int[10];
        fill_n(dp[i], 10, 0);
    }

    dp[1][0] = 0;
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1] % MOD;
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][8] % MOD;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        sum += dp[N][i];
        sum %= MOD;
    }

    cout << sum << "\n";

    for (int i = 1; i <= N; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}
