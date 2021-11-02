#include <iostream>
#include <algorithm>
using namespace std;

int min(int v1, int v2) {
    return v1 < v2 ? v1 : v2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int *matrix = new int[N + 1];
    unsigned int **dp = new unsigned int*[N + 1];
    for (int i = 1; i <= N; i++) {
        dp[i] = new unsigned int[N + 1];
        fill_n(dp[i], N + 1, -1);
        dp[i][i] = 0;
        cin >> matrix[i - 1] >> matrix[i];
    }

    int j;
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i <= N - len + 1; i++) {
            j = len + i - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j]);
            }
        }
    }

    cout << dp[1][N] << "\n";

    for (int i = 0; i <= N; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] matrix;
    return 0;
}
