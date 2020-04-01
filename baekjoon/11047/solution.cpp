#include <iostream>

using namespace std;

int main() {
    int N = 0, K = 0, count = 0, num = 0;
    cin >> N >> K;
    int *A = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = N - 1; i >= 0 && K > 0; i--) {
        if (K >= A[i]) {
            num = K / A[i];
            K -= num * A[i];
            count += num;
        }
    }

    cout << count << "\n";

    delete[] A;
    return 0;
}
