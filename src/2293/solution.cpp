#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, K = 0;

    cin >> N >> K;
    int *coin = new int[N];
    int *dp = new int[K + 1];
    fill_n(dp, K + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - coin[i] >= 0) {
                dp[j] += dp[j - coin[i]];
            }
        }
    }

    cout << dp[K] << "\n";

    delete[] dp;
    delete[] coin;
    return 0;
}
