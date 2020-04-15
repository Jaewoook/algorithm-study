#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

void dfs(int start, int weight, vector<pair<int, int> > *a, bool *v, int &far_node, int &distance) {
    bool is_end = true;
    v[start] = true;

    for (vector<pair<int, int> >::iterator iter = a[start].begin(); iter != a[start].end(); iter++) {
        if (!v[(*iter).first]) {
            is_end = false;
            dfs((*iter).first, weight + (*iter).second, a, v, far_node, distance);
        }
    }

    if (is_end && weight > distance) {
        distance = weight;
        far_node = start;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, n1 = 0, n2 = 0, w = 0, distance = 0;
    cin >> N;
    vector<pair<int, int> > *a = new vector<pair<int, int> >[N + 1];

    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2 >> w;

        a[n1].push_back(make_pair(n2, w));
        a[n2].push_back(make_pair(n1, w));
    }

    bool *v = new bool[N + 1];
    int far_node = 0;
    fill_n(v, N + 1, false);
    dfs(1, 0, a, v, far_node, distance);

    fill_n(v, N + 1, false);
    dfs(far_node, 0, a, v, far_node, distance);

    cout << distance << "\n";
    delete[] a;
    delete[] v;
    return 0;
}
