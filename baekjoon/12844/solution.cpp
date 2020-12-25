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
    tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}

void update_lazy(int *tree, int *lazy, int start, int end, int node) {
    if (!lazy[node]) return;

    tree[node] ^= lazy[node] * ((end - start + 1) % 2);
    if (start != end) {
        lazy[node << 1] ^= lazy[node];
        lazy[node << 1 | 1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void xor_tree(int *tree, int *lazy, int start, int end, int l_range, int r_range, int modifier, int node) {
    update_lazy(tree, lazy, start, end, node);
    if (r_range < start || end < l_range) return;
    if (l_range <= start && end <= r_range) {
        lazy[node] ^= modifier;
        update_lazy(tree, lazy, start, end, node);
        return;
    }

    int mid = (start + end) / 2;
    xor_tree(tree, lazy, start, mid, l_range, r_range, modifier, node << 1);
    xor_tree(tree, lazy, mid + 1, end, l_range, r_range, modifier, node << 1 | 1);
    tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}

int query_tree(int *tree, int *lazy, int start, int end, int l_range, int r_range, int node) {
    update_lazy(tree, lazy, start, end, node);
    if (r_range < start || end < l_range) return 0;
    if (l_range <= start && end <= r_range) return tree[node];

    int mid = (start + end) / 2;
    int l = query_tree(tree, lazy, start, mid, l_range, r_range, node << 1);
    int r = query_tree(tree, lazy, mid + 1, end, l_range, r_range, node << 1 | 1);
    return l ^ r;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, M, H, A, I, J, K;
    cin >> N;
    H = ceil(log2(N)) + 1;
    int *n = new int[N + 1];
    int *tree = new int[1 << H];
    int *lazy = new int[1 << H];
    fill_n(tree, 1 << H, 0);
    fill_n(lazy, 1 << H, 0);

    for (int i = 1; i <= N; i++) {
        cin >> n[i];
    }
    init_tree(tree, n, 1, N, 1);

    cin >> M;
    while (M--) {
        cin >> A >> I >> J;
        I++;
        J++;
        if (A == 1) {
            cin >> K;
            xor_tree(tree, lazy, 1, N, I, J, K, 1);
        } else {
            cout << query_tree(tree, lazy, 1, N, I, J, 1) << "\n";
        }
    }

    delete[] n;
    delete[] tree;
    delete[] lazy;
    return 0;
}
