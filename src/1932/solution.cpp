#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size = 0, arr[500][500], big = 0;
    cin >> size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                arr[i][j] += arr[i - 1][j];
            } else if (j == i) {
                arr[i][j] += arr[i - 1][j - 1];
            } else {
                arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[size - 1][i] > big) {
            big = arr[size - 1][i];
        }
    }

    cout << big << "\n";

    return 0;
}
