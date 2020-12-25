#include <iostream>
#include <cmath>
using namespace std;

void init_tree(int *tree, int *n, int start, int end, int node) {
    if (start == end) {
        tree[node] = n[start];
        return;
    }

    int mid = (start + end) / 2;
    init_tree(tree, n, start, mid, node << 1);
    init_tree(tree, n, mid + 1, end, node << 1 | 1);
}

void lazy_update(int *tree, int start, int end, int node) {
    if (tree[node] == 0 || start == end) return;

    tree[node << 1] ^= tree[node];
    tree[node << 1 | 1] ^= tree[node];
    tree[node] = 0;
}

void update_tree(int *tree, int start, int end, int l_range, int r_range, int modifier, int node) {
    lazy_update(tree, start, end, node);
    if (r_range < start || end < l_range) return;
    if (l_range <= start && end <= r_range) {
        tree[node] ^= modifier;
        lazy_update(tree, start, end, node);
        return;
    }

    int mid = (start + end) / 2;
    update_tree(tree, start, mid, l_range, r_range, modifier, node << 1);
    update_tree(tree, mid + 1, end, l_range, r_range, modifier, node << 1 | 1);
}

int query_tree(int *tree, int start, int end, int index, int node) {
    lazy_update(tree, start, end, node);
    if (index < start || end < index) return 0;
    if (start == end) return tree[node];

    int mid = (start + end) / 2;
    int l = query_tree(tree, start, mid, index, node << 1);
    int r = query_tree(tree, mid + 1, end, index, node << 1 | 1);
    return max(l, r);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, H, T, A, B, C;
    cin >> N;
    int *n = new int[N + 1];
    H = ceil(log2(N)) + 1;
    int *tree = new int[1 << H];
    fill_n(tree, 1 << H, 0);
    for (int i = 1; i <= N; i++) {
        cin >> n[i];
    }
    init_tree(tree, n, 1, N, 1);

    cin >> M;
    while (M--) {
        cin >> T >> A;
        A++;
        if (T == 1) {
            cin >> B >> C;
            B++;
            update_tree(tree, 1, N, A, B, C, 1);
        } else {
            cout << query_tree(tree, 1, N, A, 1) << "\n";
        }
    }

    delete[] n;
    delete[] tree;
    return 0;
}
