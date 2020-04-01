#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0;

    cin >> N;
    int *arr = new int[N + 1];
    int *dp = new int[N + 1];
    fill_n(dp, N + 1, 0);
    arr[0] = 0;

    for (int i  = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= N; i++) {
        dp[i] = max(max(arr[i] + arr[i - 1] + dp[i - 3], dp[i - 1]), dp[i - 2] + arr[i]);
    }

    cout << dp[N] << "\n";

    delete[] arr;
    delete[] dp;
    return 0;
}
