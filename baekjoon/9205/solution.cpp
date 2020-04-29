#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

bool bfs(pair<int, int> start, pair<int, int> destination, int N, pair<int, int> *store, bool *v) {
    queue<pair<int, int> > q;
    pair<int, int> top;
    bool happy = false;

    q.push(start);
    while (!q.empty()) {
        top = q.front();
        q.pop();

        if (abs(top.first - destination.first) + abs(top.second - destination.second) <= 1000) {
            happy = true;
            break;
        }

        for (int i = 0; i < N; i++) {
            if (abs(top.first - store[i].first) + abs(top.second - store[i].second) <= 1000 && !v[i]) {
                q.push(store[i]);
                v[i] = true;
            }
        }
    }

    return happy;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, N = 0;
    pair<int, int> home, destination;
    cin >> T;

    while (T--) {
        cin >> N >> home.first >> home.second;
        bool *v = new bool[N];
        fill_n(v, N, false);
        pair<int, int> *store = new pair<int, int>[N];
        for (int i = 0; i < N; i++) {
            cin >> store[i].first >> store[i].second;
        }
        cin >> destination.first >> destination.second;

        cout << (bfs(home, destination, N, store, v) ? "happy" : "sad") << "\n";

        delete[] v;
        delete[] store;
    }

    return 0;
}
