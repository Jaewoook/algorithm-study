#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

void dfs(pair<int, int> pos, int map[50][50], bool visited[50][50]) {
    stack<pair<int, int> > s;
    int col[4] = { 0, 1, 0, -1 }, row[4] = { -1, 0, 1, 0 };
    bool should_pop = false;
    int next_i = -1, next_j = -1;
    pair<int, int> root;
    visited[pos.first][pos.second] = true;
    s.push(pos);

    while (!s.empty()) {
        root = s.top();
        should_pop = true;
        for (int i = 0; i < 4; i++) {
            next_i = root.first + row[i];
            next_j = root.second + col[i];
            if (next_i > 49 || next_i < 0 || next_j > 49 || next_j < 0) {
                continue;
            }
            if (map[next_i][next_j] == 1 && !visited[next_i][next_j]) {
                visited[next_i][next_j] = true;
                s.push(make_pair(next_i, next_j));
                should_pop = false;
                break;
            }
        }

        if (should_pop) {
            s.pop();
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, N = 0, M = 0, K = 0, row = 0, col = 0, count = 0;
    int map[50][50];
    bool visited[50][50];

    cin >> T;

    while (T--) {
        count = 0;
        cin >> N >> M >> K;

        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < K; i++) {
            cin >> row >> col;
            map[row][col] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(make_pair(i, j), map, visited);
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}
