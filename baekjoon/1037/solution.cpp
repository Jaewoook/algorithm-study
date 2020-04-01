#include <iostream>
using namespace std;

int main() {
    int N = 0, n = 0, min = 1000000, max = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        if (min > n) {
            min = n;
        }
        if (max < n) {
            max = n;
        }
    }

    cout << min * max << "\n";

    return 0;
}
