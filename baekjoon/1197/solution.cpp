#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int first_node;
    int second_node;
    int weight;
};

int find_root_node(int x, int *set) {
    if (x != set[x]) {
        return set[x] = find_root_node(set[x], set);
    }
    return x;
}

void union_set(int a, int b, int *set) {
    if (a > b) {
        if (set[a] != a) {
            union_set(set[a], b, set);
        }
        set[a] = b;
    } else {
        if (set[b] != b) {
            union_set(set[b], a, set);
        }
        set[b] = a;
    }
}

bool sort_by_weight(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int V = 0, E = 0, min_weight = 0;
    cin >> V >> E;
    Edge *edges = new Edge[E];
    int *set = new int[V + 1];
    for (int i = 1; i <= V; i++) {
        set[i] = i;
    }

    for (int i = 0; i < E; i++) {
        cin >> edges[i].first_node >> edges[i].second_node >> edges[i].weight;
    }
    sort(edges, edges + E, sort_by_weight);

    for (int i = 0; i < E; i++) {
        if (find_root_node(edges[i].first_node, set) != find_root_node(edges[i].second_node, set)) {
            union_set(edges[i].first_node, edges[i].second_node, set);
            min_weight += edges[i].weight;
        }
    }

    cout << min_weight << "\n";

    delete[] set;
    delete[] edges;
    return 0;
}
