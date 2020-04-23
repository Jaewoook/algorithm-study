#include <iostream>
#include <vector>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R = 0, C = 0, next_i = 0, next_j = 0, sea = 0;
    cin >> R >> C;

    char **map = new char*[R];
    char **new_map = new char*[R];
    vector<int> except_row, except_col;
    for (int i = 0; i < R; i++) {
        map[i] = new char[C];
        new_map[i] = new char[C];
    }

    for (int i = 0; i < R; i++) {
        cin >> map[i];
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            sea = 0;
            if (map[i][j] == 'X') {
                for (int k = 0; k < 4; k++) {
                    next_i = i + d[k][0], next_j = j + d[k][1];
                    if (next_i < 0 || next_i >= R || next_j < 0 || next_j >= C) {
                        sea++;
                        continue;
                    }
                    if (map[next_i][next_j] == '.') {
                        sea++;
                    }
                }
                if (sea > 2) {
                    new_map[i][j] = '.';
                } else {
                    new_map[i][j] = 'X';
                }
            } else {
                new_map[i][j] = '.';
            }
        }
    }

    bool is_all_sea = true;
    for (int i = 0; i < R; i++) {
        is_all_sea = true;
        for (int j = 0; j < C; j++) {
            if (new_map[i][j] == 'X') {
                is_all_sea = false;
                break;
            }
        }
        if (is_all_sea) {
            except_row.push_back(i);
        } else {
            break;
        }
    }
    for (int i = R - 1; i >= 0; i--) {
        is_all_sea = true;
        for (int j = 0; j < C; j++) {
            if (new_map[i][j] == 'X') {
                is_all_sea = false;
                break;
            }
        }
        if (is_all_sea) {
            except_row.push_back(i);
        } else {
            break;
        }
    }

    for (int i = 0; i < C; i++) {
        is_all_sea = true;
        for (int j = 0; j < R; j++) {
            if (new_map[j][i] == 'X') {
                is_all_sea = false;
                break;
            }
        }
        if (is_all_sea) {
            except_col.push_back(i);
        } else {
            break;
        }
    }
    for (int i = C - 1; i >= 0; i--) {
        is_all_sea = true;
        for (int j = 0; j < R; j++) {
            if (new_map[j][i] == 'X') {
                is_all_sea = false;
                break;
            }
        }
        if (is_all_sea) {
            except_col.push_back(i);
        } else {
            break;
        }
    }

    for (int i = 0; i < R; i++) {
        is_all_sea = false;
        for (vector<int>::iterator iter = except_row.begin(); iter != except_row.end(); iter++) {
            if ((*iter) == i) {
                is_all_sea = true;
                break;
            }
        }
        if (is_all_sea) {
            continue;
        }

        for (int j = 0; j < C; j++) {
            is_all_sea = false;
            for (vector<int>::iterator iter = except_col.begin(); iter != except_col.end(); iter++) {
                if ((*iter) == j) {
                    is_all_sea = true;
                    break;
                }
            }
            if (is_all_sea) {
                continue;
            }
            cout << new_map[i][j];
        }
        cout << "\n";
    }


    for (int i = 0; i < R; i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}
