#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long min = 0, max = 0, count = 0;

    cin >> min >> max;
    bool *arr = new bool[max - min + 1];
    fill_n(arr, max - min + 1, false);

    for (long long i = 2; i * i <= max; i++) {
        long long j = min;
        if (min % (i * i) != 0) {
            j += i * i - min % (i * i);
        }
        for (; j <= max; j += i * i) {
            arr[j - min] = true;
        }
    }

    for (int i = 0; i < max - min + 1; i++) {
        if (!arr[i]) {
            count++;
        }
    }

    cout << count << "\n";

    delete[] arr;
    return 0;
}
