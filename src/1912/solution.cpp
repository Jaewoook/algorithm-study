#include <iostream>
using namespace std;

int main() {
    int N = 0, max = -1000000000;

    cin >> N;
    int *num = new int[N];
    int *dp = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    dp[0] = num[0];
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + num[i] > num[i] ? dp[i - 1] + num[i] : num[i];
    }

    for (int i = 0; i < N; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    cout << max << "\n";

    delete[] num;
    delete[] dp;
    return 0;
}
