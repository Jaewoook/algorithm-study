#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pick(int start_i, int start_j, int **map) {
    vector<int> area;
    for (int i = start_i; i < start_i + 2; i++) {
        for (int j = start_j; j < start_j + 2; j++) {
            area.push_back(map[i][j]);
        }
    }

    sort(area.begin(), area.end());
    return area[2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, _N = 0;
    cin >> N;

    _N = N;
    int **map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[N];
        fill_n(map[i], N, 0);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    while (N > 1) {
        for (int i = 0; i < N; i += 2) {
            for (int j = 0; j < N; j += 2) {
                map[i / 2][j / 2] = pick(i, j, map);
            }
        }
        N /= 2;
    }

    cout << map[0][0] << "\n";

    for (int i = 0; i < _N; i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}
