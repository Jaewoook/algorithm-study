#include <iostream>
using namespace std;

int find_root_city(int n, int *city) {
    if (city[n] != n) {
        return city[n] = find_root_city(city[n], city);
    }
    return n;
}

void union_city(int a, int b, int *city) {
    if (a < b) {
        if (city[b] != b) {
            union_city(city[b], a, city);
        }
        city[b] = a;
    } else {
        if (city[b] != b) {
            union_city(city[a], b, city);
        }
        city[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, M = 0, connected = -1;
    bool possible = true;
    cin >> N >> M;
    int *city = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        city[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> connected;

            if (connected == 1 && find_root_city(i, city) != find_root_city(j, city)) {
                union_city(i, j, city);
            }
        }
    }

    connected = -1;
    while (M--) {
        cin >> N;
        if (connected == -1) {
            connected = find_root_city(N, city);
        }
        if (connected != find_root_city(N, city)) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << "\n";

    delete[] city;
    return 0;
}
