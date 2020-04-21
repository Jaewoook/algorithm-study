#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

#define MULTI_PIECE 0
#define ONE_PIECE 1
#define ALL_MELDTED 2

const int d[4][2] = {{ -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }};

bool check_map(bool **v, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!v[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void dfs(int start_row, int start_col, int **map, bool **v, int row, int col) {
    if (v[start_row][start_col]) {
        return;
    }

    v[start_row][start_col] = true;
    if (map[start_row][start_col] == -1) {
        map[start_row][start_col] = 0;
    }
    int next_i = 0, next_j = 0;

    for (int i = 0; i < 4; i++) {
        next_i = start_row + d[i][0];
        next_j = start_col + d[i][1];

        if (next_i < 0 || next_i >= row || next_j < 0 || next_j >= col) {
            continue;
        }

        if (!v[next_i][next_j]) {
            dfs(next_i, next_j, map, v, row, col);
        }
    }
}

void bfs(int start_i, int start_j, int **map, bool **v, int row, int col) {
    queue<pair<int, int> > q;
    pair<int, int> root;
    int next_i = 0, next_j = 0;

    q.push(make_pair(start_i, start_j));
    v[start_i][start_j] = true;
    while (!q.empty()) {
        root = q.front();

        for (int i = 0; i < 4; i++) {
            next_i = root.first + d[i][0];
            next_j = root.second + d[i][1];

            if (next_i < 0 || next_i >= row || next_j < 0 || next_j >= col) {
                continue;
            }

            if (!v[next_i][next_j]) {
                if (map[next_i][next_j] > 0) {
                    map[next_i][next_j]--;
                    if (map[next_i][next_j] == 0) {
                        map[next_i][next_j] = -1;
                    }
                } else if (map[next_i][next_j] == 0) {
                    v[next_i][next_j] = true;
                    q.push(make_pair(next_i, next_j));
                }
            }
        }

        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int row = 0, col = 0, y = 0;
    bool is_all_melted = false;
    cin >> row >> col;

    int **map = new int*[row];
    bool **v = new bool*[row];
    for (int i = 0; i < row; i++) {
        map[i] = new int[col];
        v[i] = new bool[col];
        fill_n(v[i], col, true);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j];
        }
    }

    while (!is_all_melted && check_map(v, row, col)) {
        for (int i = 0; i < row; i++) {
            fill_n(v[i], col, false);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!v[i][j] && map[i][j] == 0) {
                    bfs(i, j, map, v, row, col);
                }
            }
        }

        is_all_melted = true;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!v[i][j]) {
                    is_all_melted = false;
                    dfs(i, j, map, v, row, col);
                }
                if (!is_all_melted) {
                    break;
                }
            }
            if (!is_all_melted) {
                break;
            }
        }
        y++;
    }

    cout << (!is_all_melted ? y - 1 : 0) << "\n";

    delete[] map;
    delete[] v;
    return 0;
}
