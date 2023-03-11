#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define T_TREE pair<int, pair<int, int>>
#define C_TREE priority_queue<T_TREE, vector<T_TREE>, greater<T_TREE>>
#define T_ENERGY vector<vector<int>>

const int DIRECTION[8][2] = {
    { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }
};

void print_forest(C_TREE &trees, T_ENERGY &energy) {
    int size = energy.size();
    cout << "\n\n=== tree information ===\n";
    C_TREE tmp_trees(trees);
    while (!tmp_trees.empty()) {
        auto node = tmp_trees.top();
        tmp_trees.pop();

        cout << node.first << " | " << node.second.first << ", " << node.second.second << "\n";
    }

    cout << "\n=== energy information ===\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << energy[i][j] << " ";
        }
        cout << "\n";
    }
}

void simulate(C_TREE &trees, T_ENERGY &energy, int M, int K) {
    C_TREE next_trees;
    T_ENERGY next_energy(M, vector<int>(M, 0));
    while (!trees.empty()) {
        auto node = trees.top();
        trees.pop();

        if (node.first <= energy[node.second.first][node.second.second]) {
            // comsume energy
            energy[node.second.first][node.second.second] -= node.first;
            node.first++;
            // create child tree
            if (node.first % 5 == 0) {
                for (int i = 0; i < 8; i++) {
                    int next_r = node.second.first + DIRECTION[i][0];
                    int next_c = node.second.second + DIRECTION[i][1];

                    if (next_r < 0 || next_c < 0 || next_r >= M || next_c >= M) {
                        continue;
                    }
                    auto child_node = make_pair(1, make_pair(next_r, next_c));
                    next_trees.push(child_node);
                }
            }
            next_trees.push(node);
        } else {
            int new_energy = node.first / 2;
            next_energy[node.second.first][node.second.second] += new_energy;
        }
    }
    trees = next_trees;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            next_energy[i][j] += energy[i][j] + K;
        }
    }
    energy = next_energy;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, M, C, K, P, t_row, t_col, t_age;
    cin >> T;
    while (T--) {
        cin >> M >> C >> K >> P;

        C_TREE trees;
        // vector<vector<vector<int>>> forest(M, vector<vector<int> >(M, vector<int>(0)));
        vector<vector<int> > energy(M, vector<int>(M, 0));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                cin >> energy[i][j];
            }
        }

        while (C--) {
            cin >> t_row >> t_col >> t_age;
            // forest[t_row][t_col].push_back(t_age);
            trees.push(make_pair(t_age, make_pair(t_row, t_col)));
        }
        // print_forest(trees, energy);

        while (P--) {
            simulate(trees, energy, M, K);
        }
        cout << trees.size() << "\n";
    }
    return 0;
}

// 2
// 5 3 1 2
// 5 5 5 5 5
// 5 5 5 5 5
// 5 5 5 5 5
// 5 5 5 5 5
// 5 5 5 5 5
// 1 1 2
// 2 3 3
// 3 4 4
// 4 2 12 430
// 4 12 16 2
// 5 12 7 5
// 19 15 8 11
// 12 2 5 10
// 2 2 17
// 3 1 2
