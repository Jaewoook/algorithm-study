#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

void init_tree(ll *tree, const ll *num, const int start, const int end, const int node) {
    if (start == end) {
        tree[node] = num[start];
        return;
    }

    int mid = (start + end) / 2;
    init_tree(tree, num, start, mid, node << 1);
    init_tree(tree, num, mid + 1, end, (node << 1) + 1);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

void update_tree(ll *tree, const int start, const int end, const int target, const ll val, const int node) {
    if (target < start || end < target) {
        return;
    }
    tree[node] += val;
    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;
    update_tree(tree, start, mid, target, val, node << 1);
    update_tree(tree, mid + 1, end, target, val, (node << 1) + 1);
}

ll query_tree(const ll *tree, const int start, const int end, const int l_range, const int r_range, const int node) {
    if (r_range < start || end < l_range) {
        return 0;
    }

    if (l_range <= start && end <= r_range) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    ll r1 = query_tree(tree, start, mid, l_range, r_range, node << 1);
    ll r2 = query_tree(tree, mid + 1, end, l_range, r_range, (node << 1) + 1);
    return r1 + r2;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    int H = ceil(log2(N)) + 1;
    ll *num = new ll[N + 1];
    ll *tree = new ll[1 << H];

    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    init_tree(tree, num, 1, N, 1);

    int x, y, a, b;
    ll diff;
    while (Q--) {
        cin >> x >> y >> a >> b;
        diff = b - num[a];

        if (x > y) swap(x, y);
        cout << query_tree(tree, 1, N, x, y, 1) << "\n";
        update_tree(tree, 1, N, a, diff, 1);
        num[a] = b;
    }

    delete[] num;
    delete[] tree;
    return 0;
}
