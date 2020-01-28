#include <iostream>
using namespace std;
#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3

int rotate(int direction) {
    return (direction + 3) % 4;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, r = 0, c = 0, d = 0, count = 1;

    cin >> N >> M;
    int **map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
    }

    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        map[r][c] = 2;
        switch (rotate(d)) {
            case TOP:
                if (map[r - 1][c] == 0) {
                    d = TOP;
                    r -= 1;
                    count++;
                    continue;
                }
                break;
            case RIGHT:
                if (map[r][c + 1] == 0) {
                    d = RIGHT;
                    c += 1;
                    count++;
                    continue;
                }
                break;
            case BOTTOM:
                if (map[r + 1][c] == 0) {
                    d = BOTTOM;
                    r += 1;
                    count++;
                    continue;
                }
                break;
            case LEFT:
                if (map[r][c - 1] == 0) {
                    d = LEFT;
                    c -= 1;
                    count++;
                    continue;
                }
                break;
        }
        if (!(map[r + 1][c] > 0 && map[r - 1][c] > 0 && map[r][c + 1] > 0 && map[r][c - 1] > 0)) {
            d = rotate(d);
            continue;
        }
        switch (d) {
            case TOP:
                if (map[r + 1][c] != 1) {
                    r += 1;
                    continue;
                }
                break;
            case RIGHT:
                if (map[r][c - 1] != 1) {
                    c -= 1;
                    continue;
                }
                break;
            case BOTTOM:
                if (map[r - 1][c] != 1) {
                    r -= 1;
                    continue;
                }
                break;
            case LEFT:
                if (map[r][c + 1] != 1) {
                    c += 1;
                    continue;
                }
                break;
        }
        break;
    }

    cout << count << "\n";

    for (int i = 0; i < N; i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}
