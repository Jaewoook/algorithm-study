#include <iostream>
using namespace std;

void count_sort(int *arr, int N, int *sorted, int k) {
    int n[10] = {-1, };
    for (int i = 0; i != N; i++) {
        int single = (arr[i] / k) % 10;
        n[single]++;
    }
    for (int i = 1; i < 10; i++) {
        n[i] += n[i - 1];
    }

    for (auto i = N - 1; i >= 0; i--) {
        int single = (arr[i] / k) % 10;
        sorted[n[single]] = arr[i];
        n[single]--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, max_value = 0;
    cin >> N;
    int *arr = new int[N];
    int *sorted = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] += 1000000;
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    int k = 1;
    while (k < max_value) {
        count_sort(arr, N, sorted, k);
        delete[] arr;
        arr = sorted;
        sorted = new int[N];
        k *= 10;
    }
    for (int i = 0; i < N; i++) {
        cout << arr[i] - 1000000 << "\n";
    }

    delete[] arr;
    delete[] sorted;
    return 0;
}

// sample input
// 8
// 170 45 75 90 2 24 802 66
