#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int dfs(int start_i, int start_j, int **board, bool **v, int M, int N) {
    int space = 1;
    stack<pair<int, int> > s;
    pair<int, int> top;
    int next_i = 0, next_j = 0;
    bool should_pop = false;

    v[start_i][start_j] = true;
    s.push(make_pair(start_i, start_j));
    while (!s.empty()) {
        should_pop = true;
        top = s.top();

        for (int i = 0; i < 4; i++) {
            next_i = top.first + d[i][0];
            next_j = top.second + d[i][1];

            if (next_i < 0 || next_i >= M || next_j < 0 || next_j >= N || board[next_i][next_j] == 1 || v[next_i][next_j]) {
                continue;
            }

            v[next_i][next_j] = true;
            should_pop = false;
            s.push(make_pair(next_i, next_j));
            space++;
            break;
        }

        if (should_pop) {
            s.pop();
        }
    }

    return space;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M = 0, N = 0, K = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    vector<int> space;
    cin >> M >> N >> K;

    int **board = new int*[M];
    bool **v = new bool*[M];
    for (int i = 0; i < M; i++) {
        board[i] = new int[N];
        v[i] = new bool[N];
        fill_n(board[i], N, 0);
        fill_n(v[i], N, false);
    }
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                board[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0 && !v[i][j]) {
                space.push_back(dfs(i, j, board, v, M, N));
            }
        }
    }
    sort(space.begin(), space.end());
    cout << space.size() << "\n";
    for (vector<int>::iterator i = space.begin(); i != space.end(); i++) {
        cout << *i << " ";
    }

    for (int i = 0; i < M; i++) {
        delete[] board[i];
        delete[] v[i];
    }
    delete[] board;
    return 0;
}
