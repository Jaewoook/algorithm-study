#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, n = 0;
    vector<int> lis;
    vector<int>::iterator bound;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        if (lis.empty()) {
            lis.push_back(n);
        } else {
            if (lis.back() > n) {
                bound = lower_bound(lis.begin(), lis.end(), n);
                if (*bound != n) {
                    *bound = n;
                }
            } else if (lis.back() != n) {
                lis.push_back(n);
            }
        }
    }

    cout << lis.size() << "\n";

    return 0;
}
