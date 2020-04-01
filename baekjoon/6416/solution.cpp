#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
using namespace std;

//  BFS
long long get_root_node(vector<long long> *a, bool *v, long long node) {
    if (a[node].size() == 0) {
        return node;
    } else {
        for (vector<long long>::iterator iter = a[node].begin(); iter != a[node].end(); iter++) {
            if (!v[*iter]) {
                v[*iter] = true;
                return get_root_node(a, v, *iter);
            }
        }
    }
    return 0;
}

bool dfs(vector<long long> *a, bool *v, long long node) {
    for (vector<long long>::iterator iter = a[node].begin(); iter != a[node].end(); iter++) {
        if (!v[*iter]) {
            v[*iter] = true;
            if (!dfs(a, v, *iter)) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool exit = false, is_tree = true;
    long long case_no = 1, a = 0, b = 0, max_range = 0;
    set<int> node_set;
    vector<pair<long long, long long> > nodes;

    while (true) {
        is_tree = true;
        max_range = 0;

        while (true) {
            cin >> a >> b;

            if (a <= 0 && b <= 0) {
                exit = a < 0 && b < 0;
                break;
            }
            max_range = max(a, b) > max_range ? max(a, b) : max_range;
            nodes.push_back(make_pair(a, b));
            node_set.insert(a);
            node_set.insert(b);
        }
        if (exit) {
            break;
        }

        if (max_range > 0) {
            vector<long long> *a = new vector<long long>[max_range + 1];
            vector<long long> *reverse_a = new vector<long long>[max_range + 1];
            bool *v = new bool[max_range + 1];
            bool *reverse_v = new bool[max_range + 1];
            fill_n(v, max_range + 1, false);
            fill_n(reverse_v, max_range + 1, false);

            for (vector<pair<long long, long long> >::iterator iter = nodes.begin(); iter != nodes.end(); iter++) {
                a[(*iter).first].push_back((*iter).second);
                reverse_a[(*iter).second].push_back((*iter).first);
            }

            long long root = get_root_node(reverse_a, reverse_v, max_range);
            if (root == 0) {
                is_tree = false;
            } else {
                v[root] = true;
                is_tree = dfs(a, v, root);

                if (is_tree) {
                    for (set<int>::iterator iter = node_set.begin(); iter != node_set.end(); iter++) {
                        if (!v[*iter]) {
                            is_tree = false;
                            break;
                        }
                    }
                }
            }

            delete[] a;
            delete[] v;
            delete[] reverse_v;
        }

        nodes.clear();
        node_set.clear();

        cout << "Case " << case_no++ << " is " << (is_tree ? "" : "not ") << "a tree.\n";
    }
    return 0;
}
