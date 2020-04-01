#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dfs(int start, vector<int> &v, vector<int> &visited, vector<int> &checked) {
    vector<int> d;
    int next = v[start];
    d.push_back(start);

    while (true) {
        if (visited[next]) {
            if (checked[next] == checked[start]) {
                return visited[d.back()] + 1 - visited[next];
            }
            break;
        } else {
            d.push_back(next);
            checked[next] = start;
            visited[next] = d.size();
            next = v[next];
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 0, N = 0, tmp = 0;

    cin >> T;

    while (T--) {
        cin >> N;

        vector<int> v, checked, visited;
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            v.push_back(tmp - 1);
            checked.push_back(i);
            visited.push_back(0);
        }

        tmp = 0;
        for (int i = 0; i < N; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                int result = dfs(i, v, visited, checked);
                tmp += result;
            }
        }

        cout << N - tmp << "\n";
    }

    return 0;
}
