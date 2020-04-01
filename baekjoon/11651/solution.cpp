#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 0, x = 0, y = 0;
    vector<pair<int, int> > v;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x >> y;

        v.push_back(make_pair(y, x));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < T; i++) {
        cout << v[i].second << " " << v[i].first << "\n";
    }

    return 0;
}
