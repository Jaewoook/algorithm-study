#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> a) {
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
}

void dfs(int N, int M, vector<int> &a) {
    if (a.size() == M) {
        print(a);
    } else {
        int start = a.size() > 0 ? a.back() : 1;
        for (int i = start; i <= N; i++) {
            a.push_back(i);
            dfs(N, M, a);
            a.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);

    vector<int> a;
    int N = 0, M = 0;
    cin >> N >> M;

    dfs(N, M, a);
    return 0;
}
