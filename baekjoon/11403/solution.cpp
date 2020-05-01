//  TODO
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

void dfs(int start, vector<int> *map, bool *v, int **result, int N) {
    for (vector<int>::iterator i = map[start].begin(); i != map[start].end(); i++) {
        result[*i][start] = 1;
        if (map[start][*i] == 1) {
            if (!v[*i]) {
                v[*i] = true;
                dfs(*i, map, v, result, N);
                v[*i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, connected = 0;
    cin >> N;

    vector<int> *map = new vector<int>[N];
    int **result = new int*[N];
    bool *v = new bool[N];
    for (int i = 0; i < N; i++) {
        result[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> connected;

            if (connected == 1) {
                map[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        v[i] = true;
        dfs(i, map, v, result, N);
    }

    cout << "\nresult\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < N; i++) {
        delete[] result[i];
    }
    delete[] map;
    delete[] result;
    delete[] v;
    return 0;
}
