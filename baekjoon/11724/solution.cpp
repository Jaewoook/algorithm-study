#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void dfs(int v, vector<int> *a, bool *visited) {
    stack<int> s;
    vector<int>::iterator iter;
    int root = v;
    bool should_remove = true;
    visited[v] = true;
    s.push(v);

    while (!s.empty()) {
        should_remove = true;
        root = s.top();
        for (iter = a[root].begin(); iter != a[root].end(); iter++) {
            if (!visited[*iter]) {
                s.push(*iter);
                root = *iter;
                visited[*iter] = true;
                should_remove = false;
                break;
            }
        }

        if (should_remove) {
            s.pop();
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, ln = 0, rn = 0, count = 0;

    cin >> N >> M;
    vector<int> *a = new vector<int>[N + 1];
    bool *visited = new bool[N + 1];
    fill_n(visited, N + 1, false);

    for (int i = 0; i < M; i++) {
        cin >> ln >> rn;

        a[ln].push_back(rn);
        a[rn].push_back(ln);

    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            count++;
            dfs(i, a, visited);
        }
    }

    cout << count << "\n";

    delete[] a;
    delete[] visited;
    return 0;
}
