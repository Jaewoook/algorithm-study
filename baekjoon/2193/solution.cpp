#include <iostream>
using namespace std;

int main() {
    int N = 0;
    cin >> N;

    unsigned long long** dp = new unsigned long long*[N];
    for (int i = 0; i < N; i++) {
        dp[i] = new unsigned long long[2];
    }

    dp[0][0] = 0;
    dp[0][1] = 1;
    if (N > 1) {
        dp[1][0] = 1;
        dp[1][1] = 0;
    }

    for (int i = 2; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[N - 1][0] + dp[N - 1][1] << "\n";

    for (int i = 0; i < N; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}
