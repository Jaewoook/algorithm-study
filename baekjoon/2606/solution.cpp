#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0, n1 = 0, n2 = 0, count = 0;

    cin >> N >> M;
    vector<int> *map = new vector<int>[N + 1];
    bool *visited = new bool[N + 1];
    queue<int> q;
    bool should_pop = false;
    int root = 1;

    while (M--) {
        cin >> n1 >> n2;
        map[n1].push_back(n2);
        map[n2].push_back(n1);
    }

    q.push(1);
    fill_n(visited, N + 1, false);
    visited[1] = true;

    while (!q.empty()) {
        root = q.front();
        should_pop = true;

        for (vector<int>::iterator iter = map[root].begin(); iter != map[root].end(); iter++) {
            if (!visited[*iter]) {
                visited[*iter] = true;
                q.push(*iter);
                should_pop = true;
                count++;
            }
        }

        if (should_pop) {
            q.pop();
        }
    }

    cout << count << "\n";

    delete[] map;
    delete[] visited;
    return 0;
}
