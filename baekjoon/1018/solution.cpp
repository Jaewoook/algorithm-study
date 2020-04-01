#include <iostream>
using namespace std;

int check(char board[50][50], int i, int j) {
    char w = 0, b = 0;
    int change = 0, change_row = 0;

    for (int _i = i; _i < i + 8; _i += 2) {
        change_row = 0;
        for (int _j = j; _j < j + 8; _j++) {
            if (_j % 2 == 0 && board[_i][_j] != 'W') {
                change_row++;
            } else if (_j % 2 == 1 && board[_i][_j] != 'B') {
                change_row++;
            }
        }
        change += change_row;
    }
    for (int _i = i + 1; _i < i + 8; _i += 2) {
        change_row = 0;
        for (int _j = j; _j < j + 8; _j++) {
            if (_j % 2 == 1 && board[_i][_j] != 'W') {
                change_row++;
            } else if (_j % 2 == 0 && board[_i][_j] != 'B') {
                change_row++;
            }
        }
        change += change_row;
    }

    return change > 32 ? 64 - change : change;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, sum = 0, start_row = 0;
    char prev = 0;
    int tmp = 0, count = 64;
    char board[50][50] = { 0, };
    int pattern_count[50] = { 0, };
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N - 7; i++) {
        for (int j = 0; j < M - 7; j++) {
            tmp = check(board, i, j);
            if (count > tmp) {
                count = tmp;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
