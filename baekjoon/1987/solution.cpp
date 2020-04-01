#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

void dfs(int r, int c, string *board, bool *v, int count, int max_row, int max_col, int &answer) {
    int next_row = 0, next_col = 0;
    for (int i = 0; i < 4; i++) {
        next_row = r + d[i][0];
        next_col = c + d[i][1];

        if (next_row < 0 || next_row > max_row - 1 || next_col < 0 || next_col > max_col - 1) {
            continue;
        }

        if (!v[board[next_row][next_col] - 'A']) {
            v[board[next_row][next_col] - 'A'] = true;
            count++;
            if (count > answer) {
                answer = count;
            }
            dfs(next_row, next_col, board, v, count, max_row, max_col, answer);
            v[board[next_row][next_col] - 'A'] = false;
            count--;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int R = 0, C = 0, count = 0;

    cin >> R >> C;
    string *board = new string[R];
    bool visited[26] = {};

    cin.ignore();
    for (int i = 0; i < R; i++) {
        getline(cin, board[i]);
    }

    visited[board[0][0] - 'A'] = true;
    count = 1;
    dfs(0, 0, board, visited, 1, R, C, count);
    cout << count << "\n";

    delete[] board;
    return 0;
}
