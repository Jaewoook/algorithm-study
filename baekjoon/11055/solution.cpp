#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, max = 0;

    cin >> N;
    int *arr = new int[N];
    int *dp = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = arr[i] > arr[j] && dp[i] < dp[j] + arr[i] ? dp[j] + arr[i] : dp[i];
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    cout << max << "\n";

    delete[] arr;
    delete[] dp;
    return 0;
}
