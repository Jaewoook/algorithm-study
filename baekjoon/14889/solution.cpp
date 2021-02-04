#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define DIFF 2147483647

int calculate_sum(const vector<vector<int>> S, vector<int> t) {
    int result = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = i + 1; j < t.size(); j++) {
            result += S[t[i]][t[j]] + S[t[j]][t[i]];
        }
    }
    return result;
}

void backtracking(const vector<vector<int>> &S, vector<int> &t1, vector<int> &t2, const int N, int depth, int &diff) {
    if (depth >= N) {
        if (t1.size() == t2.size() && t2.size() == N / 2) {
            int t1_sum = calculate_sum(S, t1);
            int t2_sum = calculate_sum(S, t2);
            diff = min(diff, abs(t1_sum - t2_sum));
        }
        return;
    }

    t1.push_back(depth);
    backtracking(S, t1, t2, N, depth + 1, diff);
    t1.pop_back();
    t2.push_back(depth);
    backtracking(S, t1, t2, N, depth + 1, diff);
    t2.pop_back();
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
    min_diff = DIFF;
    backtracking(S, t1, t2, N, 0, min_diff);
    cout << min_diff << "\n";

    return 0;
}
