#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N = 0, result = 0;

    cin >> N;
    int **dp = new int*[N + 1];
    for (int i = 0; i <= N; i++) {
        dp[i] = new int[10];
    }
    fill_n(dp[1], 10, 1);

    for (int i = 2; i <= N; i++) {
        for (int j = 9; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (j != 9) {
                dp[i][j] += dp[i][j + 1];
                dp[i][j] %= 10007;
            };
        }
    }

    for (int i = 0; i < 10; i++) {
        result += dp[N][i];
        result %= 10007;
    }

    cout << result << "\n";

    for (int i = 0; i <= N; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}
