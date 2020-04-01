#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> a) {
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
}

void dfs(int N, int M, vector<int> &a, vector<bool> &v) {
    if (a.size() == M) {
        print(a);
    } else {
        int start = a.size() == 0 ? 1 : a.back();
        for (int i = start; i <= N; i++) {
            if (!v[i]) {
                v[i] = true;
                a.push_back(i);
                dfs(N, M, a, v);
                v[i] = false;
                a.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, M = 0;
    cin >> N >> M;
    vector<bool> v(N + 1, false);
    vector<int> a;

    dfs(N, M, a, v);

    return 0;
}
