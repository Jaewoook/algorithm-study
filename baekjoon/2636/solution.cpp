#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }};

bool is_gone(int **plate, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (plate[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

queue<pair<int, int> > bfs(int **plate, bool **v, int row, int col) {
    queue<pair<int, int> > q, c;

    pair<int, int> root;
    int next_i = 0, next_j = 0;
    bool should_pop = false;
    q.push(make_pair(0, 0));
    v[0][0] = true;

    while (!q.empty()) {
        root = q.front();
        should_pop = true;
        for (int i = 0; i < 4; i++) {
            next_i = root.first + d[i][0];
            next_j = root.second + d[i][1];

            if (next_i < 0 ||next_i >= row || next_j <0 || next_j >= col) {
                continue;
            }

            if (!v[next_i][next_j]) {
                if (plate[next_i][next_j] == 1) {
                    c.push(make_pair(next_i, next_j));
                } else {
                    q.push(make_pair(next_i, next_j));
                }
                v[next_i][next_j] = true;
                should_pop = false;
            }
        }

        q.pop();
    }

    return c;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int row = 0, col = 0, h = 0, pieces = 0;
    queue<pair<int, int> > c;
    cin >> row >> col;

    int **plate = new int*[row];
    bool **v = new bool*[row];
    for (int i = 0; i < row; i++) {
        plate[i] = new int[col];
        v[i] = new bool[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> plate[i][j];
        }
    }

    while (!is_gone(plate, row, col)) {
        for (int i = 0; i < row; i++) {
            fill_n(v[i], col, false);
        }
        c = bfs(plate, v, row, col);

        pieces = c.size();
        h++;

        while (!c.empty()) {
            plate[c.front().first][c.front().second] = 0;
            c.pop();
        }
    }

    cout << h << "\n" << pieces << "\n";

    delete[] plate;
    delete[] v;
    return 0;
}
