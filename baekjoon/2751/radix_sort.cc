#include <iostream>
#include <vector>
using namespace std;

vector<int> count_sort(vector<int> arr, int k) {
    int n[10] = {-1, };
    for (auto i = arr.begin(); i != arr.end(); i++) {
        int single = ((*i) / k) % 10;
        n[single]++;
    }
    for (int i = 1; i < 10; i++) {
        n[i] += n[i - 1];
    }

    vector<int> sorted(arr.size());
    for (auto i = arr.rbegin(); i != arr.rend(); i++) {
        int single = ((*i) / k) % 10;
        sorted[n[single]] = (*i);
        n[single]--;
    }

    return sorted;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, max_value = 0;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] += 1000000;
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    int k = 1;
    while (k < max_value) {
        arr = count_sort(arr, k);
        k *= 10;
    }
    for (int i = 0; i < N; i++) {
        cout << arr[i] - 1000000 << "\n";
    }

    return 0;
}

// sample input
// 8
// 170 45 75 90 2 24 802 66
