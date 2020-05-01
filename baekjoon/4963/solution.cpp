#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

const int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs(int start_i, int start_j, int **map, bool **v, int W, int H) {
    stack<pair<int, int> > s;
    pair<int, int> top;
    int next_i = 0, next_j = 0;
    bool should_pop = false;

    s.push(make_pair(start_i, start_j));
    while (!s.empty()) {
        top = s.top();
        should_pop = true;

        for (int i = 0; i < 8; i++) {
            next_i = top.first + d[i][0];
            next_j = top.second + d[i][1];
            if (next_i < 0 || next_i >= H || next_j < 0 || next_j >= W || v[next_i][next_j]) {
                continue;
            }

            if (map[next_i][next_j] == 1) {
                v[next_i][next_j] = true;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int W = 0, H = 0, island = 0;
    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) {
            break;
        }

        island = 0;
        int **map = new int*[H];
        bool **v = new bool*[H];
        for (int i = 0; i < H; i++) {
            map[i] = new int[W];
            v[i] = new bool[W];
            fill_n(v[i], W, false);
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (map[i][j] == 1 && !v[i][j]) {
                    dfs(i, j, map, v, W, H);
                    island++;
                }
            }
        }

        cout << island << "\n";

        for (int i = 0; i < H; i++) {
            delete[] map[i];
            delete[] v[i];
        }
        delete[] map;
        delete[] v;
    }

    return 0;
}
