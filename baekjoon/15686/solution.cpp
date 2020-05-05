#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define HOUSE 1
#define CHICKEN 2

int compute_distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int compute_total_distance(vector<pair<int, int> > house, vector<pair<int, int> > chicken) {
    int distance = 0, result = 0;
    for (vector<pair<int, int> >::iterator i = house.begin(); i != house.end(); i++) {
        distance = 0;
        for (vector<pair<int, int> > ::iterator j = chicken.begin(); j != chicken.end(); j++) {
            int d = compute_distance(*i, *j);
            if (distance == 0 || distance > d) {
                distance = d;
            }
        }
        result += distance;
    }

    return result;
}

int select_chicken(int chicken_idx, vector<pair<int, int> > &c, vector<pair<int, int> > chicken, vector<pair<int, int> > house, int M) {
    int distance = 0;
    bool duplicated = false;

    if (c.size() < M) {
        if (chicken_idx >= chicken.size()) {
            return 0;
        }
        c.push_back(chicken[chicken_idx]);
        distance = select_chicken(chicken_idx + 1, c, chicken, house, M);
        c.pop_back();
        int d = select_chicken(chicken_idx + 1, c, chicken, house, M);
        if (d > 0 && distance > 0) {
            distance = min(distance, d);
        } else if (d > 0) {
            distance = d;
        }
    } else if (c.size() == M) {
        distance = compute_total_distance(house, c);
    }

    return distance;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0, total_distance = 0;
    vector<pair<int, int> >::iterator min_pos;
    vector<pair<int, int> > chicken, house, c;
    cin >> N >> M;

    int **map = new int*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == CHICKEN) {
                chicken.push_back(make_pair(i, j));
            } else if (map[i][j] == HOUSE) {
                house.push_back(make_pair(i, j));
            }
        }
    }

    if (M >= chicken.size()) {
        total_distance = compute_total_distance(house, chicken);
    } else {
        total_distance = select_chicken(0, c, chicken, house, M);
    }

    cout << total_distance << "\n";

    for (int i = 0; i < N; i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}
