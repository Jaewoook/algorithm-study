#include <iostream>
using namespace std;

bool isPrimeNum(int i) {
    int n = 2;
    while (i > n) {
        if (i % n == 0) {
            return false;
        }
        n++;
    }
    return i > 1;
}

int main() {
    int N = 0, count = 0;
    cin >> N;

    int *arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (isPrimeNum(arr[i])) {
            count++;
        }
    }

    cout << count << "\n";

    delete[] arr;
    return 0;
}
