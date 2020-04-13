#include <iostream>
#include <algorithm>
using namespace std;

struct Nation {
    int gold, silver, bronze;
};

bool compare(Nation n1, Nation n2) {
    if (n1.gold != n2.gold) {
        return n1.gold > n2.gold;
    }
    if (n1.silver != n2.silver) {
        return n1.silver > n2.silver;
    }
    if (n1.bronze != n2.bronze) {
        return n1.bronze > n2.bronze;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, K = 0, x = 0;

    cin >> N >> K;
    Nation *nations = new Nation[N + 1];

    for (int i = 1; i <= N; i++) {
        cin >> x >> nations[x].gold >> nations[x].silver >> nations[x].bronze;
        if (x == K) {
            nations[0].gold = nations[x].gold;
            nations[0].silver = nations[x].silver;
            nations[0].bronze = nations[x].bronze;
        }
    }

    sort(nations + 1, nations + N + 1, compare);

    for (int i = 1; i <= N; i++) {
        if (nations[0].gold == nations[i].gold && nations[0].silver == nations[i].silver && nations[0].bronze == nations[i].bronze) {
            cout << i << "\n";
            break;
        }
    }

    delete[] nations;
    return 0;
}
