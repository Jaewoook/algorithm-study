#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, x = 0;
    cin >> T;
    priority_queue<pair<int, int>, vector<pair<int, int> >,  greater<pair<int, int> > > pq;

    while (T--) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        } else {
            pq.push(make_pair(abs(x), x));
        }
    }

    return 0;
}
