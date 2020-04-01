#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, count = 0, max_count = 0;
    long long n = 0, max_val = 0;
    vector<long long> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;

        v.push_back(n);
    }

    sort(v.begin(), v.end());

    n = v[0];
    count++;
    for (int i = 1; i < N; i++) {
        if (n == v[i]) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
                max_val = n;
            }
            n = v[i];
            count = 0;
        }
    }

    cout << max_val << "\n";

    return 0;
}
