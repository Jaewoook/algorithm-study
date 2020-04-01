#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N = 0, a[51] = {0, }, b[51] = {0, }, max = 0, maxIndex = -1, result = 0;
    cin >> N;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0) {
                cin >> a[j];
            } else {
                cin >> b[j];
            }
        }
    }

    sort(a, a + N);

    for (int i = 0; i < N; i++) {
        max = 0;
        for (int j = 0; j < N; j++) {
            if (b[j] > max) {
                max = b[j];
                maxIndex = j;
            }
        }
        b[maxIndex] = -1;
        result += a[i] * max;
    }

    cout << result << "\n";

    return 0;
}
