#include <iostream>
using namespace std;

int find_root(int x, int *set) {
    if (x != set[x]) {
        return set[x] = find_root(set[x], set);
    }
    return x;
}

void union_set(int a, int b, int *set) {
    if (find_root(a, set) == find_root(b, set)) {
        return;
    }

    if (a < b) {
        if (set[b] != b) {
            union_set(set[b], a, set);
        }
        set[b] = a;
    } else {
        if (set[a] != a) {
            union_set(set[a], b, set);
        }
        set[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, M = 0, command = 0, left = 0, right = 0;
    cin >> N >> M;

    int *set = new int[N + 1];
    for (int i = 0; i <= N; i++) {
        set[i] = i;
    }

    while (M--) {
        cin >> command >> left >> right;

        if (command) {
            cout << (find_root(left, set) == find_root(right, set) ? "YES" : "NO") << "\n";
        } else {
            if (left != right) {
                union_set(left, right, set);
            }
        }
    }

    delete[] set;
    return 0;
}
