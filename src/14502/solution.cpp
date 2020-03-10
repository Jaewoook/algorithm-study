#include <iostream>
#include <vector>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

void dfs(vector<vector<int> > &map, int row, int col, int row_size, int col_size) {
    int next_i = 0, next_j = 0;
    for (int i = 0; i < 4; i++) {
        next_i = row + d[i][0];
        next_j = col + d[i][1];
        if (next_i < 0 || next_j < 0 || next_i > row_size - 1 || next_j > col_size - 1) {
            continue;
        }
        if (map[next_i][next_j] == 0) {
            map[next_i][next_j] = 2;
            dfs(map, next_i, next_j, row_size, col_size);
        }
    }
}

void search_virus(vector<vector<int> > &map, int row_size, int col_size) {
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (map[i][j] == 2) {
                dfs(map, i, j, row_size, col_size);
            }
        }
    }
}

int count_safe_area(vector<vector<int> > map, int row, int col) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

int create_wall(vector<vector<int> > map, int created, int &safe_area) {
    int row_size = map.size();
    int col_size = map.front().size();

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (map[i][j] > 0) {
                continue;
            }
            map[i][j] = 1;
            created++;
            if (created < 3) {
                create_wall(map, created, safe_area);
            } else {
                vector<vector<int> > modified;
                modified.assign(map.begin(), map.end());
                search_virus(modified, row_size, col_size);
                int result = count_safe_area(modified, row_size, col_size);
                safe_area = safe_area < result ? result : safe_area;
            }
            map[i][j] = 0;
            created--;
        }
    }

    return safe_area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0, result = 0;
    cin >> N >> M;
    vector<vector<int> > map(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    create_wall(map, 0, result);

    cout << result << "\n";

    return 0;
}
