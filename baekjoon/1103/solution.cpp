#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

const int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int dfs(int start_i, int start_j, int **dp, bool **v, char **board, int N, int M) {
    if (start_i < 0 || start_i >= N || start_j < 0 || start_j >= M || board[start_i][start_j] == 'H') {
        return 0;
    }

    int next_i = 0, next_j = 0;
    if (v[start_i][start_j]) {
        return -1;
    }

    if (dp[start_i][start_j] > 0) {
        return dp[start_i][start_j];
    }

    v[start_i][start_j] = true;
    for (int i = 0; i < 4; i++) {
        next_i = start_i + d[i][0] * (board[start_i][start_j] - 48);
        next_j = start_j + d[i][1] * (board[start_i][start_j] - 48);

        int result = dfs(next_i, next_j, dp, v, board, N, M);
        if (result == -1) {
            return -1;
        }
        dp[start_i][start_j] = max(dp[start_i][start_j], result + 1);
    }

    v[start_i][start_j] = false;
    return dp[start_i][start_j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0;
    cin >> N >> M;

    char **board = new char*[N];
    int **dp = new int*[N];
    bool **v = new bool*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new char[M];
        dp[i] = new int[M];
        v[i] = new bool[M];
        fill_n(dp[i], M, 0);
        fill_n(v[i], M, false);
    }

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    cout << dfs(0, 0, dp, v, board, N, M) << "\n";

    for (int i = 0; i < N; i++) {
        delete[] board[i];
        delete[] dp[i];
    }
    delete[] board;
    delete[] dp;
    delete[] v;
    return 0;
}
