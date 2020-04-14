#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void dfs(int start, int distance, vector<pair<int, int> > *a, vector<bool> &v, int N, int &result, int &far_node) {
    bool is_end = true;
    v[start] = true;
    for (vector<pair<int, int> >::iterator iter = a[start].begin(); iter != a[start].end(); iter++) {
        if (!v[(*iter).first]) {
            is_end = false;
            dfs((*iter).first, distance + (*iter).second, a, v, N, result, far_node);
        }
    }

    if (is_end && distance > result) {
        result = distance;
        far_node = start;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 9, point = 0, node = 0, length = 0, result = 0;
    cin >> N;
    vector<pair<int, int> > *a = new vector<pair<int, int> >[N + 1];

    for (int i = 0; i < N; i++) {
        cin >> point;
        while (true) {
            cin >> node;
            if (node == -1) {
                break;
            }

            cin >> length;
            a[point].push_back(make_pair(node, length));
        }
    }

    int start_node = 0;
    vector<bool> v1(N + 1, false);
    dfs(1, 0, a, v1, N, result, start_node);

    vector<bool> v2(N + 1, false);
    dfs(start_node, 0, a, v2, N, result, start_node);

    cout << result << "\n";

    delete[] a;
    return 0;
}
