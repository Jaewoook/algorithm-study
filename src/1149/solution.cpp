#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N = 0, arr[1000][3];

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 0;

    for (int i = 1; i < N; i++) {
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + arr[i][0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + arr[i][1];
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + arr[i][2];
    }

    cout << min(min(arr[N - 1][0], arr[N - 1][1]), arr[N - 1][2]) << "\n";

    return 0;
}
