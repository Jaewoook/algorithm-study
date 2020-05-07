#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

#define INF -1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int V = 0, E = 0, u = 0, v = 0, w = 0, start = 0;
    pair<int, int> top;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    cin >> V >> E >> start;

    vector<pair<int, int> > *a = new vector<pair<int, int> >[V + 1];
    int *before_v = new int[V + 1];
    int *distance = new int[V + 1];
    fill_n(before_v, V + 1, INF);
    fill_n(distance, V + 1, INF);
    before_v[start] = distance[start] = 0;

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;

        a[u].push_back(make_pair(w, v));
    }

    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        top = pq.top();
        pq.pop();

        if (top.first > distance[top.second]) {
            continue;
        }
        for (vector<pair<int, int> >::iterator i = a[top.second].begin(); i != a[top.second].end(); i++) {
            if (distance[(*i).second] == INF || distance[(*i).second] > top.first + (*i).first) {
                distance[(*i).second] = top.first + (*i).first;
                pq.push(make_pair(top.first + (*i).first, (*i).second));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (distance[i] >= 0) {
            cout <<distance[i] << "\n";
        } else {
            cout << "INF\n";
        }
    }

    delete[] before_v;
    delete[] distance;
    delete[] a;
    return 0;
}
