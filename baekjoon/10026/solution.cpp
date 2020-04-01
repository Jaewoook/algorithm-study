#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int d[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

void dfs(int row, int col, vector<string> &pic, vector<vector<bool> > &v, int N, bool rg) {
    int next_i = 0, next_j = 0;
    for (int i = 0; i < 4; i++) {
        next_i = row + d[i][0];
        next_j = col + d[i][1];
        if (next_i < 0 || next_j < 0 || next_i > N - 1 || next_j > N - 1) {
            continue;
        }
        if (v[next_i][next_j]) {
            continue;
        }

        if (rg && ((pic[row][col] == 'B' && pic[next_i][next_j] == 'B') || (pic[row][col] != 'B' && pic[next_i][next_j] != 'B'))) {
            v[next_i][next_j] = true;
            dfs(next_i, next_j, pic, v, N, rg);
        } else if (!rg && pic[row][col] == pic[next_i][next_j]) {
            v[next_i][next_j] = true;
            dfs(next_i, next_j, pic, v, N, rg);
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    cin >> N;

    vector<string> pic(N, "");
    for (int i = 0; i < N; i++) {
        cin >> pic[i];
    }

    vector<vector<bool> > v1(N, vector<bool>(N, false));
    vector<vector<bool> > v2(N, vector<bool>(N, false));
    int rgb = 0, rg_b = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!v1[i][j]) {
                v1[i][j] = true;
                rgb++;
                dfs(i, j, pic, v1, N, false);
            }
            if (!v2[i][j]) {
                v2[i][j] = true;
                rg_b++;
                dfs(i, j, pic, v2, N, true);
            }
        }
    }

    cout << rgb << " " << rg_b << "\n";

    return 0;
}
