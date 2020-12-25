#include <iostream>
#include <cmath>
using namespace std;

void lazy_update(int *tree, bool *lazy, int start, int end, int node) {
    if (!lazy[node]) {
        return;
    }

    tree[node] = (end - start + 1) - tree[node];
    if (start != end) {
        lazy[node << 1] = !lazy[node << 1];
        lazy[node << 1 | 1] = !lazy[node << 1 | 1];
    }
    lazy[node] = false;
}

void update_tree(int *tree, bool *state, bool *lazy, int start, int end, int l_range, int r_range, int node) {
    lazy_update(tree, lazy, start, end, node);
    if (r_range < start || end < l_range) {
        return;
    }

    if (l_range <= start && end <= r_range) {
        lazy[node] = !lazy[node];
        lazy_update(tree, lazy, start, end, node);
        return;
    }

    int mid = (start + end) / 2;
    update_tree(tree, state, lazy, start, mid, l_range, r_range, node << 1);
    update_tree(tree, state, lazy, mid + 1, end, l_range, r_range, node << 1 | 1);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query_tree(int *tree, bool *lazy, int start, int end, int l_range, int r_range, int node) {
    lazy_update(tree, lazy, start, end, node);
    if (r_range < start || end < l_range) {
        return 0;
    }

    if (l_range <= start && end <= r_range) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int l = query_tree(tree, lazy, start, mid, l_range, r_range, node << 1);
    int r = query_tree(tree, lazy, mid + 1, end, l_range, r_range, node << 1 | 1);
    return l + r;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, H, O, S, T;
    cin >> N >> M;
    bool *state = new bool[N + 1];
    H = ceil(log2(N)) + 1;
    int *tree = new int[1 << H];
    bool *lazy = new bool[1 << H];
    fill_n(tree, 1 << H, 0);
    fill_n(lazy, 1 << H, false);

    while (M--) {
        cin >> O >> S >> T;
        if (O == 0) {
            update_tree(tree, state, lazy, 1, N, S, T, 1);
        } else {
            cout << query_tree(tree, lazy, 1, N, S, T, 1) << "\n";
        }
    }

    delete[] tree;
    delete[] state;
    delete[] lazy;
    return 0;
}
