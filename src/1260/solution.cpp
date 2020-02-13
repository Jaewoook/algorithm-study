#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void dfs(int v, vector<int> *a, int n) {
    bool *visited = new bool[n + 1];
    fill_n(visited, n + 1, false);

    int top = 0;
    bool flag = false;

    stack<int> stack;
    vector<int>::iterator iter;
    stack.push(v);
    visited[v] = true;
    cout << v << " ";

    while (!stack.empty()) {
        top = stack.top();
        flag = false;

        for (iter = a[top].begin(); iter != a[top].end(); iter++) {
            if (!visited[*iter]) {
                stack.push(*iter);
                visited[*iter] = true;
                flag = true;
                cout << *iter << " ";
                break;
            }
        }

        if (!flag) {
            stack.pop();
        }
    }

    delete[] visited;
}

void bfs(int v, vector<int> *a, int n) {
    bool *visited = new bool[n + 1];
    fill_n(visited, n + 1, false);

    queue<int> q;
    vector<int>::iterator iter;
    q.push(v);
    visited[v] = true;

    cout << v << " ";

    int root = 0;

    while (!q.empty()) {
        root = q.front();
        q.pop();

        for (iter = a[root].begin(); iter != a[root].end(); iter++) {
            if (!visited[*iter]) {
                q.push(*iter);
                visited[*iter] = true;
                cout << *iter << " ";
            }
        }
    }

    delete[] visited;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, V = 0, v1 = 0, v2 = 0;

    cin >> N >> M >> V;
    vector<int> *a = new vector<int>[N + 1];

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;

        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }
    for (int i = 1; i <= N; i++) {
        sort(a[i].begin(), a[i].end());
    }

    dfs(V, a, N);
    cout << "\n";
    bfs(V, a, N);

    delete[] a;
    return 0;
}
