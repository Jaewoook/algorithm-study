#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x7FFFFFFF

const int d[4][2] = {
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }
};

struct Position {
    int y, x, cost;
    bool operator()(const Position &p1, const Position &p2) {
        return p1.cost > p2.cost;
    }
};

bool is_movable(int x, int y, int M, int N) {
    return !(x < 0 || y < 0 || x >= M || y >= N);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    string input;
    cin >> M >> N;
    vector<vector<bool> > map(N, vector<bool>(M));
    vector<vector<int> > distance(N, vector<int>(M, INF));

    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            map[i][j] = input[j] == '1';
        }
    }

    int next_x, next_y;
    Position current;
    priority_queue<Position, vector<Position>, Position> q;
    q.push({ 0, 0, 0 });
    distance[0][0] = 0;

    while (!q.empty()) {
        current = q.top();
        if (current.x == M - 1 && current.y == N - 1) {
            break;
        }
        q.pop();

        for (int i = 0; i < 4; i++) {
            next_y = current.y + d[i][0];
            next_x = current.x + d[i][1];

            if (!is_movable(next_x, next_y, M, N)) continue;

            if (distance[current.y][current.x] + map[next_y][next_x] < distance[next_y][next_x]) {
                distance[next_y][next_x] = distance[current.y][current.x] + map[next_y][next_x];
                q.push(Position { next_y, next_x, distance[next_y][next_x] });
            }
        }
    }

    cout << distance[N - 1][M - 1] << "\n";

    return 0;
}
