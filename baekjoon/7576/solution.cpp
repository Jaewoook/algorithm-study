#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

void clear_queue(queue<pair<int, int> > &q) {
    queue<pair<int, int> > empty;
    swap(q, empty);
}

queue<pair<int, int> > bfs(pair<int, int> root, int **box, bool **visited, int row, int col) {
    int d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    queue<pair<int, int> > q;
    int next_i = 0, next_j = 0;

    for (int i = 0; i < 4; i++) {
        next_i = root.first + d[i][0];
        next_j = root.second + d[i][1];

        if (next_i < 0 || next_j < 0 || next_i > row || next_j > col) {
            continue;
        }
        if (box[next_i][next_j] == 0 && !visited[next_i][next_j]) {
            q.push(make_pair(next_i, next_j));
            visited[next_i][next_j] = true;
        }
    }

    return q;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M = 0, N = 0;
    cin >> M >> N;
    int **box = new int*[N];
    bool **ripened = new bool*[N];

    queue<pair<int, int> > root, tmp;
    int day = 0;

    for (int i = 0; i < N; i++) {
        box[i] = new int[M];
        ripened[i] = new bool[M];
        fill_n(ripened[i], M, false);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                tmp.push(make_pair(i, j));
                ripened[i][j] = true;
            }
        }
    }

    if (tmp.size() == M * N) {
        day = 0;
    } else {
        day = -1;
        while (!tmp.empty()) {
            root = tmp;
            clear_queue(tmp);
            while (!root.empty()) {
                queue<pair<int, int> > result = bfs(root.front(), box, ripened, N - 1, M - 1);
                while (!result.empty()) {
                    tmp.push(result.front());
                    result.pop();
                }
                root.pop();
            }
            day++;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (box[i][j] != -1 && !ripened[i][j]) {
                    day = -1;
                    break;
                }
            }
        }
    }

    cout << day << "\n";

    for (int i = 0; i < N; i++) {
        delete[] box[i];
        delete[] ripened[i];
    }
    delete[] box;
    delete[] ripened;
    return 0;
}
