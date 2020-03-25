#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

void clear_queue(queue<pair<int, int> > &q) {
    queue<pair<int, int> > empty;
    swap(q, empty);
}

int bfs(vector<vector<int> > &map, vector<vector<bool> > &v, int N, int M) {
    int time = 0, gram_time = 0, result = 0;
    queue<pair<int, int> > q, tmp;
    pair<int, int> root;
    int next_i = 0, next_j = 0;
    bool finished = false;

    q.push(make_pair(0, 0));
    while (!q.empty()) {
        root = q.front();

        for (int i = 0; i < 4; i++) {
            next_i = root.first + d[i][0];
            next_j = root.second + d[i][1];

            if (next_i < 0 || next_i > N - 1 || next_j < 0 || next_j > M - 1) {
                continue;
            }
            if (map[next_i][next_j] != 1 && !v[next_i][next_j]) {
                v[next_i][next_j] = true;
                tmp.push(make_pair(next_i, next_j));
                if (map[next_i][next_j] == 2) {
                    gram_time = time + 1;
                    gram_time += M - 1 - next_j;
                    gram_time += N - 1 - next_i;
                }
                if (next_i == N - 1 && next_j == M - 1) {
                    finished = true;
                    time++;
                }
            }
        }

        if (finished) {
            break;
        }
        q.pop();

        if (q.empty()) {
            time++;
            q = tmp;
            clear_queue(tmp);
        }
    }

    time = v[N - 1][M - 1] ? time : 0;
    if (time > 0) {
        if (gram_time > 0) {
            result = time > gram_time ? gram_time : time;
        } else {
            result = time;
        }
    } else {
        result = gram_time > 0 ? gram_time : 0;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0, T = 0;

    cin >> N >> M >> T;
    vector<vector<int> > map(N, vector<int>(M, 0));
    vector<vector<bool> > v(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    v[0][0] = true;
    int result = bfs(map, v, N, M);
    if (result > 0 && result <= T) {
        cout << result << "\n";
    } else {
        cout << "Fail\n";
    }

    return 0;
}
