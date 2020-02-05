#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, max = 1, max_index = 0, size = 0;

    cin >> N;
    int *arr = new int[N];
    vector<int> *dp = new vector<int>[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i].push_back(arr[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i].size() < dp[j].size() + 1) {
                dp[i].assign(dp[j].begin(), dp[j].end());
                dp[i].push_back(arr[i]);
            }
        }
        if (max < dp[i].size()) {
            max = dp[i].size();
            max_index = i;
        }
    }

    cout << max << "\n";

    size = dp[max_index].size();
    for (int i = 0; i < size; i++) {
        cout << dp[max_index][i] << (i + 1 < size ? " " : "\n");
    }

    delete[] arr;
    delete[] dp;
    return 0;
}
