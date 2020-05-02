#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int N = 0, K = 0;
    bool *v = new bool[100001];
    queue<pair<int, int> > q;
    pair<int, int> top;
    int next_i = 0, time = 0;
    bool finished = false;

    cin >> N >> K;

    if (N != K) {
        q.push(make_pair(N, 0));
        v[N] = true;
        while (!q.empty()) {
            top = q.front();
            q.pop();

            if (top.first > 0) {
                for (int i = top.first; i <= 100000; i *= 2) {
                    if (v[i]) {
                        continue;
                    }
                    v[i] = true;
                    q.push(make_pair(i, top.second));
                    if (i == K) {
                        finished = true;
                        time = top.second;
                        break;
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                if (i == 0) {
                    next_i = top.first - 1;
                } else if (i == 1) {
                    next_i = top.first + 1;
                }
                if (next_i < 0 || next_i > 100000 || v[next_i]) {
                    continue;
                }
                v[next_i] = true;
                q.push(make_pair(next_i, top.second + 1));
                if (next_i == K) {
                    finished = true;
                    time = top.second + 1;
                    break;
                }
            }

            if (finished) {
                break;
            }
        }
    }

    cout << time << "\n";

    delete[] v;
    return 0;
}
