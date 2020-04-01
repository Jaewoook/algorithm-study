#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int bfs(int **map, int size, int h) {
    bool **v = new bool*[size];
    for (int i = 0; i < size; i++) {
        v[i] = new bool[size];
        fill_n(v[i], size, false);
    }
    queue<pair<int, int> > q;
    pair<int, int> root;
    bool should_pop = false;
    int area = 0;
    int next_i = 0, next_j = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (v[i][j] || h >= map[i][j]) {
                continue;
            }

            v[i][j] = true;
            q.push(make_pair(i, j));
            area++;

            while (!q.empty()) {
                should_pop = true;
                root = q.front();

                for (int k = 0; k < 4; k++) {
                    next_i = root.first + d[k][0];
                    next_j = root.second + d[k][1];
                    if (next_i < 0 || next_j < 0 || next_i > size - 1 || next_j > size - 1) {
                        continue;
                    }

                    if (!v[next_i][next_j] && map[next_i][next_j] > h) {
                        v[next_i][next_j] = true;
                        should_pop = false;
                        q.push(make_pair(next_i, next_j));
                    }
                }

                if (should_pop) {
                    q.pop();
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        delete[] v[i];
    }
    delete[] v;

    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, min_h = 100, max_h = 0, max_area = 1;

    cin >> N;
    int **map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[N];

        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            min_h = map[i][j] < min_h ? map[i][j] : min_h;
            max_h = map[i][j] > max_h ? map[i][j] : max_h;
        }
    }

    for (int i = min_h; i <= max_h; i++) {
        int result = bfs(map, N, i);
        max_area = max_area < result ? result : max_area;
    }

    cout << max_area << "\n";

    for (int i = 0; i < N; i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}
