#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

unsigned int board[20][20];
int N;
unsigned int max_score;

bool equal(unsigned int (*original)[20], unsigned int (*moved)[20]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (original[i][j] != moved[i][j]) {
                return false;
            }
        }
    }

    return true;
}

unsigned int find_max(unsigned int (*board)[20]) {
    unsigned int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result = max(result, board[i][j]);
        }
    }

    return result;
}

void copy_board(unsigned int (*from)[20], unsigned int (*to)[20]) {
    for (int i = 0; i < N; i++) {
        copy(from[i], from[i] + N, to[i]);
    }
}

void move(unsigned int (*board)[20], unsigned int direction) {
    stack<int> num_stack;

    if (direction == 0) {
        for (int col = 0; col < N; col++) {
            int row;
            for (row = N - 1; row >= 0; row--) {
                if (!board[row][col]) continue;
                num_stack.push(board[row][col]);
                board[row][col] = 0;
            }
            row = 0;
            while (!num_stack.empty()) {
                if (board[row][col] == 0) {
                    board[row][col] = num_stack.top();
                } else if (board[row][col] == num_stack.top()) {
                    board[row][col] *= 2;
                    row++;
                } else {
                    row++;
                    board[row][col] = num_stack.top();
                }
                num_stack.pop();
            }
        }
    } else if (direction == 1) {
        for (int row = 0; row < N; row++) {
            int col;
            for (col = N - 1; col >= 0; col--) {
                if (!board[row][col]) continue;
                num_stack.push(board[row][col]);
                board[row][col] = 0;
            }
            col = 0;
            while (!num_stack.empty()) {
                if (board[row][col] == 0) {
                    board[row][col] = num_stack.top();
                } else if (board[row][col] == num_stack.top()) {
                    board[row][col] *= 2;
                    col++;
                } else {
                    col++;
                    board[row][col] = num_stack.top();
                }
                num_stack.pop();
            }
        }
    } else if (direction == 2) {
        for (int col = 0; col < N; col++) {
            int row;
            for (row = 0; row < N; row++) {
                if (!board[row][col]) continue;
                num_stack.push(board[row][col]);
                board[row][col] = 0;
            }
            row = N - 1;
            while (!num_stack.empty()) {
                if (board[row][col] == 0) {
                    board[row][col] = num_stack.top();
                } else if (board[row][col] == num_stack.top()) {
                    board[row][col] *= 2;
                    row--;
                } else {
                    row--;
                    board[row][col] = num_stack.top();
                }
                num_stack.pop();
            }
        }
    } else if (direction == 3) {
        for (int row = 0; row < N; row++) {
            int col;
            for (col = 0; col < N; col++) {
                if (!board[row][col]) continue;
                num_stack.push(board[row][col]);
                board[row][col] = 0;
            }
            col = N - 1;
            while (!num_stack.empty()) {
                if (board[row][col] == 0) {
                    board[row][col] = num_stack.top();
                } else if (board[row][col] == num_stack.top()) {
                    board[row][col] *= 2;
                    col--;
                } else {
                    col--;
                    board[row][col] = num_stack.top();
                }
                num_stack.pop();
            }
        }
    }
}

void compute(unsigned int (*board)[20], const int depth) {
    if (depth > 10) {
        return;
    }

    unsigned int high_score = find_max(board);
    unsigned int moved[20][20];

    //  move to top
    for (int i = 0; i < 4; i++) {
        copy_board(board, moved);
        move(moved, i);
        high_score = max(high_score, find_max(moved));
        max_score = max(max_score, high_score);
        if (!equal(board, moved) && high_score * 1 << (10 - depth) > max_score) {
            compute(moved, depth + 1);
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    compute(board, 1);
    cout << max_score << "\n";

    return 0;
}
