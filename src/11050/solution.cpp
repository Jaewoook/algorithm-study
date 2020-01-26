#include <iostream>
using namespace std;

int main() {
    int N = 0, K = 0, result = 1;
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        result *= N - i;
    }
    for (int i = 1; i <= K; i++) {
        result /= i;
    }

    cout << result << "\n";

    return 0;
}
