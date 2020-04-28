#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Disjoint {
    int root;
};

struct Edge {
    int cost;
    int first_node;
    int second_node;
};

int find_root_node(int x, Disjoint *set) {
    if (set[x].root != x) {
        return set[x].root = find_root_node(set[x].root, set);
    }
    return x;
}

void union_set(int a, int b, Disjoint *set) {
    if (a > b) {
        if (set[a].root != a) {
            union_set(set[a].root, b, set);
        }
        set[a].root = b;
    } else {
        if (set[b].root != b) {
            union_set(set[b].root, a, set);
        }
        set[b].root = a;

    }
}

bool sort_by_cost(Edge a, Edge b) {
    return a.cost < b.cost;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, total_cost = 0;
    vector<Edge> edges;
    cin >> N >> M;
    Disjoint *set = new Disjoint[N + 1];

    for (int i = 1; i <= N; i++) {
        set[i].root = i;
    }

    for (int i = 0; i < M; i++) {
        Edge edge;
        cin >> edge.first_node >> edge.second_node >> edge.cost;

        if (edge.first_node != edge.second_node) {
            edges.push_back(edge);
        }
    }
    sort(edges.begin(), edges.end(), sort_by_cost);

    for (vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
        if (find_root_node((*it).first_node, set) != find_root_node((*it).second_node, set)) {
            union_set((*it).first_node, (*it).second_node, set);
            total_cost += (*it).cost;
        }
    }

    cout << total_cost << "\n";

    delete[] set;
    return 0;
}
