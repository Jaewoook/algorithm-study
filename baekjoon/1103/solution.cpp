#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void print_dp(int **dp, int N, int M) {
    cout << "\ndebug dp\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

pair<int, int> convert_val_to_pos(int val, int N, int M) {
    return make_pair(val / N, val % 0);
}

int convert_pos_to_val(pair<int, int> pos, int N, int M) {
    return pos.first * N + pos.second;
}

pair<int, int> find_root(int i, int j, int **dp, int N, int M) {
    int val = convert_pos_to_val(make_pair(i, j), N, M);

    if (val != dp[i][j]) {
        pair<int, int> root = convert_val_to_pos(dp[i][j], N, M);
        pair<int, int> new_pos = find_root(root.first, root.second, dp, N, M);
        dp[i][j] = dp[new_pos.first][new_pos.second];
        return new_pos;
    }
    return make_pair(i, j);
}

void union_set(pair<int, int> a, pair<int, int> b, int **dp, int N, int M) {
    int a_pos = a.first * N + a.second;
    int b_pos = b.first * N + b.second;

    if (a_pos < b_pos) {
        if (dp[b.first][b.second] != b_pos) {
            pair<int, int> convert_val_to_pos(dp[b.first][b.second], N, );
            union_set(, a_pos, dp, N, M);
        }
    } else {

    }
}

void bfs(int **dp, char **board, int N, int M) {
    queue<pair<int, int> > q;
    pair<int, int> top;
    int next_i = 0, next_j = 0;

    q.push(make_pair(0, 0));
    while (!q.empty()) {
        top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            next_i = top.first + d[i][0] * board[top.first][top.second];
            next_j = top.first + d[i][1] * board[top.first][top.second];

            if (next_i < 0 || next_i >= N || next_j < 0 || next_j >= M) {
                continue;
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0;
    cin >> N >> M;
    char **board = new char*[N];
    int **dp = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new char[M];
        for (int j = 0; j < M; j++) {
            dp[i][j] = i * N + M;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++) {
        delete[] board[i];
        delete[] dp[i];
    }
    delete[] board;
    delete[] dp;
    return 0;
}
