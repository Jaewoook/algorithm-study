#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<int> *al, bool *v) {
    int count = 0;
    queue<int> q;
    int root = 1;
    bool should_pop = false;

    q.push(1);
    v[1] = true;
    while (!q.empty()) {
        should_pop = true;
        root = q.front();

        for (vector<int>::iterator iter = al[root].begin(); iter != al[root].end(); iter++) {
            if (!v[*iter]) {
                q.push(*iter);
                v[*iter] = true;
                should_pop = false;
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

    int T = 0, N = 0, M = 0, a = 0, b = 0;

    cin >> T;
    while (T--) {
        cin >> N >> M;

        vector<int> *al = new vector<int>[N + 1];
        bool *v = new bool[N + 1];
        fill_n(v, N + 1, false);

        while (M--) {
            cin >> a >> b;
            al[a].push_back(b);
            al[b].push_back(a);
        }

        cout << bfs(al, v) << "\n";

        delete[] al;
        delete[] v;
    }

    return 0;
}
