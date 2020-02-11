#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, max = 1;

    cin >> N;
    int *arr = new int[N];
    int *dp = new int[N];
    fill_n(dp, N, 1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = arr[i] < arr[j] && dp[i] < dp[j] + 1 ? dp[j] + 1 : dp[i];
        }
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    cout << max << "\n";

    delete[] arr;
    delete[] dp;
    return 0;
}
