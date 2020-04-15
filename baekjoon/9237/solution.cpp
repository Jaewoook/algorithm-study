#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, days = 0;
    cin >> N;
    int *arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N, greater<int>());
    for (int i = 0; i < N; i++) {
        if (arr[i] + 1 + i > days) {
            days = arr[i] + 1 + i;
        }
    }

    cout << days + 1 << "\n";

    delete[] arr;
    return 0;
}
