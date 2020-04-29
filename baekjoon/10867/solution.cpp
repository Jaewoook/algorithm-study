#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, prev = -1001;
    cin >> N;
    int *arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        if (prev != arr[i]) {
            cout << arr[i] << " ";
            prev = arr[i];
        }
    }

    delete[] arr;
    return 0;
}
