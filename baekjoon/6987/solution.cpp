#include <iostream>
#include <algorithm>
using namespace std;

const int match[15][2] = {
    {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
    {1, 2}, {1, 3}, {1, 4}, {1, 5},
    {2, 3}, {2, 4}, {2, 5},
    {3, 4}, {3, 5},
    {4, 5}
};

void dfs(int n, int simulation[6][3], int result[4][6][3], bool *valid) {
    if (n == 15) {
        for (int i = 0; i < 4; i++) {
            if (valid[i]) {
                continue;
            }

            bool is_valid = true;
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 3; k++) {
                    if (result[i][j][k] != simulation[j][k]) {
                        is_valid = false;
                        break;
                    }
                }
                if (!is_valid) {
                    break;
                }
            }
            if (is_valid) {
                valid[i] = true;
            }
        }

        return;
    }

    for (int i = 0; i < 3; i++) {
        simulation[match[n][0]][i]++;
        simulation[match[n][1]][2 - i]++;
        dfs(n + 1, simulation, result, valid);
        simulation[match[n][0]][i]--;
        simulation[match[n][1]][2 - i]--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool valid[4] = {};
    int teams[4][6][3], simulation[6][3];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> teams[i][j][k];
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        simulation[i][0] = simulation[i][1] = simulation[i][2] = 0;
    }

    //  simulate all matches
    dfs(0, simulation, teams, valid);

    for (int i = 0; i < 4; i++) {
        cout << valid[i] << " ";
    }
    cout << "\n";
    return 0;
}
