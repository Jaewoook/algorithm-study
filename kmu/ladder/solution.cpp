#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int DIRECTION[3][2] = {
    { 0, -1 }, { 0, 1 }, { -1, 0 }
};

// void print_map(vector<vector<bool> > &map) {
//     cout << "\nprint map\n\n";
//     for (auto i = map.begin(); i != map.end(); i++) {
//         for (auto j = (*i).begin(); j != (*i).end(); j++) {
//             cout << *j << " ";
//         }
//         cout << "\n";
//     }
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool pos_updated = false;
    int T, n, m, col_size, d, line_size, dest_index, cur_r, cur_c, next_r, next_c;
    string line;
    cin >> T;
    while (T--) {
        cin >> n >> m >> d;
        cin.ignore();
        col_size = n * 2 - 1;
        dest_index = d * 2 - 2;
        vector<vector<bool> > map(m, vector<bool>(col_size, false));
        vector<vector<bool> > visited(m, vector<bool>(col_size, false));

        for (int i = 0; i < m; i++) {
            getline(cin, line);
            line_size = line.size();
            for (int j = 0; j < col_size; j++) {
                if (line[j] == '+') {
                    map[i][j] = true;
                }
            }
        }
        // print_map(map);

        cur_r = m - 1;
        cur_c = dest_index;
        visited[cur_r][cur_c] = true;
        while (true) {
            pos_updated = false;
            // cout << "cur row: " << cur_r << " cur col: " << cur_c << "\n";

            for (int i = 0; i < 3; i++) {
                next_r = cur_r + DIRECTION[i][0];
                next_c = cur_c + DIRECTION[i][1];

                if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= line_size) {
                    continue;
                }

                if (map[next_r][next_c] == false || visited[next_r][next_c] == true) {
                    continue;
                }

                cur_c = next_c;
                cur_r = next_r;\
                visited[cur_r][cur_c] = true;
                pos_updated = true;
                break;
            }

            if (!pos_updated) {
                break;
            }
        }
        // cout << "current col: " << cur_c << "\n";
        cout << (cur_c + 2) / 2 << "\n";
    }
    return 0;
}


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
