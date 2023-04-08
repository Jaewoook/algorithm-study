#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T, N, M, idx_s, idx_e, result, diff;
    vector<unsigned int> nums;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        nums = vector<unsigned int>(N);
        idx_s = 0;
        idx_e = 1;

        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        result = nums[N - 1] - nums[0];

        while (idx_e < N) {
            diff = nums[idx_e] - nums[idx_s];

            if (diff < M) {
                ++idx_e;
            } else {
                if (diff < result) {
                    result = diff;
                }
                ++idx_s;
            }
        }

        cout << result << "\n";
    }
    return 0;
}

// sample input
// 2
// 6 5
// 8 6 1 4 2 3
// 7 4
// 89 36 33 53 63 83 52

// sample output
// 5
// 6
