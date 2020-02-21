#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int bfs(pair<int, int> v, char **map, bool **visited, int N) {
    int d[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    int count = 1;
    bool should_pop = false;
    queue<pair<int, int> > q;
    pair<int, int> root;
    visited[v.first][v.second] = true;
    int next_i = 0, next_j = 0;

    q.push(v);
    while (!q.empty()) {
        root = q.front();
        should_pop = true;

        for (int i = 0; i < 4; i++) {
            next_i = root.first + d[i][0];
            next_j = root.second + d[i][1];

            if (next_i > N || next_i < 0 || next_j > N || next_j < 0) {
                continue;
            }

            if (map[next_i][next_j] == '1' && !visited[next_i][next_j]) {
                should_pop = false;
                q.push(make_pair(next_i, next_j));
                visited[next_i][next_j] = true;
                count++;
            }
        }

        if (should_pop) {
            q.pop();
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;

    cin >> N;
    char **map = new char*[N];
    bool ** visited = new bool*[N];
    vector<int> count;
    for (int i = 0; i < N; i++) {
        map[i] = new char[N + 1];
        visited[i] = new bool[N];
    }

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && !visited[i][j]) {
                count.push_back(bfs(make_pair(i, j), map, visited, N - 1));
            }
        }
    }

    sort(count.begin(), count.end());
    cout << count.size() << "\n";
    for (vector<int>::iterator iter = count.begin(); iter != count.end(); iter++) {
        cout << *iter << "\n";
    }

    for (int i = 0; i < N; i++) {
        delete[] map[i];
        delete[] visited[i];
    }
    delete[] map;
    delete[] visited;
    return 0;
}
