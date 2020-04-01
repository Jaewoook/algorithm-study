#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N = 0;

    cin >> N;
    int *arr = new int[N + 1];
    int *dp = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = 0;
    }

    dp[0] = arr[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
        }
    }

    cout << dp[N] << "\n";

    delete[] arr;
    delete[] dp;
    return 0;
}
