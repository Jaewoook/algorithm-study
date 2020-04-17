#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> find_no_requires(int *build_requires, int N) {
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        if (build_requires[i] == 0) {
            result.push_back(i);
        }
    }
    return result;
}

void topological_sort(vector<int> start_nodes, int *build_info, int N, vector<int> *build_map, int *build_requires, int w, int *time) {
    queue<int> q, tmp;
    int front;

    for (vector<int>::iterator iter = start_nodes.begin(); iter != start_nodes.end(); iter++) {
        q.push(*iter);
    }

    while (build_requires[w] && !q.empty()) {
        front = q.front();

        for (vector<int>::iterator iter = build_map[front].begin(); iter != build_map[front].end(); iter++) {
            time[*iter] = max(time[front] + build_info[*iter], time[*iter]);

            build_requires[*iter]--;
            if (build_requires[*iter] == 0) {
                q.push(*iter);
                if (*iter == w) {
                    break;
                }
            }
        }

        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 0, N = 0, K = 0, first = 0, last = 0, W = 0;
    vector<int> start_nodes;

    cin >> T;
    while (T--) {
        cin >> N >> K;
        int *build_info = new int[N + 1];
        vector<int> *build_map = new vector<int>[N + 1];
        int *build_requires = new int[N + 1];
        fill_n(build_requires, N + 1, 0);
        int *result = new int[N + 1];
        fill_n(result, N + 1, 0);

        for (int i = 1; i <= N; i++) {
            cin >> build_info[i];
            result[i] = build_info[i];
        }
        for (int i = 0; i < K; i++) {
            cin >> first >> last;
            build_map[first].push_back(last);
            build_requires[last]++;
        }

        cin >> W;

        start_nodes = find_no_requires(build_requires, N);
        topological_sort(start_nodes, build_info, N, build_map, build_requires, W, result);
        cout << result[W] << "\n";

        delete[] build_info;
        delete[] build_map;
        delete[] build_requires;
        delete[] result;
    }

    return 0;
}
