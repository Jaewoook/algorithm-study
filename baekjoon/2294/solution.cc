#include <iostream>
#include <vector>
using namespace std;
#define INF 10001

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> coins(n), dp(k + 1, INF);
    for (auto i = coins.begin(); i != coins.end(); i++) {
        cin >> *i;
        dp[*i] = 1;
    }
    dp[0] = 0;

    for (int c = 0; c < n; c++) {
        for (int m = coins[c]; m <= k; m++) {
            dp[m] = min(dp[m], dp[m - coins[c]] + 1);
        }
    }

    cout << (dp[k] == INF ? -1 : dp[k]) << "\n";

    return 0;
}
