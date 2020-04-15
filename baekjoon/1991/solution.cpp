#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    char current, left, right;
};

void pre_order_traversal(char root, Node nodes[26], bool *v) {
    cout << root;
    if (nodes[root - 'A'].left != '.') {
        pre_order_traversal(nodes[root - 'A'].left, nodes, v);
    }
    if (nodes[root - 'A'].right != '.') {
        pre_order_traversal(nodes[root - 'A'].right, nodes, v);
    }
}

void in_order_traversal(char root, Node nodes[26], bool *v) {
    if (nodes[root - 'A'].left != '.') {
        in_order_traversal(nodes[root - 'A'].left, nodes, v);
    }
    cout << root;
    if (nodes[root - 'A'].right != '.') {
        in_order_traversal(nodes[root - 'A'].right, nodes, v);
    }
}

void post_order_traversal(char root, Node nodes[26], bool *v) {
    if (nodes[root - 'A'].left != '.') {
        post_order_traversal(nodes[root - 'A'].left, nodes, v);
    }
    if (nodes[root - 'A'].right != '.') {
        post_order_traversal(nodes[root - 'A'].right, nodes, v);
    }
    cout << root;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0;
    char root = 0, left = 0, right = 0;
    Node nodes[26] = {};
    bool v[26] = {};
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> root >> left >> right;

        nodes[root - 'A'].current = root;
        nodes[root - 'A'].left = left;
        nodes[root - 'A'].right = right;
    }

    fill_n(v, N, false);
    pre_order_traversal('A', nodes, v);
    cout << "\n";

    fill_n(v, N, false);
    in_order_traversal('A', nodes, v);
    cout << "\n";

    fill_n(v, N, false);
    post_order_traversal('A', nodes, v);
    cout << "\n";

    return 0;
}
