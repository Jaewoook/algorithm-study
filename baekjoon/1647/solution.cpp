#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Road {
    int first_house;
    int second_house;
    int cost;
};

bool sort_by_low_cost(Road a, Road b) {
    return a.cost < b.cost;
}

int find_start_house(int h, int *houses) {
    if (h != houses[h]) {
        return houses[h] = find_start_house(houses[h], houses);
    }
    return h;
}

void connect_road(int h1, int h2, int *houses) {
    if (h1 < h2) {
        if (houses[h2] != h2) {
            connect_road(houses[h2], h1, houses);
        }
        houses[h2] = h1;
    } else {
        if (houses[h1] != h1) {
            connect_road(houses[h1], h2, houses);
        }
        houses[h1] = h2;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, min_cost = 0;
    cin >> N >> M;

    Road *road = new Road[M];
    int *houses = new int[N + 1];
    vector<int> costs;
    for (int i = 1; i <= N; i++) {
        houses[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> road[i].first_house >> road[i].second_house >> road[i].cost;
    }
    sort(road, road + M, sort_by_low_cost);

    for (int i = 0; i < M; i++) {
        if (find_start_house(road[i].first_house, houses) != find_start_house(road[i].second_house, houses)) {
            connect_road(road[i].first_house, road[i].second_house, houses);
            costs.push_back(road[i].cost);
        }
    }

    for (int i = 0; i < N - 2; i++) {
        min_cost += costs[i];
    }

    cout << min_cost << "\n";

    delete[] road;
    delete[] houses;
    return 0;
}
