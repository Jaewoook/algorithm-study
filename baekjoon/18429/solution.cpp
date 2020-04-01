#include <iostream>
#include <stack>
#include <utility>
using namespace std;

void dfs(int *weight, bool *visited, int &total, int N, int &count, int len) {
    if (len == N) {
        count++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && weight[i] + total >= 0) {
            total += weight[i];
            visited[i] = true;
            dfs(weight, visited, total, N, count, len + 1);
            visited[i] = false;
            total -= weight[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, K = 0, a = 0, total = 0, count = 0;
    cin >> N >> K;
    int *w = new int[N];
    bool *v = new bool[N];

    for (int i = 0; i < N; i++) {
        cin >> a;
        w[i] = a - K;
        v[i] = false;
    }

    dfs(w, v, total, N, count, 0);

    cout << count << "\n";

    delete[] w;
    return 0;
}
