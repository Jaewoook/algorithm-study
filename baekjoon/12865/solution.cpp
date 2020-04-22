#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 0, K = 0, W = 0, V = 0;

    cin >> N >> K;
    pair<int, int> *wv = new pair<int, int>[N];
    int **dp = new int*[N];
    for (int i = 0; i < N; i++) {
        dp[i] = new int[K + 1];
        fill_n(dp[i], K + 1, 0);
    }

    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        wv[i] = make_pair(W, V);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (i == 0) {
                if (wv[i].first <= j) {
                    dp[i][j] = wv[i].second;
                }
                continue;
            }

            if (wv[i].first <= j) {
                dp[i][j] = max(dp[i - 1][j], wv[i].second + dp[i - 1][j - wv[i].first]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N - 1][K] << "\n";

    for (int i = 0; i < N; i++) {
        delete[] dp[i];
    }
    delete[] wv;
    delete[] dp;
    return 0;
}
