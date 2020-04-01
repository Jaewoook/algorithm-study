#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void clear_queue(queue<int> &q) {
    queue<int> empty;
    swap(q, empty);
}

int bfs(int start, int end, vector<int> *a, bool *visited) {
    queue<int> q, depth;
    bool should_pop = false, found = false;
    int root = 0, result = 0;
    vector<int>::iterator iter;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        result++;
        depth = q;
        clear_queue(q);

        while (!depth.empty()) {
            root = depth.front();
            should_pop = true;

            for (iter = a[root].begin(); iter != a[root].end(); iter++) {
                if (!visited[*iter]) {
                    q.push(*iter);
                    visited[*iter] = true;
                    should_pop = false;
                    if (*iter == end) {
                        found = true;
                    }
                }
            }

            if (should_pop) {
                depth.pop();
            }
            if (found) {
                break;
            }
        }

        if (found) {
            break;
        }
        if (q.empty()) {
            result = -1;
        }

    }

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, start = 0, end = 0, tmp = 0, x = 0, y = 0;

    cin >> N;
    vector<int> *a = new vector<int>[N + 1];
    bool *visited = new bool[N + 1];
    fill_n(visited, N + 1, false);

    cin >> start >> end >> tmp;

    while (tmp--) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    cout << bfs(start, end, a, visited) << "\n";

    delete[] a;
    delete[] visited;
    return 0;
}
