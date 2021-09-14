#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, count = 0, start = 0;
    cin >> N;
    vector<pair<int, int> > time(N);

    for (int i = 0; i < N; i++) {
        cin >> time[i].first >> time[i].second;
    }

    sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.second < b.second) {
            return true;
        } else if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return false;
        }
    });

    for (int i = 0; i < N; i++) {
        if (start <= time[i].first) {
            start = time[i].second;
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}
