#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v) {
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
}

void dfs(int N, int M, int depth, vector<int> &v, vector<bool> &visited) {
    if (M == depth) {
        print(v);
    } else {
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                v.push_back(i);
                visited[i] = true;
                dfs(N, M, depth + 1, v, visited);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, M = 0;
    vector<int> v;
    vector<bool> visited(N + 1, false);
    cin >> N >> M;

    dfs(N, M, 0, v, visited);

    return 0;
}
