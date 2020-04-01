#include <iostream>

using namespace std;

int main() {
    int N = 0, arr[21] = {0, };
    arr[1] = 1;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[N] << "\n";

    return 0;
}
