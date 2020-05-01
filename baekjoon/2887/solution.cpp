//  TODO
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Plannet {
    int id, x, y, z;
};

struct Tunnel {
    int first_id, second_id, cost;
};

bool asc_by_x(Plannet a, Plannet b) {
    return a.x < b.x;
}

bool asc_by_y(Plannet a, Plannet b) {
    return a.y < b.y;
}

bool asc_by_z(Plannet a, Plannet b) {
    return a.z < b.z;
}

int compute_cost(Plannet a, Plannet b) {
    return min(min(abs(a.x - b.x), abs(a.y - b.y)), abs(a.z - b.z));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    cin >> N;
    Plannet *plannets = new Plannet[N];
    for (int i = 0; i < N; i++) {
        plannets[i].id = i + 1;
        cin >> plannets[i].x >> plannets[i].y >> plannets[i].z;
    }

    Tunnel *x_tunnels = new Tunnel[N - 1];
    sort(plannets, plannets + N, asc_by_x);
    for (int i = 0; i < N - 1; i++) {
        x_tunnels[i].first_id = plannets[i].id;
        x_tunnels[i].second_id = plannets[i + 1].id;
        x_tunnels[i].cost = compute_cost(plannets[i], plannets[i + 1]);
    }
    Tunnel *y_tunnels = new Tunnel[N - 1];
    sort(plannets, plannets + N, asc_by_y);
    for (int i = 0; i < N - 1; i++) {
        y_tunnels[i].first_id = plannets[i].id;
        y_tunnels[i].second_id = plannets[i + 1].id;
        y_tunnels[i].cost = compute_cost(plannets[i], plannets[i + 1]);
    }
    Tunnel *z_tunnels = new Tunnel[N - 1];
    sort(plannets, plannets + N, asc_by_z);
    for (int i = 0; i < N - 1; i++) {
        z_tunnels[i].first_id = plannets[i].id;
        z_tunnels[i].second_id = plannets[i + 1].id;
        z_tunnels[i].cost = compute_cost(plannets[i], plannets[i + 1]);
    }

    delete[] plannets;
    delete[] x_tunnels;
    delete[] y_tunnels;
    delete[] z_tunnels;
    return 0;
}
