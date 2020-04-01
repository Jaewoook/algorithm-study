#include <iostream>

using namespace std;

int main() {
    long T = 0, N = 0, arr[101] = {0, };
    cin >> T;

    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 4; i <= 100; i++) {
        arr[i] = arr[i - 3] + arr[i - 2];
    }

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << arr[N] << "\n";
    }

    return 0;
}
