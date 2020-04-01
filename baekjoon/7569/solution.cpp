#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#define EMPTY -1
#define RED 1
#define GREEN 0
using namespace std;

//  { H, M, N } index shift directions
const int d[6][3] = {
    { 0, -1, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 0, -1 },
    { -1, 0, 0 },
    { 1, 0, 0 }
};

bool is_all_red(int ***box, int HEIGHT, int ROW, int COL) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < ROW; j++) {
            for (int k = 0; k < COL; k++) {
                if (box[i][j][k] == GREEN) {
                    return false;
                }
            }
        }
    }

    return true;
}

pair<int, pair<int, int> > make_pos(int h, int x, int y) {
    return make_pair(h, make_pair(x, y));
}

queue<pair<int, pair<int, int> > > bfs(queue<pair<int, pair<int, int> > > start, int ***box, int HEIGHT, int ROW, int COL) {
    queue<pair<int, pair<int, int> > > result;
    pair<int, pair<int, int> > root;
    int next_i = 0, next_j = 0, next_k = 0;

    while (!start.empty()) {
        root = start.front();
        for (int i = 0; i < 6; i++) {
            next_i = root.first + d[i][0];
            next_j = root.second.first + d[i][1];
            next_k = root.second.second + d[i][2];
            if (next_i < 0 || next_i > HEIGHT - 1 || next_j < 0 || next_j > ROW - 1 || next_k < 0 || next_k > COL - 1) {
                continue;
            }

            if (box[next_i][next_j][next_k] == GREEN) {
                box[next_i][next_j][next_k] = RED;
                result.push(make_pos(next_i, next_j, next_k));
            }
        }
        start.pop();
    }

    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int COL = 0, ROW = 0, HEIGHT = 0, day = 0;
    queue<pair<int, pair<int, int> > > start, next;
    cin >> COL >> ROW >> HEIGHT;

    int ***box = new int**[HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        box[i] = new int*[ROW];
        for (int j = 0; j < ROW; j++) {
            box[i][j] = new int[COL];
        }
    }

    for (int h = 0; h < HEIGHT; h++) {
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                cin >> box[h][r][c];
                if (box[h][r][c] == RED) {
                    start.push(make_pos(h, r, c));
                }
            }
        }
    }

    if (!is_all_red(box, HEIGHT, ROW, COL)) {
        while (!start.empty()) {
            start = bfs(start, box, HEIGHT, ROW, COL);
            if (!start.empty()) {
                day++;
            }
        }

        if (!is_all_red(box, HEIGHT, ROW, COL)) {
            day = -1;
        }
    }

    cout << day << "\n";

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < ROW; j++) {
            delete[] box[i][j];
        }
    }
    delete[] box;
    return 0;
}
