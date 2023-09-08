#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int direction[3][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 } };

void print_map(vector<vector<bool>> &map) {
    cout << "\ndebug map\n";
    for (auto i = map.begin(); i != map.end(); i++) {
        for (auto j = (*i).begin(); j != (*i).end(); j++) {
            cout << (*j == true ? "+" : " ") << " ";
        }
        cout << "\n";
    }
}

int dfs(vector<vector<bool>> &map, vector<vector<bool>> &visited, int &N, int &M, int &D, int &ladder_width) {
    bool new_direction = false;
    int next_row, next_col;
    int dest_pos = (D - 1) * 2;
    stack<pair<int, int>> stack;
    pair<int, int> curr;

    stack.push(make_pair(M - 1, dest_pos));
    visited[M - 1][dest_pos] = true;

    while (!stack.empty()) {
        curr = stack.top();
        new_direction = false;

        for (int i = 0; i < 3; i++) {
            next_row = curr.first + direction[i][0];
            next_col = curr.second + direction[i][1];

            if (next_row < 0 || next_col < 0 || next_col >= ladder_width) {
                continue;
            }

            if (map[next_row][next_col] == false || visited[next_row][next_col]) {
                continue;
            }

            stack.push(make_pair(next_row, next_col));
            visited[next_row][next_col] = true;
            new_direction = true;

            if (next_row == 0) {
                return next_col / 2 + 1;
            }
            break;
        }

        if (!new_direction) {
            stack.pop();
        }
    }

    return -10;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, line_size, ladder_width;
    string line;
    vector<vector<bool>> map, visited;
    cin >> T;

    while (T--) {
        int N, M, D;
        cin >> N >> M >> D;

        ladder_width = N * 2 - 1;
        map = vector<vector<bool>>(M, vector<bool>(ladder_width, false));
        visited = vector<vector<bool>>(M, vector<bool>(ladder_width, false));

        cin.ignore();
        for (int i = 0; i < M; i++) {
            getline(cin, line);

            line_size = line.size();
            for (int j = 0; j < line_size; j++) {
                if (line[j] == '+') {
                    map[i][j] = true;
                }
            }
        }

        int result = dfs(map, visited, N, M, D, ladder_width);

        cout << result << "\n";
    }

    return 0;
}


// sample input
// 2
// 6 10 4
// + + + + + +
// + + +++ +++
// +++ + + + +
// + +++ +++ +
// + + + + + +
// +++ + + +++
// + + +++ + +
// + + + + + +
// +++ + +++ +
// + + + + + +
// 4 10 2
// + + + +
// +++ + +
// + + +++
// +++ + +
// + +++ +
// + + + +
// +++ +++
// + + + +
// + +++ +
// + + + +
