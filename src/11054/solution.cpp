#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    bool increase = true;
    int N = 0, max = 0;

    cin >> N;
    int *arr = new int[N];
    int **dp = new int*[N];
    for (int i = 0; i < N; i++) {
        dp[i] = new int[2];
        fill_n(dp[i], 2, 1);
    }

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][0] = arr[i] > arr[j] && dp[i][0] < dp[j][0] + 1 ? dp[j][0] + 1 : dp[i][0];
        }
    }
    reverse(arr, arr + N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            dp[N - 1 - i][1] = arr[i] > arr[j] && dp[N - 1 - i][1] < dp[N - 1 - j][1] + 1 ? dp[N - 1 - j][1] + 1 : dp[N - 1 - i][1];
        }
    }

    for (int i = 0; i < N; i++) {
        if (max < dp[i][0] + dp[i][1]) {
            max = dp[i][0] + dp[i][1];
        }
    }

    cout << max - 1 << "\n";

    delete[] arr;
    for (int i = 0; i < N; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}
