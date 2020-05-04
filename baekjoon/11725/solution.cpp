#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int start, vector<int> *v, int *root) {
    for (vector<int>::iterator i = v[start].begin(); i != v[start].end(); i++) {
        if (root[*i] < 1) {
            root[*i] = start;
            dfs(*i, v, root);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, first = 0, second = 0;
    cin >> N;
    vector<int> *v = new vector<int>[N + 1];
    int *root = new int[N + 1];
    fill_n(root, N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        cin >> first >> second;

        v[first].push_back(second);
        v[second].push_back(first);
    }

    root[1] = 1;
    dfs(1, v, root);
    for (int i = 2; i <= N; i++) {
        cout << root[i] << "\n";
    }

    delete[] v;
    delete[] root;
    return 0;
}
