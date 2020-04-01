#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, v = 0, count = 0, max_val = 0;
    bool escape = false;
    vector<int> a, a2;
    cin >> N;

    while (N--) {
        cin >> v;
        a.push_back(v);
        a2.push_back(v);
    }

    N = a.size();
    v = -1;
    sort(a.begin(), a.end());

    for (int i = N - 1; i >= 1; i--) {
        if (a[i] != a2[i]) {
            v = a2[i];
            count = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (v != a[j]) {
                    count++;
                } else {
                    max_val = max_val < count ? count : max_val;
                    if (j == 0) {
                        escape = true;
                    }
                    break;
                }
            }
            if (escape) {
                break;
            }
        }
    }

    cout << max_val + 1 << "\n";

    return 0;
}
