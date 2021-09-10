#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int find_max(vector<vector<int> > board) {
    int result = 0;
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result = max(result, board[i][j]);
        }
    }

    return result;
}

void copy_board(vector<vector<int> > &from, vector<vector<int> > &to) {
    to.assign(from.begin(), from.end());
}

int compute(vector<vector<int> > &board, int N, const int depth) {
    int high_score = 0;
    if (depth > 5) {
        return high_score;
    }

    vector<vector<int> > moved(N);
    for (int i = 0; i < N; i++) {
        moved[i] = vector<int>(N);
    }
    copy_board(board, moved);
    stack<int> num_stack;
    int index;

    //  move to top
    for (int col = 0; col < N; col++) {
        for (int row = N - 1; row >= 0; row--) {
            if (moved[row][col] > 0) {
                num_stack.push(moved[row][col]);
                moved[row][col] = 0;
            }
        }
        index = 0;
        while (!num_stack.empty()) {
            if (moved[index][col] == 0) {
                moved[index][col] = num_stack.top();
            } else if (moved[index][col] == num_stack.top()) {
                moved[index][col] *= 2;
                index++;
            } else {
                index++;
                moved[index][col] = num_stack.top();
            }
            num_stack.pop();
        }
    }
    high_score = max(high_score, find_max(moved));
    high_score = max(high_score, compute(moved, N, depth + 1));

    //  reset board and stack
    copy_board(board, moved);
    num_stack = stack<int>();
    //  move to bottom
    for (int col = 0; col < N; col++) {
        for (int row = 0; row < N; row++) {
            if (moved[row][col] > 0) {
                num_stack.push(moved[row][col]);
                moved[row][col] = 0;
            }
        }
        index = N - 1;
        while (!num_stack.empty()) {
            if (moved[index][col] == 0) {
                moved[index][col] = num_stack.top();
            } else if (moved[index][col] == num_stack.top()) {
                moved[index][col] *= 2;
                index--;
            } else {
                index--;
                moved[index][col] = num_stack.top();
            }
            num_stack.pop();
        }
    }
    high_score = max(high_score, find_max(moved));
    high_score = max(high_score, compute(moved, N, depth + 1));

    //  reset board and stack
    copy_board(board, moved);
    num_stack = stack<int>();
    //  move to left
    for (int row = 0; row < N; row++) {
        for (int col = N - 1; col >= 0; col--) {
            if (moved[row][col] > 0) {
                num_stack.push(moved[row][col]);
                moved[row][col] = 0;
            }
        }
        index = 0;
        while (!num_stack.empty()) {
            if (moved[row][index] == 0) {
                moved[row][index] = num_stack.top();
            } else if (moved[row][index] == num_stack.top()) {
                moved[row][index] *= 2;
                index++;
            } else {
                index++;
                moved[row][index] = num_stack.top();
            }
            num_stack.pop();
        }
    }
    high_score = max(high_score, find_max(moved));
    high_score = max(high_score, compute(moved, N, depth + 1));

    //  reset board and stack
    copy_board(board, moved);
    num_stack = stack<int>();
    //  move to right
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (moved[row][col] > 0) {
                num_stack.push(moved[row][col]);
                moved[row][col] = 0;
            }
        }
        index = N - 1;
        while (!num_stack.empty()) {
            if (moved[row][index] == 0) {
                moved[row][index] = num_stack.top();
            } else if (moved[row][index] == num_stack.top()) {
                moved[row][index] *= 2;
                index--;
            } else {
                index--;
                moved[row][index] = num_stack.top();
            }
            num_stack.pop();
        }
    }
    high_score = max(high_score, find_max(moved));
    high_score = max(high_score, compute(moved, N, depth + 1));

    return high_score;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int> > board(N);
    for (int i = 0; i < N; i++) {
        board[i] = vector<int>(N);
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << compute(board, N, 1) << "\n";

    return 0;
}
