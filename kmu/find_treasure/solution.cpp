#include <iostream>
#include <string>
#include <vector>
using namespace std;

char get_direction(char direction, char prev_direction) {
    if (prev_direction == 'F') {
        switch (direction) {
        case 'F':
            return 'F';
        case 'R':
            return 'R';
        case 'L':
            return 'L';
        case 'B':
            return 'B';
        }
    }
    if (prev_direction == 'R') {
        switch (direction) {
        case 'F':
            return 'R';
        case 'R':
            return 'B';
        case 'L':
            return 'F';
        case 'B':
            return 'L';
        }
    }
    if (prev_direction == 'L') {
        switch (direction) {
        case 'F':
            return 'L';
        case 'R':
            return 'F';
        case 'L':
            return 'B';
        case 'B':
            return 'R';
        }
    }
    if (prev_direction == 'B') {
        switch (direction) {
        case 'F':
            return 'B';
        case 'R':
            return 'L';
        case 'L':
            return 'R';
        case 'B':
            return 'F';
        }
    }

    return NULL;
}

pair<int, int> get_next_pos(pair<int, int> pos, char direction, int move) {
    pair<int, int> next_pos = pos;

    switch (direction) {
    case 'F':
        next_pos.first += move;
        break;
    case 'R':
        next_pos.second += move;
        break;
    case 'L':
        next_pos.second -= move;
        break;
    case 'B':
        next_pos.first -= move;
        break;
    }
    return next_pos;
}

bool is_in(vector<char> &v, char d) {
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it == d) {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, N, move;
    char next_direction, prev_direction;
    pair<int, int> pos;
    string ab;
    vector<vector<string>> map;
    vector<vector<vector<char>>> v;
    cin >> T;
    while (T--) {
        pos = {0, 0};
        prev_direction = 'B';
        cin >> N;
        map = vector<vector<string>>(N, vector<string>(N, ""));
        v = vector<vector<vector<char>>>(N, vector<vector<char>>(N, vector<char>()));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        v[0][0].push_back('B');
        while (true) {
            next_direction = get_direction(map[pos.first][pos.second].at(0), prev_direction);
            move = map[pos.first][pos.second].at(1) - '0';

            pos = get_next_pos(pos, next_direction, move);
            prev_direction = next_direction;

            if (is_in(v[pos.first][pos.second], next_direction)) {
                break;
            }
            v[pos.first][pos.second].push_back(next_direction);
        }

        cout << pos.first << " " << pos.second << "\n";
    }

    return 0;
}

// sample input
//
// 2
// 5
// B1  L1  R2  F1  R2
// F2  R2  L2  R2  F2
// B1  L1  R2  L1  R1
// R3  R3  B1  R2  R1
// R1  R2  B1  L3  R2
// 5
// B3  B1  R2  L2  R2
// B1  F3  B1  R2  B1
// F2  F1  F2  B2  R3
// R4  R1  F3  L2  R3
// R1  F1  B3  R2  B2

// sample output
//
// 1 3
// 2 2
