#include <iostream>
#include <algorithm>
using namespace std;

void search(int arr[], int len, int val) {
    int mid = len / 2;
    int result = arr[mid];

    if (len == 1) {
        cout << (result == val ? "1" : "0") << "\n";
        return;
    }

    if (result == val) {
        cout << "1\n";
    } else if (result > val) {
        search(arr, mid, val);
    } else {
        search(arr + mid, len - mid, val);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N = 0, M = 0, val = 0;

    cin >> N;
    int* num = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> val;
        search(num, N, val);
    }

    return 0;
}
