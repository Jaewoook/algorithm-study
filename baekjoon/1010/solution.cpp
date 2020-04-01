#include <iostream>
using namespace std;

int main() {
    unsigned long long T = 0, N = 0, M = 0, k = 0, result = 1;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        result = 1;
        k = 1;
        for (int j = M; j > M - N; j--) {
            result *= j;
            if (k <= N) {
                result /= k;
            }
            k++;
        }
        cout << result << "\n";
    }
    return 0;
}
