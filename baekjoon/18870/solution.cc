#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> arr(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    set<int> unique_arr(arr.begin(), arr.end());
    vector<int> sorted_arr(unique_arr.begin(), unique_arr.end());
    sort(sorted_arr.begin(), sorted_arr.end());

    map<int, int> compact;
    for (int i = 0; i < sorted_arr.size(); i++) {
        compact[sorted_arr[i]] = i;
    }

    for (auto it = arr.begin(); it != arr.end(); it++) {
        auto v = compact.find(*it);
        cout << (*v).second << " ";
    }
    cout << "\n";

    return 0;
}
