#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    string name;
    set<string> n_set;
    vector<string> nm_arr;
    cin >> N >> M;

    while (N--) {
        cin >> name;

        n_set.insert(name);
    }

    while (M--) {
        cin >> name;

        auto result = n_set.find(name);
        if (result != n_set.end()) {
            nm_arr.push_back(name);
        }
    }

    sort(nm_arr.begin(), nm_arr.end());
    cout << nm_arr.size() << "\n";
    for (auto it = nm_arr.begin(); it != nm_arr.end(); it++) {
        cout << (*it) << "\n";
    }

    return 0;
}
