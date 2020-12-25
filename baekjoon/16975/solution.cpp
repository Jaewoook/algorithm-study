#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

void init_tree(ll *tree, ll *num, int start, int end, int node) {
    if (start == end) {
        tree[node] = num[start];
        return;
    }

    int mid = (start + end) / 2;
    init_tree(tree, num, start, mid, node << 1);
    init_tree(tree, num, mid + 1, end, node << 1 | 1);
}

void lazy_update(ll *tree, int start, int end, int node) {
    if (tree[node] == 0) {
        return;
    }

    if (start != end) {
        tree[node << 1] += tree[node];
        tree[node << 1 | 1] += tree[node];
        tree[node] = 0;
    }
}

void update_tree(ll *tree, int start, int end, int l_range, int r_range, int val, int node) {
    lazy_update(tree, start, end, node);
    if (r_range < start || end < l_range) {
        return;
    }
    if (l_range <= start && end <= r_range) {
        tree[node] += val;
        lazy_update(tree, start, end, node);
        return;
    }

    int mid = (start + end) / 2;
    update_tree(tree, start, mid, l_range, r_range, val, node << 1);
    update_tree(tree, mid + 1, end, l_range, r_range, val, node << 1 | 1);
}

ll query_tree(ll *tree, int start, int end, int index, int node) {
    lazy_update(tree, start, end, node);
    if (index < start || end < index) {
        return 0;
    }
    if (start == end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    ll l = query_tree(tree, start, mid, index, node << 1);
    ll r = query_tree(tree, mid + 1, end, index, node << 1 | 1);
    return l + r;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, M, H, a, b, c, d;
    cin >> N;
    ll *num = new ll[N + 1];
    H = ceil(log2(N)) + 1;
    ll *tree = new ll[1 << H];
    fill_n(tree, 1 << H, 0);
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init_tree(tree, num, 1, N, 1);

    cin >> M;
    while (M--) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c >> d;
            update_tree(tree, 1, N, b, c, d, 1);
        } else {
            cout << query_tree(tree, 1, N, b, 1) << "\n";
        }
    }

    delete[] num;
    delete[] tree;
    return 0;
}
