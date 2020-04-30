#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void print_board(char **board, int N, int M) {
    cout << "debug board\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

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
    return make_pair(val / N, val % M);
}

int convert_pos_to_val(pair<int, int> pos, int M) {
    return pos.first * M + pos.second;
}

pair<int, int> find_root(int i, int j, int **dp, int N, int M) {
    int val = convert_pos_to_val(make_pair(i, j), M);

    if (val != dp[i][j]) {
        pair<int, int> root = convert_val_to_pos(dp[i][j], N, M);
        pair<int, int> new_pos = find_root(root.first, root.second, dp, N, M);
        dp[i][j] = dp[new_pos.first][new_pos.second];
        return new_pos;
    }
    return make_pair(i, j);
}

int bfs(int **dp, char **board, int N, int M) {
    queue<pair<int, int> > q;
    pair<int, int> top;
    int next_i = 0, next_j = 0;
    pair<int, int> root_pos;
    int root_val = 0;
    bool should_count_up = false;
    int count = 0;

    q.push(make_pair(0, 0));
    while (!q.empty()) {
        should_count_up = false;
        top = q.front();
        cout << "\nbfs: " << top.first << " " << top.second << "\n";
        root_pos = find_root(top.first, top.second, dp, N, M);
        root_val = convert_pos_to_val(root_pos, M);
        // cout << "root: " << root_pos.first << " " << root_pos.second << " " << root_val << "\n";
        q.pop();

        for (int i = 0; i < 4; i++) {
            next_i = top.first + d[i][0] * (board[top.first][top.second] - 48);
            next_j = top.second + d[i][1] * (board[top.first][top.second] - 48);
            // cout << "next: " << next_i << " " << next_j << "\n";

            if (next_i < 0 || next_i >= N || next_j < 0 || next_j >= M || board[next_i][next_j] == 'H') {
                continue;
            }
            cout << "next: " << next_i << " " << next_j << " board: " << (int) (board[next_i][next_j]) - 48 << "\n";

            pair<int, int> next_root_pos = find_root(next_i, next_j, dp, N, M);
            if (root_val == convert_pos_to_val(next_root_pos, M)) {
                return -1;
            } else {
                should_count_up = true;
                dp[next_i][next_j] = 0;
                q.push(next_root_pos);
            }
        }

        if (should_count_up) {
            count++;
            cout << "count up!\n";
        }
    }

    return count;
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
        dp[i] = new int[M];

        //  initialize dp array
        for (int j = 0; j < M; j++) {
            dp[i][j] = i * M + j;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    print_dp(dp, N, M);
    print_board(board, N, M);
    cout << "count: " << bfs(dp, board, N, M) << "\n";
    print_dp(dp, N, M);

    for (int i = 0; i < N; i++) {
        delete[] board[i];
        delete[] dp[i];
    }
    delete[] board;
    delete[] dp;
    return 0;
}
