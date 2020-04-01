#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N = 0, tmp = 0, root = 0;

    cin >> N;
    int *dp = new int[N + 1];
    dp[0] = 0, dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        root = sqrt(i);
        tmp = root - 1;
        dp[i] = dp[i % (root * root)] + i / (root * root);
        while (tmp > 2) {
            dp[i] = min(dp[i], dp[i % (tmp * tmp)] + i / (tmp * tmp));
            tmp--;
        }
    }

    cout << dp[N] << "\n";

    delete[] dp;
    return 0;
}
