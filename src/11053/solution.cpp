#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N = 0, max = 1;

    cin >> N;
    int *arr = new int[N];
    int *dp = new int[N];

    arr[0] = 0;
    dp[0] = 0;
    fill_n(dp, N, 1);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
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
