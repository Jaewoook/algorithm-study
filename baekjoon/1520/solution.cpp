#include <iostream>
#include <algorithm>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }};

void dfs(int start_i, int start_j, int **map, int **dp, int M, int N) {
    if (dp[start_i][start_j] < 0) {
        dp[start_i][start_j] = 0;
        int next_i = 0, next_j = 0;
        for (int i = 0; i < 4; i++) {
            next_i = start_i + d[i][0];
            next_j = start_j + d[i][1];

            if (next_i < 0 || next_i >= M || next_j < 0 || next_j >= N) {
                continue;
            }

            if (map[start_i][start_j] > map[next_i][next_j]) {
                dfs(next_i, next_j, map, dp, M, N);
                dp[start_i][start_j] += dp[next_i][next_j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M = 0, N = 0, next_i = 0, next_j = 0;
    cin >> M >> N;

    int **map = new int*[M];
    int **dp = new int*[M];
    for (int i = 0; i < M; i++) {
        map[i] = new int[N];
        dp[i] = new int[N];
        fill_n(dp[i], N, -1);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    dp[M - 1][N - 1] = 1;
    dfs(0, 0, map, dp, M, N);
    cout << dp[0][0] << "\n";

    delete[] map;
    delete[] dp;
    return 0;
}
