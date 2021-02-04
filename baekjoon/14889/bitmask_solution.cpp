#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int calculate_sum(const vector<vector<int>> S, vector<int> t) {
    int result = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = i + 1; j < t.size(); j++) {
            result += S[t[i]][t[j]] + S[t[j]][t[i]];
        }
    }
    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, min_diff;
    cin >> N;
    vector<vector<int>> S(N);
    vector<int> t1, t2;
    for (int i = 0; i < N; i++) {
        S[i] = vector<int>(N);
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }
    min_diff = -1;
    for (int i = (1 << (N / 2 + 1)) - 1; i < 1 << N; i++) {
        t1.clear();
        t2.clear();
        for (int j = 0; j < N; j++) {
            if (i & 1 << j) {
                t1.push_back(j);
            } else {
                t2.push_back(j);
            }
        }
        if (t1.size() == t2.size()) {
            int t1_sum = calculate_sum(S, t1);
            int t2_sum = calculate_sum(S, t2);
            if (min_diff < 0) {
                min_diff = abs(t1_sum - t2_sum);
            } else {
                min_diff = min(min_diff, abs(t1_sum - t2_sum));
            }
        }
    }
    cout << min_diff << "\n";

    return 0;
}
