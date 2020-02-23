//  TODO
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

void clear_queue(queue<pair<int, int> > &q) {
    queue<pair<int, int> > empty;
    swap(q, empty);
}

queue<pair<int, int> > bfs(pair<int, int> pos, char **map, bool **visited, int N, int M) {
    int d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    queue<pair<int, int> > q;
    int next_i = 0, next_j = 0;

    for (int i = 0; i < 4; i++) {
        next_i = pos.first + d[i][0];
        next_j = pos.second + d[i][1];
        if (next_i < 0 || next_j < 0 || next_i > N - 1 || next_j > M - 1) {
            continue;
        }
        if (map[next_i][next_j] == '1' && !visited[next_i][next_j]) {
            visited[next_i][next_j] = true;
            q.push(make_pair(next_i, next_j));
            if (next_i == N && next_j == M) {
                // result.push_back(count);
                break;
            }
        }

    }

    return q;
}

int main() {
    int N = 0, M = 0, count = 0;
    queue<pair<int, int> > q, tmp;
    pair<int, int> root;
    bool finish = false;

    cin >> N >> M;
    char **map = new char*[N];
    bool **v = new bool*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new char[M + 1];
        v[i] = new bool[M];
        fill_n(v[i], M, false);
    }

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    tmp.push(make_pair(0, 0));
    v[0][0] = true;
    while (!tmp.empty()) {
        q = tmp;
        clear_queue(tmp);

        count++;
        while (!q.empty()) {
            root = q.front();
            if (root.first == N - 1 && root.second == M - 1) {
                finish = true;
                break;
            }
            queue<pair<int, int> > result = bfs(root, map, v, N, M);
            while (!result.empty()) {
                tmp.push(result.front());
                result.pop();
            }
            q.pop();
        }
        if (finish) {
            break;
        }
    }

    cout << count << "\n";

    for (int i = 0; i < N; i++) {
        delete[] map[i];
        delete[] v[i];
    }
    delete[] v;
    delete[] map;
    return 0;
}
