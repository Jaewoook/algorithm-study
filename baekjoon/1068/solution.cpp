#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int root;
    vector<int> child;
};

void remove_nodes(int start_node, Node *nodes) {
    vector<int>::iterator i = nodes[start_node].child.begin();
    while (!nodes[start_node].child.empty()) {
        remove_nodes(*i, nodes);
        nodes[start_node].child.erase(i);
    }
    nodes[start_node].root = -2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, x = 0;
    cin >> N;
    Node *nodes = new Node[N];

    for (int i = 0; i < N; i++) {
        cin >> nodes[i].root;
        if (nodes[i].root > -1) {
            nodes[nodes[i].root].child.push_back(i);
        }
    }

    cin >> x;
    remove_nodes(x, nodes);
    for (int i = 0; i < N; i++) {
        for (vector<int>::iterator it = nodes[i].child.begin(); it != nodes[i].child.end(); it++) {
            if (*it == x) {
                nodes[i].child.erase(it);
                break;
            }
        }
    }

    x = 0;
    for (int i = 0; i < N; i++) {
        if (nodes[i].root > -2 && nodes[i].child.empty()) {
            x++;
        }
    }

    cout << x << "\n";

    delete[] nodes;
    return 0;
}
