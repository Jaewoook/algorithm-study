#include <iostream>
#include <cmath>
using namespace std;

void init_tree(int *tree, int *num, int start, int end, int node) {
    if (start == end) {
        tree[node] = start;
        return;
    }

    int mid = (start + end) / 2;
    init_tree(tree, num, start, mid, node << 1);
    init_tree(tree, num, mid + 1, end, node << 1 | 1);
    tree[node] = num[tree[node << 1]] <= num[tree[node << 1 | 1]] ? tree[node << 1] : tree[node << 1 | 1];
}

int query_tree(int *tree, int *num, int start, int end, int l_range, int r_range, int node) {
    if (r_range < start || end < l_range) {
        return -1;
    }

    if (l_range <= start && end <= r_range) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int r1 = query_tree(tree, num, start, mid, l_range, r_range, node << 1);
    int r2 = query_tree(tree, num, mid + 1, end, l_range, r_range, node << 1 | 1);
    if (r1 > -1 && r2 > -1) {
        return num[r1] <= num[r2] ? r1 : r2;
    }
    return r1 > -1 ? r1 : r2;
}

long long get_max_size(int *tree, int *num, int N, int l_range, int r_range) {
    int min_index = query_tree(tree, num, 1, N, l_range, r_range, 1);
    long long max_size = (long long) num[min_index] * (long long) (r_range - l_range + 1);

    if (l_range < min_index) {
        max_size = max(max_size, get_max_size(tree, num, N, l_range, min_index - 1));
    }
    if (min_index < r_range) {
        max_size = max(max_size, get_max_size(tree, num, N, min_index + 1, r_range));
    }

    return max_size;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    int H = ceil(log2(N)) + 1;
    int *tree = new int[1 << H];
    int *num = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init_tree(tree, num, 1, N, 1);
    cout << get_max_size(tree, num, N, 1, N) << "\n";

    delete[] num;
    delete[] tree;
    return 0;
}
