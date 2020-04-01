#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define NONE 0
#define LEFT 1
#define RIGHT 2
using namespace std;

bool bfs(vector<int> *a, int *v, int val) {
    queue<int> q;
    q.push(val);
    int root = 0, flag = NONE;
    bool should_pop = false;

    while (!q.empty()) {
        root = q.front();
        flag = v[root];
        should_pop = true;

        for (vector<int>::iterator iter = a[root].begin(); iter != a[root].end(); iter++) {
            if (v[*iter] == NONE) {
                should_pop = false;
                v[*iter] = flag == LEFT ? RIGHT : LEFT;
                 q.push(*iter);
            } else if (v[*iter] == flag) {
                return false;
            }
        }

        if (should_pop) {
            q.pop();
        }
    }

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int K = 0, V = 0, E = 0, n1 = 0, n2 = 0;
    cin >> K;

    while (K--) {
        cin >> V >> E;
        bool result = true;
        vector<int> *a = new vector<int>[V + 1];
        int *v = new int[V + 1];
        fill_n(v, V + 1, NONE);

        while (E--) {
            cin >> n1 >> n2;
            a[n1].push_back(n2);
            a[n2].push_back(n1);
        }

        for (int i = 1; i <= V; i++) {
            if (v[i] == NONE) {
                v[i] = LEFT;
                if (bfs(a, v, i) == false) {
                    result = false;
                    break;
                }
            }
        }

        cout << (result ? "YES" : "NO") << "\n";

        delete[] a;
        delete[] v;
    }

    return 0;
}
