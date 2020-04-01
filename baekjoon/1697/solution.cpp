#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void clear_queue(queue<int> &q) {
    queue<int> empty;
    swap(q, empty);
}

queue<int> bfs(int v, bool visited[100001], int K) {
    queue<int> q;
    int next[3] = { v - 1, v + 1, v * 2 };

    for (int i = 0; i < 3; i++) {
        if (next[i] < 0 || next[i] > 100000) {
            continue;
        }
        if (!visited[next[i]]) {
            q.push(next[i]);
            if (next[i] == K) {
                break;
            }
        }
    }

    return q;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool visited[100001] = {};
    int N = 0, K = 0, time = 0;
    cin >> N >> K;

    bool finish = false;
    queue<int> start, tmp;

    tmp.push(N);
    while (!tmp.empty()) {
        finish = false;
        start = tmp;
        clear_queue(tmp);

        while (!start.empty()) {
            if (start.front() == K) {
                finish = true;
                break;
            }
            if (!visited[start.front()]) {
                visited[start.front()] = true;
                queue<int> result = bfs(start.front(), visited, K);
                while (!result.empty()) {
                    tmp.push(result.front());
                    result.pop();
                }
            }
            start.pop();
        }
        if (finish) {
            break;
        }
        time++;
    }

    cout << time << "\n";

    return 0;
}
