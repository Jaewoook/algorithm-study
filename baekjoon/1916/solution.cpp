#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <utility>
using namespace std;

#define INF -1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0, from = 0, to = 0, cost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pair<int, int> top;
    cin >> N >> M;

    vector<pair<int, int> > *a = new vector<pair<int, int> >[N + 1];
    int *distance = new int[N + 1];
    fill_n(distance, N + 1, INF);
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> cost;

        a[from].push_back(make_pair(cost, to));
    }
    cin >> from >> to;

    distance[from] = 0;
    pq.push(make_pair(0, from));
    while (!pq.empty()) {
        top = pq.top();
        pq.pop();

        if (top.first > distance[top.second]) {
            continue;
        }

        for (vector<pair<int, int> >::iterator i = a[top.second].begin(); i != a[top.second].end(); i++) {
            if (distance[(*i).second] == INF || top.first + (*i).first < distance[(*i).second]) {
                distance[(*i).second] = top.first + (*i).first;
                pq.push(make_pair(top.first + (*i).first, (*i).second));
            }
        }
    }

    cout << distance[to] << "\n";

    delete[] a;
    delete[] distance;
    return 0;
}
