#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, a = 0, b = 0;
    vector<pair<int, int> > line;
    vector<int> lis;
    vector<int>::iterator bound;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        line.push_back(make_pair(a, b));
    }
    sort(line.begin(), line.end());

    for (int i = 0; i < N; i++) {
        if (lis.empty()) {
            lis.push_back(line[i].second);
        } else {
            if (lis.back() > line[i].second) {
                bound = lower_bound(lis.begin(), lis.end(), line[i].second);
                if (*bound != line[i].second) {
                    *bound = line[i].second;
                }
            } else if (lis.back() != line[i].second) {
                lis.push_back(line[i].second);
            }
        }
    }

    cout << line.size() - lis.size() << "\n";

    return 0;
}
