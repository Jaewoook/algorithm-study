#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, M, a, b;
    cin >> N;
    int *num = new int[N + 1];
    int *dp = new int[N + 1];
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        dp[i] = dp[i - 1] + num[i];
    }
    cin >> M;
    while (M--) {
        cin >> a >> b;
        cout << dp[b] - dp[a - 1] << "\n";
    }

    delete[] num;
    delete[] dp;
    return 0;
}
