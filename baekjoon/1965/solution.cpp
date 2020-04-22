#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, result = 0;
    cin >> N;

    int *arr = new int[N];
    int *dp = new int[N];
    fill_n(dp, N, 1);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = arr[j] < arr[i] ? max(dp[j] + 1, dp[i]) : dp[i];
        }
    }

    for (int i = 0; i < N; i++) {
        result = dp[i] > result ? dp[i] : result;
    }

    cout << result << "\n";

    delete[] arr;
    delete[] dp;
    return 0;
}
