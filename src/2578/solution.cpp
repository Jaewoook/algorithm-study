#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int d[4][2] = { { 0, 1 }, { 1, 0 }, { 1, 1 }, { -1, 1 } };

pair<int, int> get_pos(vector<vector<int> > &bingo, int val) {
    pair<int, int> result = make_pair(-1, -1);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (bingo[i][j] == val) {
                result.first = i;
                result.second = j;
                return result;
            }
        }
    }
    return result;
}

bool is_bingo(vector<vector<int> > &bingo, int i, int j, const int *d) {
    if (bingo[i][j] > 0) {
        return false;
    }

    while (true) {
        i += d[0];
        j += d[1];

        if (i < 0 || i > 4 || j > 4) {
            return true;
        }

        if (bingo[i][j] > 0) {
            return false;
        }
    }
}

int check(vector<vector<int> > &bingo) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            //  check vertical directions
            if (i == 0 && is_bingo(bingo, i, j, d[1])) {
                count++;
            }
            //  check horizontal directions
            if (j == 0 && is_bingo(bingo, i, j, d[0])) {
                count++;
            }
            //  check right-down direction
            if (i == 0 && j == 0 && is_bingo(bingo, i, j, d[2])) {
                count++;
            }
            //  check right-up direction
            if (i == 4 && j == 0 && is_bingo(bingo, i, j, d[3])) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int val = 0, result = 0;
    vector<vector<int> > bingo(5, vector<int>(5, 0));
    pair<int, int> pos;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> val;
            if (result == 0) {
                pos = get_pos(bingo, val);
                bingo[pos.first][pos.second] = 0;

                if (check(bingo) >= 3) {
                    result = i * 5 + j + 1;
                }
            }
        }
    }

    cout << result << "\n";

    return 0;
}
