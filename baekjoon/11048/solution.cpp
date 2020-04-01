#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0;

    cin >> N >> M;
    int **map = new int*[N + 1];
    for (int i = 0; i <= N; i++) {
        map[i] = new int[M + 1];
        map[i][0] = 0;
    }
    fill_n(map[0], M + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            map[i][j] += max(max(map[i - 1][j - 1], map[i - 1][j]), map[i][j - 1]);
        }
    }

    cout << map[N][M] << "\n";

    for(int i = 0; i < N; i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}
