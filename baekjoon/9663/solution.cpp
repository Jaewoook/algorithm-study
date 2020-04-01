#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

bool validate(vector<pair<int, int> > &a, int i, int j) {
    bool valid = true;
    int next_i = 0, next_j = 0;

    for (vector<pair<int, int> >::iterator iter = a.begin(); iter != a.end(); iter++) {
        int queen_i = (*iter).first;
        int queen_j = (*iter).second;
        if (abs(queen_i - i) == abs(queen_j - j) || queen_i == i || queen_j == j) {
            valid = false;
            break;
        }
    }
    return valid;
}

int dfs(int **board, int N, vector<pair<int, int> > &a, int row) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (board[row][i] == 0 && validate(a, row, i)) {
            a.push_back(make_pair(row, i));
            board[row][i] = row * N + i + 1;
            if (a.size() == N) {
                count++;
            } else {
                count += dfs(board, N, a, row + 1);
            }
            board[row][i] = 0;
            a.pop_back();
        }
    }

    return count;
}

int main() {
    int N = 0;
    cin >> N;
    int **board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
    }
    vector<pair<int, int> > a;

    cout << dfs(board, N, a, 0) << "\n";

    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}
